#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int avg = round(image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen / 3.0);

            // Update pixel values

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;

        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    double half = width / 2;
    for (int i = 0; i < height; i++)
    {
        int temp_width = width - 1;
        for (int j = 0; j < half ; j++)
        {

             RGBTRIPLE temp = image[i][j];
             image[i][j] = image[i][temp_width];
             image[i][temp_width] = temp;
             temp_width--;

        }
    }
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sums_Red[9];
            int sums_Blue[9];
            int sums_Green[9];
            int count = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        sums_Red[count] = copy[k][l].rgbtRed;
                        sums_Blue[count] = copy[k][l].rgbtBlue;
                        sums_Green[count] = copy[k][l].rgbtGreen;
                        count++;
                    }
                }
            }

            int total_Red = 0, total_Blue = 0, total_Green = 0;
            for (int m = 0; m < count; m++)
            {
                total_Red += sums_Red[m];
                total_Blue += sums_Blue[m];
                total_Green += sums_Green[m];
            }

            int avg_Red = round((float) total_Red / count);
            int avg_Blue = round((float) total_Blue / count);
            int avg_Green = round((float) total_Green / count);

            image[i][j].rgbtRed = avg_Red;
            image[i][j].rgbtBlue = avg_Blue;
            image[i][j].rgbtGreen = avg_Green;
        }
    }
}
