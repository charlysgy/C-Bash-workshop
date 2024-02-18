void rot_x(char *s, int x)
{
    if (!s)
        return;

    for (unsigned i = 0; s[i] != '\0'; i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            s[i] -= 'a';
            s[i] = (s[i] + x) % 26;
            if (s[i] < 0)
                s[i] += 26;
            s[i] += 'a';
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            s[i] -= 'A';
            if (s[i] < 0)
                s[i] += 26;
            s[i] = (s[i] + x) % 26;
            s[i] += 'A';
        }
    }
}
