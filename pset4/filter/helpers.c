#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            
            // Find average
            float avg = (red + blue + green) / 3.0;
            
            // Reassign average to all RGB values
            image[i][j].rgbtRed = (int)round(avg);
            image[i][j].rgbtGreen = (int)round(avg);
            image[i][j].rgbtBlue = (int)round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get RGB values
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            
            // Generate new values
            // sepiaRed
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)  // check if new value > 255
            {
                sepiaRed = 255; // cap new value at 255
            }
            
            // sepiaGreen
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            
            //sepiaBlue
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaGreen = 255;
            }
            
            // Reassign new values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Create copy of image
    RGBTRIPLE tmp_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp_image[i][j] = image[i][j];
        }
    }
    
    // Loop through image and use temp image to reflect
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp_image[i][width - 1 - j];
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create copy of image
    RGBTRIPLE tmp_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp_image[i][j] = image[i][j];
        }
    }
    
    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float n = 0;
            int red = 0;
            int blue = 0;
            int green = 0;
            
            // Loop around pixel and get RGB values
            for (int ii = -1; ii < 2; ii++)
            {
                for (int jj = -1; jj < 2; jj++)
                {
                    // Check if pixel exists
                    if ((i + ii >= 0 && i + ii < height) && (j + jj >= 0 && j + jj < width))
                    {
                        // Get RGB values
                        red += tmp_image[i + ii][j + jj].rgbtRed;
                        green += tmp_image[i + ii][j + jj].rgbtGreen;
                        blue += tmp_image[i + ii][j + jj].rgbtBlue;
                        n++;
                    }
                }
                // Calculate new values
                int blurRed = (int)round(red / n);
                int blurGreen = (int)round(green / n);
                int blurBlue = (int)round(blue / n);
                
                // Reassign new values
                image[i][j].rgbtRed = blurRed;
                image[i][j].rgbtGreen = blurGreen;
                image[i][j].rgbtBlue = blurBlue;
            }
        }
    }
    
    return;
}
