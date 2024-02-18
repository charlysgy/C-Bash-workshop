unsigned char rol(unsigned char value, unsigned char roll)
{
    unsigned char mask = 1 << 7;
    for (; roll > 0; roll--)
    {
        unsigned char tmp = value & mask;
        tmp = tmp >> 7;
        value = value << 1;
        value = value | tmp;
    }

    return value;
}
