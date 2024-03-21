#include "helpers.h"

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
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = (BYTE)lrint(mean);
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
            image_blur[i][j].rgbtBlue = (BYTE)lrint((double)b / n);
            image_blur[i][j].rgbtGreen = (BYTE)lrint((double)g / n);
            image_blur[i][j].rgbtRed = (BYTE)lrint((double)r / n);
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
    int b, g, r;
    int x, y;

    RGBTRIPLE(*image_edge)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            b = g = r = 0;
            for (int k = 0; k < n ; k++)
            {
                x = k + i - 1;
                for (int l = 0; l < n; l++)
                {
                    y = l + j - 1;
                    if (0 <= x && x < height && 0 <= y && y < width)
                    {
                        b += image[k][l].rgbtBlue;
                        g += image[k][l].rgbtGreen;
                        r += image[k][l].rgbtRed;
                        n++;
                    }
                }
            }
            mean.rgbtBlue = (BYTE)lrint((double)mean.rgbtBlue / n);
            mean.rgbtGreen = (BYTE)lrint((double)mean.rgbtGreen / n);
            mean.rgbtRed = (BYTE)lrint((double)mean.rgbtRed / n);

            image_edge[i][j] = mean;
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
