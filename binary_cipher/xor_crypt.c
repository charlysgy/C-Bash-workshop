#include "binary_cipher.h"

void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    unsigned char *char_data = data;
    const unsigned char *key_char = key;
    for (size_t i = 0; i < data_len;)
    {
        for (size_t j = 0; j < key_len && i < data_len; j++, i++)
        {
            char_data[i] = char_data[i] ^ key_char[j];
        }
    }
}
