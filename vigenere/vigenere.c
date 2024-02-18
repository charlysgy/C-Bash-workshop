#include "vigenere.h"

unsigned str_len(const char *s)
{
    unsigned len = 0;
    for (; s[len] != '\0'; len++)
        continue;

    return len;
}

char to_upper(char c)
{
    if ('a' <= c && c <= 'z')
        return c - ('a' - 'A');

    return c;
}

void cipher(const char *key, const char *msg, char *res)
{
    unsigned keylen = str_len(key);

    unsigned i = 0;
    unsigned ik = 0;
    for (; msg[i] != '\0'; i++)
    {
        ik = ik % keylen;
        char msgc = to_upper(msg[i]);
        char keyc = to_upper(key[ik]);

        if (('A' <= msg[i] && msg[i] <= 'Z')
            || ('a' <= msg[i] && msg[i] <= 'z'))
        {
            res[i] = ((msgc - 'A' + keyc - 'A') % 26) + 'A';
            ik++;
        }

        else
            res[i] = msg[i];
    }

    res[i] = '\0';
}

void decipher(const char *key, const char *msg, char *res)
{
    unsigned keylen = str_len(key);

    unsigned i = 0;
    unsigned ik = 0;
    for (; msg[i] != '\0'; i++)
    {
        ik = ik % keylen;
        char msgc = to_upper(msg[i]);
        char keyc = to_upper(key[ik]);

        if (('A' <= msg[i] && msg[i] <= 'Z')
            || ('a' <= msg[i] && msg[i] <= 'z'))
        {
            int tmp = ((msgc - 'A' - keyc - 'A') % 26);
            if (tmp < 0)
                tmp += 26;
            res[i] = tmp + 'A';
            ik++;
        }

        else
            res[i] = msg[i];
    }

    res[i] = '\0';
}
