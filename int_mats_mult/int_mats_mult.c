#include <stddef.h>

void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    for (size_t row = 0; row < *matrices_size; row++)
    {
        for (size_t col = 0; col < *(matrices_size + 2); col++)
        {
            int sum = 0;
            for (size_t offset = 0; offset < *(matrices_size + 1); offset++)
            {
                sum += mat1[row][offset] * mat2[offset][col];
            }
            out[row][col] = sum;
        }
    }
}
