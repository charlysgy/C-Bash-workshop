#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "libstream.h"

#define MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH

static void set_flags(const char *mode, struct stream *stream)
{
    if (strcmp(mode, "r") == 0)
        stream->flags = O_RDONLY;
    else if (strcmp(mode, "r+") == 0)
        stream->flags = O_RDWR;
    else if (strcmp(mode, "w") == 0)
        stream->flags = O_WRONLY | O_CREAT | O_TRUNC;
    else if (strcmp(mode, "w+") == 0)
        stream->flags = O_RDWR | O_CREAT | O_TRUNC;
    else
        stream->flags = -1;
}

struct stream *lbs_fopen(const char *path, const char *mode)
{
    int flags = O_RDONLY;
    int fd;

    if (strcmp(mode, "r") == 0)
        flags = O_RDONLY;
    else if (strcmp(mode, "r+") == 0)
        flags = O_RDWR;
    else if (strcmp(mode, "w") == 0)
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    else if (strcmp(mode, "w+") == 0)
        flags = O_RDWR | O_CREAT | O_TRUNC;
    else
        flags = -1;

    fd = open(path, flags, 0666);

    if (fd < 0)
        return NULL;
    return lbs_fdopen(fd, mode);
}

struct stream *lbs_fdopen(int fd, const char *mode)
{
    if (fd < 0)
        return NULL;

    struct stream *stream = calloc(1, sizeof(struct stream));

    if (stream == NULL)
        return NULL;

    set_flags(mode, stream);

    stream->error = 0;
    stream->fd = fd;
    stream->io_operation = STREAM_READING;
    stream->buffering_mode =
        isatty(stream->fd) ? STREAM_LINE_BUFFERED : STREAM_BUFFERED;
    stream->buffered_size = 0;
    stream->already_read = 0;

    memset(stream->buffer, 0, LBS_BUFFER_SIZE);

    return stream;
}

int lbs_fclose(struct stream *stream)
{
    if (!stream)
        return EOF;

    if (stream->buffered_size > 0)
    {
        if (stream->io_operation == STREAM_WRITING)
        {
            if (write(stream->fd, stream->buffer, stream->buffered_size) < 0)
            {
                stream->error = 1;
                return EOF;
            }
        }
    }

    if (close(stream->fd) < 0)
    {
        stream->error = 1;
        return EOF;
    }

    free(stream);

    return 0;
}

int lbs_fputc(int c, struct stream *stream)
{
    unsigned char ch = c;
    if (!stream || !stream_writable(stream))
        return EOF;

    if (stream->io_operation == STREAM_READING)
    {
        if (lbs_fflush(stream) < 0)
        {
            stream->error = 1;
            return EOF;
        }
        stream->io_operation = STREAM_WRITING;
    }

    stream->io_operation = STREAM_WRITING;
    stream->buffer[stream->buffered_size] = ch;
    stream->buffered_size++;

    if (stream->buffering_mode == STREAM_UNBUFFERED
        || stream->buffered_size == LBS_BUFFER_SIZE)
    {
        if (lbs_fflush(stream) < 0)
        {
            stream->error = 1;
            return EOF;
        }
        return c;
    }

    if (stream->buffered_size == LBS_BUFFER_SIZE)
    {
        if (lbs_fflush(stream) < 0)
        {
            stream->error = 1;
            return EOF;
        }
    }
    else if (stream->buffering_mode == STREAM_LINE_BUFFERED && c == '\n')
    {
        if (lbs_fflush(stream) < 0)
        {
            stream->error = 1;
            return EOF;
        }
    }

    return c;
}

int lbs_fgetc(struct stream *stream)
{
    if (!stream || !stream_readable(stream))
    {
        return LBS_EOF;
    }

    if (stream->io_operation == STREAM_WRITING)
    {
        if (lbs_fflush(stream) < 0)
        {
            stream->error = 1;
            return LBS_EOF;
        }
        stream->io_operation = STREAM_READING;
    }

    if (stream->buffered_size == 0)
    {
        int read_octet;

        if ((read_octet = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE))
            < 0)
        {
            stream->error = 1;
            return LBS_EOF;
        }
        else if (read_octet == 0)
        {
            return LBS_EOF;
        }
        else
        {
            size_t r = read_octet;
            stream->buffered_size = r;
            stream->already_read = 0;
        }
    }

    unsigned char c = stream->buffer[stream->already_read];
    stream->already_read++;
    if (stream->already_read == stream->buffered_size)
    {
        stream->buffered_size = 0;
        stream->already_read = 0;
    }

    int res = c;

    return res;
}

int lbs_fflush(struct stream *stream)
{
    if (!stream)
        return EOF;

    if (stream->io_operation == STREAM_READING && stream->already_read > 0)
    {
        off_t new_offset = -stream_remaining_buffered(stream);
        long new_position = lseek(stream->fd, new_offset, SEEK_CUR);
        if (new_position == -1)
        {
            stream->error = 1;
            return EOF;
        }
    }
    else if (stream->io_operation == STREAM_WRITING
             && stream->buffered_size > 0)
    {
        ssize_t bytesWritten =
            write(stream->fd, stream->buffer, stream->buffered_size);

        if (bytesWritten < 0)
        {
            stream->error = 1;
            return EOF;
        }
    }

    memset(stream->buffer, 0, LBS_BUFFER_SIZE);
    stream->buffered_size = 0;
    stream->already_read = 0;

    return 0;
}
