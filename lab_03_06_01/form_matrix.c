#include "form_matrix.h"
#include"common_dependencies.h"

void form_matrix(int return_code, int matrix[][MAX_ARR_SIZE], int size)
{
    if (return_code == OK)
    {
        int top = 0, bottom = size - 1, left = 0, right = size - 1;
        int steps = 1;
        while (steps <= size * size) 
        {
            for (int j = left; j <= right; j++)
                matrix[top][j] = steps++;
            top += 1;
            for (int i = top; i <= bottom; i++)
                matrix[i][right] = steps++;
            right -= 1;
            for (int j = right; j >= left; j--)
                matrix[bottom][j] = steps++;
            bottom -= 1;
            for (int i = bottom; i >= top; i--)
                matrix[i][left] = steps++;
            left += 1;
        }
    }
}