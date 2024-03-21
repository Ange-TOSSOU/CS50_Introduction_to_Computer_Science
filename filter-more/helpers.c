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
    RGBTRIPLE mean;
    int height_c, width_c;
    int n;
    for (int i = 0; i < height; i++)
    {
        height_c = i + 1;
        for (int j = 0; j < width; j++)
        {
            n = 0;
            mean.rgbtBlue = mean.rgbtGreen = mean.rgbtRed = 0;
            width_c = j + 1;
            for (int k = i - 1; k <= height_c ; k++)
            {
                for (int l = j - 1; l <= width_c; l++)
                {
                    if (0 <= k && k < height && 0 <= l && l < width)
                    {
                        mean.rgbtBlue += image[k][l].rgbtBlue;
                        mean.rgbtGreen += image[k][l].rgbtGreen;
                        mean.rgbtRed += image[k][l].rgbtRed;
                        n++;
                    }
                }
            }
            mean.rgbtBlue = (BYTE)lrint((double)mean.rgbtBlue / n);
            mean.rgbtGreen = (BYTE)lrint((double)mean.rgbtGreen / n);
            mean.rgbtRed = (BYTE)lrint((double)mean.rgbtRed / n);

            image_blur[i][j] = mean;
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

/*void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE mean;
    int height_c, width_c;
    int n;
    for (int i = 0; i < height; i++)
    {
        height_c = i + 1;
        for (int j = 0; j < width; j++)
        {
            n = 0;
            mean.rgbtBlue = mean.rgbtGreen = mean.rgbtRed = 0;
            width_c = j + 1;
            for (int k = i - 1; k <= height_c ; k++)
            {
                for (int l = j - 1; l <= width_c; l++)
                {
                    if (0 <= k && k < height && 0 <= l && l < width)
                    {
                        mean.rgbtBlue += image[k][l].rgbtBlue;
                        mean.rgbtGreen += image[k][l].rgbtGreen;
                        mean.rgbtRed += image[k][l].rgbtRed;
                        n++;
                    }
                }
            }
            mean.rgbtBlue = (BYTE)lrint((double)mean.rgbtBlue / n);
            mean.rgbtGreen = (BYTE)lrint((double)mean.rgbtGreen / n);
            mean.rgbtRed = (BYTE)lrint((double)mean.rgbtRed / n);

            image[i][j] = mean;
        }
    }
}*/

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE mean;
    const int n = 3;
    int kernel_x[n][n] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int kernel_y[n][n] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mean.rgbtBlue = mean.rgbtGreen = mean.rgbtRed = 0;
            for (int k = 0; k < n ; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (0 <= k && k < height && 0 <= l && l < width)
                    {
                        mean.rgbtBlue += image[k][l].rgbtBlue;
                        mean.rgbtGreen += image[k][l].rgbtGreen;
                        mean.rgbtRed += image[k][l].rgbtRed;
                        n++;
                    }
                }
            }
            mean.rgbtBlue = (BYTE)lrint((double)mean.rgbtBlue / n);
            mean.rgbtGreen = (BYTE)lrint((double)mean.rgbtGreen / n);
            mean.rgbtRed = (BYTE)lrint((double)mean.rgbtRed / n);

            image[i][j] = mean;
        }
    }
}
