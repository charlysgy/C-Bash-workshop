#include "lakes.h"

void fill_lake(char **map, int x, int y)
{
    map[x][y] = '#';

    if (map[x - 1][y] == '.')
        fill_lake(map, x - 1, y);

    if (map[x + 1][y] == '.')
        fill_lake(map, x + 1, y);

    if (map[x][y - 1] == '.')
        fill_lake(map, x, y - 1);

    if (map[x][y + 1] == '.')
        fill_lake(map, x, y + 1);
}

int lakes(char **map, int width, int height)
{
    int counter = 0;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            if (map[x][y] == '.')
            {
                counter++;
                fill_lake(map, x, y);
            }
        }
    }

    return counter;
}
