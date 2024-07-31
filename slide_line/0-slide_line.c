#include "slide_line.h"

/**
 * slide_left - Slides and merges the array to the left
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
void slide_left(int *line, size_t size)
{
    size_t i, j;

    for (i = 0; i < size; i++)
    {
        if (line[i] == 0)
        {
            for (j = i + 1; j < size; j++)
            {
                if (line[j] != 0)
                {
                    line[i] = line[j];
                    line[j] = 0;
                    break;
                }
            }
        }

        if (i < size - 1 && line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }

    for (i = 0; i < size; i++)
    {
        if (line[i] == 0)
        {
            for (j = i + 1; j < size; j++)
            {
                if (line[j] != 0)
                {
                    line[i] = line[j];
                    line[j] = 0;
                    break;
                }
            }
        }
    }
}

/**
 * slide_right - Slides and merges the array to the right
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
void slide_right(int *line, size_t size)
{
    size_t i, j;

    for (i = size; i > 0; i--)
    {
        if (line[i - 1] == 0)
        {
            for (j = i - 1; j > 0; j--)
            {
                if (line[j - 1] != 0)
                {
                    line[i - 1] = line[j - 1];
                    line[j - 1] = 0;
                    break;
                }
            }
        }

        if (i > 1 && line[i - 1] == line[i - 2])
        {
            line[i - 1] *= 2;
            line[i - 2] = 0;
        }
    }

    for (i = size; i > 0; i--)
    {
        if (line[i - 1] == 0)
        {
            for (j = i - 1; j > 0; j--)
            {
                if (line[j - 1] != 0)
                {
                    line[i - 1] = line[j - 1];
                    line[j - 1] = 0;
                    break;
                }
            }
        }
    }
}

/**
 * slide_line - Slides and merges an array of integers to the left or right
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide and merge the array
 * 
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else if (direction == SLIDE_RIGHT)
        slide_right(line, size);
    else
        return 0;

    return 1;
}
