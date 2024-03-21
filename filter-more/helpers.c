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
/*void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    int lim = width / 2;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < lim; i++)
        {
            tmp = image[i][j];
            image[i][j] = image[width - 1 - i][j];
            image[width - 1 - i][j] = tmp;
        }
    }
}*/
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0, k = width - 1; i < k; i++, k--)
        {
            tmp = image[i][j];
            image[i][j] = image[k][j];
            image[k][j].rgbtBlue = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
