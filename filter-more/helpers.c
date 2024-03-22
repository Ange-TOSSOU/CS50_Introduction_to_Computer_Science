#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double mean;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mean = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            mean /= 3;
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = (BYTE)round(mean);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    int lim = width / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < lim; j++)
        {
            tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*image_blur)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    int b, g, r;
    int height_c, width_c;
    int n;
    for (int i = 0; i < height; i++)
    {
        height_c = i + 1;
        for (int j = 0; j < width; j++)
        {
            n = 0;
            b = g = r = 0;
            width_c = j + 1;
            for (int k = i - 1; k <= height_c ; k++)
            {
                for (int l = j - 1; l <= width_c; l++)
                {
                    if (0 <= k && k < height && 0 <= l && l < width)
                    {
                        b += image[k][l].rgbtBlue;
                        g += image[k][l].rgbtGreen;
                        r += image[k][l].rgbtRed;
                        n++;
                    }
                }
            }
            image_blur[i][j].rgbtBlue = (BYTE)round((double)b / n);
            image_blur[i][j].rgbtGreen = (BYTE)round((double)g / n);
            image_blur[i][j].rgbtRed = (BYTE)round((double)r / n);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_blur[i][j];
        }
    }

    free(image_blur);
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    const int n = 3;
    int kernel_x[n][n] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int kernel_y[n][n] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int bx, gx, rx;
    int by, gy, ry;
    int x, y;

    RGBTRIPLE(*image_edge)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            bx = gx = rx = 0;
            by = gy = ry = 0;
            for (int k = 0; k < n ; k++)
            {
                x = k + i - 1;
                for (int l = 0; l < n; l++)
                {
                    y = l + j - 1;
                    if (0 <= x && x < height && 0 <= y && y < width)
                    {
                        bx += kernel_x[k][l] * image[x][y].rgbtBlue;
                        gx += kernel_x[k][l] * image[x][y].rgbtGreen;
                        rx += kernel_x[k][l] * image[x][y].rgbtRed;
                        by += kernel_y[k][l] * image[x][y].rgbtBlue;
                        gy += kernel_y[k][l] * image[x][y].rgbtGreen;
                        ry += kernel_y[k][l] * image[x][y].rgbtRed;
                    }
                }
            }

            image_edge[i][j].rgbtBlue = (BYTE)lrint(sqrt(pow(bx, 2) + pow(by, 2)));
            image_edge[i][j].rgbtGreen = (BYTE)lrint(sqrt(pow(gx, 2) + pow(gy, 2)));
            image_edge[i][j].rgbtRed = (BYTE)lrint(sqrt(pow(rx, 2) + pow(ry, 2)));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_edge[i][j];
        }
    }
}
