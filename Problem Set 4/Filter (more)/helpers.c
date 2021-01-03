#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE avArray[height][width];

    float average = 0;
    float avRed = 0;
    float avBlue = 0;
    float avGreen = 0;

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            avRed = image[i][k].rgbtRed;
            avBlue = image[i][k].rgbtBlue;
            avGreen = image[i][k].rgbtGreen;

            average = round(((avRed + avBlue + avGreen) / 3));

            avArray[i][k].rgbtRed = average;
            avArray[i][k].rgbtBlue = average;
            avArray[i][k].rgbtGreen = average;

            image[i][k].rgbtRed = avArray[i][k].rgbtRed;
            image[i][k].rgbtBlue = avArray[i][k].rgbtBlue;
            image[i][k].rgbtGreen = avArray[i][k].rgbtGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int sub[3];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            sub[0] = image[i][j].rgbtRed;
            sub[1] = image[i][j].rgbtBlue;
            sub[2] = image[i][j].rgbtGreen;

            image[i][j].rgbtRed = image[i][(width - 1) - j].rgbtRed;
            image[i][j].rgbtBlue = image[i][(width - 1) - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][(width - 1) - j].rgbtGreen;

            image[i][(width - 1) - j].rgbtRed = sub[0];
            image[i][(width - 1) - j].rgbtBlue = sub[1];
            image[i][(width - 1) - j].rgbtGreen = sub[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE avArray[height][width];

    int count = 0;
    float avRed = 0;
    float avBlue = 0;
    float avGreen = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            // -------------------------------------------------
            //defining for 3 by 3 grid pixel possibility

            if ((j >= 1 && j <= width - 2) && (i >= 1 && i <= height - 2))
            {
                for (int x = (i - 1); x <= (i + 1); x++)
                {
                    for (int y = (j - 1); y <= (j + 1); y++)
                    {
                        avRed += image[x][y].rgbtRed;
                        avBlue += image[x][y].rgbtBlue;
                        avGreen += image[x][y].rgbtGreen;
                        count++;
                    }
                }
            }

            else if (j == 0 && i == 0) //defining for corner pixel should run 4 times
           {
                for (int x = i; x <= i + 1; x++)
                {
                    for (int y = j; y <= j + 1; y++)
                    {
                        avRed += image[x][y].rgbtRed;
                        avBlue += image[x][y].rgbtBlue;
                        avGreen += image[x][y].rgbtGreen;
                        count ++;
                    }
                }
            }

            //top right most pixel
            else if ((j == width - 1) && i == 0)
            {
                for (int x = i; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j; y++)
                    {
                        avRed += image[x][y].rgbtRed;
                        avBlue += image[x][y].rgbtBlue;
                        avGreen += image[x][y].rgbtGreen;
                        count ++;
                    }
                }
            }

            //bottom left most pixel
            else if (j == 0 && (i == height - 1))
            {
                for (int x = i - 1; x <= i; x++)
                {
                    for (int y = j; y <= j + 1; y++)
                    {
                        avRed += image[x][y].rgbtRed;
                        avBlue += image[x][y].rgbtBlue;
                        avGreen += image[x][y].rgbtGreen;
                        count ++;
                    }
                }
            }

            //bottom right most pixel
            else if ((j == width - 1) && (i == height - 1))
            {
                for (int x = i - 1; x <= i; x++)
                {
                    for (int y = j - 1; y <= j; y++)
                    {
                        avRed += image[x][y].rgbtRed;
                        avBlue += image[x][y].rgbtBlue;
                        avGreen += image[x][y].rgbtGreen;
                        count ++;
                    }
                }
            }

            //defining for side pixel possibility
            //vertical edge pixel on the left
            else if ((j == 0) && (i != 0) && (i != height - 1))
            {
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j; y <= j + 1; y++)
                    {
                        avRed += image[x][y].rgbtRed;
                        avBlue += image[x][y].rgbtBlue;
                        avGreen += image[x][y].rgbtGreen;
                        count ++;
                    }
                }
            }

            //vertical edge pixel on the right
            else if ((j == width - 1) && (i != 0) && (i != height - 1))
            {
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j; y++)
                    {
                        avRed += image[x][y].rgbtRed;
                        avBlue += image[x][y].rgbtBlue;
                        avGreen += image[x][y].rgbtGreen;
                        count ++;
                    }
                }
            }

            //horizontal edge pixel on the top
            else if ((i == 0) && (j != 0) && (j != width - 1))
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    for (int x = i; x <= i + 1; x++)
                    {
                        avRed += image[x][y].rgbtRed;
                        avBlue += image[x][y].rgbtBlue;
                        avGreen += image[x][y].rgbtGreen;
                        count ++;
                    }
                }
            }

            //horizontal edge pixel on the bottom
            else if ((i == height - 1) && (j != 0) && (j != width - 1))
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    for (int x = i - 1; x <= i; x++)
                    {
                        avRed += image[x][y].rgbtRed;
                        avBlue += image[x][y].rgbtBlue;
                        avGreen += image[x][y].rgbtGreen;
                        count ++;
                    }
                }

            }

        //final calculation and setting the final value of the pixel
        avRed = round(avRed/count);
        avBlue = round(avBlue/count);
        avGreen = round(avGreen/count);

        avArray[i][j].rgbtRed = avRed;
        avArray[i][j].rgbtBlue = avBlue;
        avArray[i][j].rgbtGreen = avGreen;

        // Reset all
        count = 0;
        avRed = 0;
        avBlue = 0;
        avGreen = 0;

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        image[i][j].rgbtRed = avArray[i][j].rgbtRed;
        image[i][j].rgbtBlue = avArray[i][j].rgbtBlue;
        image[i][j].rgbtGreen = avArray[i][j].rgbtGreen;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE avArray[height][width];

    int count = 0;
    int avRed = 0;
    int avBlue = 0;
    int avGreen = 0;
    float avRedX = 0;
    float avBlueX = 0;
    float avGreenX = 0;
    float avRedY = 0;
    float avBlueY = 0;
    float avGreenY = 0;
    int Red = 0;
    int Blue = 0;
    int Green = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            // -------------------------------------------------
            //defining for 3 by 3 grid pixel possibility

            if ((j >= 1 && j <= width - 2) && (i >= 1 && i <= height - 2))
            {
                for (int x = (i - 1); x <= (i + 1); x++)
                {
                    for (int y = (j - 1); y <= (j + 1); y++)
                    {
                        //Defining the arrays of GX and GY for 3x3
                        int GXArray[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
                        int GYArray[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
                        
                        //GX 
                        //Red
                        Red = image[x][y].rgbtRed;
                        avRedX += (GXArray[count] * Red);
                        
                        //Blue
                        Blue = image[x][y].rgbtBlue;
                        avBlueX += (GXArray[count] * Blue);                        
                        
                        //Green
                        Green = image[x][y].rgbtGreen;
                        avGreenX += (GXArray[count] * Green);
                        
                        //GY
                        //Red
                        avRedY += (GYArray[count] * Red);
                        
                        //Blue
                        avBlueY += (GYArray[count] * Blue);                        
                        
                        //Green
                        avGreenY += (GYArray[count] * Green); 
                        
                        count++;
                    }
                }
            }

            //top left most pixel
            else if (j == 0 && i == 0) //defining for corner pixel -- should run 4 times
           {
                for (int x = i; x <= i + 1; x++)
                {
                    for (int y = j; y <= j + 1; y++)
                    {
                        //Defining the arrays of GX and GY for 3x3
                        int GXArray[4] = {0, 2, 0, 1};
                        int GYArray[4] = {0, 0, 2, 1};
                        
                        //GX 
                        //Red
                        Red = image[x][y].rgbtRed;
                        avRedX += (GXArray[count] * Red);
                        
                        //Blue
                        Blue = image[x][y].rgbtBlue;
                        avBlueX += (GXArray[count] * Blue);                        
                        
                        //Green
                        Green = image[x][y].rgbtGreen;
                        avGreenX += (GXArray[count] * Green);
                        
                        //GY
                        //Red
                        avRedY += (GYArray[count] * Red);
                        
                        //Blue
                        avBlueY += (GYArray[count] * Blue);                        
                        
                        //Green
                        avGreenY += (GYArray[count] * Green); 
                        
                        count++;
                    }
                }
            }

            //top right most pixel
            else if ((j == width - 1) && i == 0)
            {
                for (int x = i; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j; y++)
                    {
                        //Defining the arrays of GX and GY for 3x3
                        int GXArray[4] = {-2, 0, -1, 0};
                        int GYArray[4] = {0, 0, 1, 2};
                        
                        //GX 
                        //Red
                        Red = image[x][y].rgbtRed;
                        avRedX += (GXArray[count] * Red);
                        
                        //Blue
                        Blue = image[x][y].rgbtBlue;
                        avBlueX += (GXArray[count] * Blue);                        
                        
                        //Green
                        Green = image[x][y].rgbtGreen;
                        avGreenX += (GXArray[count] * Green);
                        
                        //GY
                        //Red
                        avRedY += (GYArray[count] * Red);
                        
                        //Blue
                        avBlueY += (GYArray[count] * Blue);                        
                        
                        //Green
                        avGreenY += (GYArray[count] * Green); 
                        
                        count++;
                    }
                }
            }

            //bottom left most pixel
            else if (j == 0 && (i == height - 1))
            {
                for (int x = i - 1; x <= i; x++)
                {
                    for (int y = j; y <= j + 1; y++)
                    {
                        //Defining the arrays of GX and GY for 3x3
                        int GXArray[4] = {0, 1, 0, 2};
                        int GYArray[4] = {-2, -1, 0, 0};
                        
                        //GX 
                        //Red
                        Red = image[x][y].rgbtRed;
                        avRedX += (GXArray[count] * Red);
                        
                        //Blue
                        Blue = image[x][y].rgbtBlue;
                        avBlueX += (GXArray[count] * Blue);                        
                        
                        //Green
                        Green = image[x][y].rgbtGreen;
                        avGreenX += (GXArray[count] * Green);
                        
                        //GY
                        //Red
                        avRedY += (GYArray[count] * Red);
                        
                        //Blue
                        avBlueY += (GYArray[count] * Blue);                        
                        
                        //Green
                        avGreenY += (GYArray[count] * Green); 
                        
                        count++;
                    }
                }
            }

            //bottom right most pixel
            else if ((j == width - 1) && (i == height - 1))
            {
                for (int x = i - 1; x <= i; x++)
                {
                    for (int y = j - 1; y <= j; y++)
                    {
                        //Defining the arrays of GX and GY for 3x3
                        int GXArray[4] = {-1, 0, -2, 0};
                        int GYArray[4] = {-1, -2, 0, 0};
                        
                        //GX 
                        //Red
                        Red = image[x][y].rgbtRed;
                        avRedX += (GXArray[count] * Red);
                        
                        //Blue
                        Blue = image[x][y].rgbtBlue;
                        avBlueX += (GXArray[count] * Blue);                        
                        
                        //Green
                        Green = image[x][y].rgbtGreen;
                        avGreenX += (GXArray[count] * Green);
                        
                        //GY
                        //Red
                        avRedY += (GYArray[count] * Red);
                        
                        //Blue
                        avBlueY += (GYArray[count] * Blue);                        
                        
                        //Green
                        avGreenY += (GYArray[count] * Green); 
                        
                        count++;
                    }
                }
            }

            //defining for side pixel possibility
            //vertical edge pixel on the left
            else if ((j == 0) && (i != 0) && (i != height - 1))
            {
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j; y <= j + 1; y++)
                    {
                        //Defining the arrays of GX and GY for 3x3
                        int GXArray[6] = {0, 1, 0, 2, 0, 1};
                        int GYArray[6] = {-2, -1, 0, 0, 2, 1};
                        
                        //GX 
                        //Red
                        Red = image[x][y].rgbtRed;
                        avRedX += (GXArray[count] * Red);
                        
                        //Blue
                        Blue = image[x][y].rgbtBlue;
                        avBlueX += (GXArray[count] * Blue);                        
                        
                        //Green
                        Green = image[x][y].rgbtGreen;
                        avGreenX += (GXArray[count] * Green);
                        
                        //GY
                        //Red
                        avRedY += (GYArray[count] * Red);
                        
                        //Blue
                        avBlueY += (GYArray[count] * Blue);                        
                        
                        //Green
                        avGreenY += (GYArray[count] * Green); 
                        
                        count++;
                    }
                }
            }

            //vertical edge pixel on the right
            else if ((j == width - 1) && (i != 0) && (i != height - 1))
            {
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j; y++)
                    {
                        //Defining the arrays of GX and GY for 3x3
                        int GXArray[6] = {-1, 0, -2, 0, -1, 0};
                        int GYArray[6] = {-1, -2, 0, 0, 1, 2};
                        
                        //GX 
                        //Red
                        Red = image[x][y].rgbtRed;
                        avRedX += (GXArray[count] * Red);
                        
                        //Blue
                        Blue = image[x][y].rgbtBlue;
                        avBlueX += (GXArray[count] * Blue);                        
                        
                        //Green
                        Green = image[x][y].rgbtGreen;
                        avGreenX += (GXArray[count] * Green);
                        
                        //GY
                        //Red
                        avRedY += (GYArray[count] * Red);
                        
                        //Blue
                        avBlueY += (GYArray[count] * Blue);                        
                        
                        //Green
                        avGreenY += (GYArray[count] * Green); 
                        
                        count++;
                    }
                }
            }

            //horizontal edge pixel on the top
            else if ((i == 0) && (j != 0) && (j != width - 1))
            {
                for (int x = i; x <= i + 1; x++) 
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        //Defining the arrays of GX and GY for 3x3
                        int GXArray[6] = {-2, 0, 2, -1, 0, 1};
                        int GYArray[6] = {0, 0, 0, 1, 2, 1};
                        
                        //GX 
                        //Red
                        Red = image[x][y].rgbtRed;
                        avRedX += (GXArray[count] * Red);
                        
                        //Blue
                        Blue = image[x][y].rgbtBlue;
                        avBlueX += (GXArray[count] * Blue);                        
                        
                        //Green
                        Green = image[x][y].rgbtGreen;
                        avGreenX += (GXArray[count] * Green);
                        
                        //GY
                        //Red
                        avRedY += (GYArray[count] * Red);
                        
                        //Blue
                        avBlueY += (GYArray[count] * Blue);                        
                        
                        //Green
                        avGreenY += (GYArray[count] * Green); 
                        
                        count++;
                    }
                }
            }

            //horizontal edge pixel on the bottom
            else if ((i == height - 1) && (j != 0) && (j != width - 1))
            {
                for (int x = i - 1; x <= i; x++) 
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        //Defining the arrays of GX and GY for 3x3
                        int GXArray[6] = {-1, 0, 1, -2, 0, 2};
                        int GYArray[6] = {-1, -2, -1, 0, 0, 0};
                        
                        //GX 
                        //Red
                        Red = image[x][y].rgbtRed;
                        avRedX += (GXArray[count] * Red);
                        
                        //Blue
                        Blue = image[x][y].rgbtBlue;
                        avBlueX += (GXArray[count] * Blue);                        
                        
                        //Green
                        Green = image[x][y].rgbtGreen;
                        avGreenX += (GXArray[count] * Green);
                        
                        //GY
                        //Red
                        avRedY += (GYArray[count] * Red);
                        
                        //Blue
                        avBlueY += (GYArray[count] * Blue);                        
                        
                        //Green
                        avGreenY += (GYArray[count] * Green); 
                        
                        count++;
                    }
                }

            }

        //final calculation and setting the final value of the pixel
        avRed = round(sqrt((avRedX * avRedX) + (avRedY * avRedY)));
        avBlue = round(sqrt((avBlueX * avBlueX) + (avBlueY * avBlueY)));
        avGreen = round(sqrt((avGreenX * avGreenX) + (avGreenY * avGreenY)));

        //Exception handler -- caps the value to max 255
        if (avRed > 255)
        {
            avRed = 255;
        }
        
        if (avBlue > 255)
        {
            avBlue = 255;
        }
        
        if (avGreen > 255)
        {
            avGreen = 255;
        }
        
        //Using the final av Values in the array
        avArray[i][j].rgbtRed = avRed;
        avArray[i][j].rgbtBlue = avBlue;
        avArray[i][j].rgbtGreen = avGreen;

        // Reset all variables
        count = 0;
        Red = 0;
        Blue = 0;
        Green = 0;
        avRed = 0;
        avBlue = 0;
        avGreen = 0;
        avRedX = 0;
        avBlueX = 0;
        avGreenX = 0;
        avRedY = 0;
        avBlueY = 0;
        avGreenY = 0;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        image[i][j].rgbtRed = avArray[i][j].rgbtRed;
        image[i][j].rgbtBlue = avArray[i][j].rgbtBlue;
        image[i][j].rgbtGreen = avArray[i][j].rgbtGreen;
        }
    }
    return;
}
