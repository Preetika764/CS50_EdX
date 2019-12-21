#include "helpers.h"
#include <math.h>


int
rounds(double x)
{
  if (round(x) >= 255)
return 255;
  else
    return round (x);
}


// Convert image to grayscale
void
grayscale (int height, int width, RGBTRIPLE image[height][width])
{
  for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
	{
	  BYTE x =
	    (BYTE) (round) ((image[i][j].rgbtBlue + image[i][j].rgbtRed +
			     image[i][j].rgbtGreen) / 3.0);
	  image[i][j].rgbtBlue = x;
	  image[i][j].rgbtRed = x;
	  image[i][j].rgbtGreen = x;
	}
    }
  return;
}

// Reflect image horizontally
void
reflect (int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE temp[width];
  for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
	{
	  temp[width - 1 - j] = image[i][j];
	}
      for (int j = 0; j < width; j++)
	{
	  image[i][j] = temp[j];
	}
    }
  return;
}

// Blur image
void
blur (int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE temp[height][width];
  for (int i = 1; i < height - 1; i++)
    {
      for (int j = 1; j < width - 1; j++)
	{
	  temp[i][j].rgbtRed =
	    (round) ((image[i - 1][j].rgbtRed + image[i][j].rgbtRed +
		      image[i + 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed +
		      image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
		      image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed +
		      image[i + 1][j + 1].rgbtRed) / 9.0);

	  temp[i][j].rgbtGreen =
	    (round) ((image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen +
		      image[i + 1][j].rgbtGreen + image[i - 1][j -
							       1].rgbtGreen +
		      image[i][j - 1].rgbtGreen + image[i + 1][j -
							       1].rgbtGreen +
		      image[i - 1][j + 1].rgbtGreen + image[i][j +
							       1].rgbtGreen +
		      image[i + 1][j + 1].rgbtGreen) / 9.0);

	  temp[i][j].rgbtBlue =
	    (round) ((image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue +
		      image[i + 1][j].rgbtBlue + image[i - 1][j -
							      1].rgbtBlue +
		      image[i][j - 1].rgbtBlue + image[i + 1][j -
							      1].rgbtBlue +
		      image[i - 1][j + 1].rgbtBlue + image[i][j +
							      1].rgbtBlue +
		      image[i + 1][j + 1].rgbtBlue) / 9.0);
	}

    }

  for (int j = 1; j < width - 1; j++)
    {
      temp[0][j].rgbtRed =
	(round) ((image[0][j - 1].rgbtRed + image[0][j].rgbtRed +
		  image[0][j + 1].rgbtRed + image[1][j - 1].rgbtRed +
		  image[1][j].rgbtRed + image[1][j + 1].rgbtRed) / 6.0);
      temp[height - 1][j].rgbtRed =
	(round) ((image[height - 1][j - 1].rgbtRed +
		  image[height - 1][j].rgbtRed + image[height - 1][j +
								   1].
		  rgbtRed + image[height - 2][j - 1].rgbtRed + image[height -
								     2][j].
		  rgbtRed + image[height - 2][j + 1].rgbtRed) / 6.0);
      temp[0][j].rgbtBlue =
	(round) ((image[0][j - 1].rgbtBlue + image[0][j].rgbtBlue +
		  image[0][j + 1].rgbtBlue + image[1][j - 1].rgbtBlue +
		  image[1][j].rgbtBlue + image[1][j + 1].rgbtBlue) / 6.0);
      temp[height - 1][j].rgbtBlue =
	(round) ((image[height - 1][j - 1].rgbtBlue +
		  image[height - 1][j].rgbtBlue + image[height - 1][j +
								    1].
		  rgbtBlue + image[height - 2][j - 1].rgbtBlue +
		  image[height - 2][j].rgbtBlue + image[height - 2][j +
								    1].
		  rgbtBlue) / 6.0);
      temp[0][j].rgbtGreen =
	(round) ((image[0][j - 1].rgbtGreen + image[0][j].rgbtGreen +
		  image[0][j + 1].rgbtGreen + image[1][j - 1].rgbtGreen +
		  image[1][j].rgbtGreen + image[1][j + 1].rgbtGreen) / 6.0);
      temp[height - 1][j].rgbtGreen =
	(round) ((image[height - 1][j - 1].rgbtGreen +
		  image[height - 1][j].rgbtGreen + image[height - 1][j +
								     1].
		  rgbtGreen + image[height - 2][j - 1].rgbtGreen +
		  image[height - 2][j].rgbtGreen + image[height - 2][j +
								     1].
		  rgbtGreen) / 6.0);

    }

  for (int i = 1; i < height - 1; i++)
    {
      temp[i][0].rgbtRed =
	(round) ((image[i - 1][0].rgbtRed + image[i][0].rgbtRed +
		  image[i + 1][0].rgbtRed + image[i - 1][1].rgbtRed +
		  image[i][1].rgbtRed + image[i + 1][1].rgbtRed) / 6.0);
      temp[i][width - 1].rgbtRed =
	(round) ((image[i - 1][width - 1].rgbtRed +
		  image[i][width - 1].rgbtRed + image[i + 1][width -
							     1].rgbtRed +
		  image[i - 1][width - 2].rgbtRed + image[i][width -
							     2].rgbtRed +
		  image[i + 1][width - 2].rgbtRed) / 6.0);
      temp[i][0].rgbtBlue =
	(round) ((image[i - 1][0].rgbtBlue + image[i][0].rgbtBlue +
		  image[i + 1][0].rgbtBlue + image[i - 1][1].rgbtBlue +
		  image[i][1].rgbtBlue + image[1 + i][1].rgbtBlue) / 6.0);
      temp[i][width - 1].rgbtBlue =
	(round) ((image[i - 1][width - 1].rgbtBlue +
		  image[i][width - 1].rgbtBlue + image[i + 1][width -
							      1].rgbtBlue +
		  image[i - 1][width - 2].rgbtBlue + image[i][width -
							      2].rgbtBlue +
		  image[i + 1][width - 2].rgbtBlue) / 6.0);
      temp[i][0].rgbtGreen =
	(round) ((image[i - 1][0].rgbtGreen + image[i][0].rgbtGreen +
		  image[i + 1][0].rgbtGreen + image[i - 1][1].rgbtGreen +
		  image[i][1].rgbtGreen + image[i + 1][1].rgbtGreen) / 6.0);
      temp[i][width - 1].rgbtGreen =
	(round) ((image[i - 1][width - 1].rgbtGreen +
		  image[i][width - 1].rgbtGreen + image[i + 1][width -
							       1].rgbtGreen +
		  image[i - 1][width - 2].rgbtGreen + image[i][width -
							       2].rgbtGreen +
		  image[i + 1][width - 2].rgbtGreen) / 6.0);
    }

  {
    temp[0][0].rgbtRed =
      (round) ((image[0][0].rgbtRed + image[0][1].rgbtRed +
		image[1][0].rgbtRed + image[1][1].rgbtRed) / 4.0);
    temp[0][0].rgbtGreen =
      (round) ((image[0][0].rgbtGreen + image[0][1].rgbtGreen +
		image[1][0].rgbtGreen + image[1][1].rgbtGreen) / 4.0);
    temp[0][0].rgbtBlue =
      (round) ((image[0][0].rgbtBlue + image[0][1].rgbtBlue +
		image[1][0].rgbtBlue + image[1][1].rgbtBlue) / 4.0);

    temp[0][width - 1].rgbtRed =
      (round) ((image[0][width - 1].rgbtRed + image[0][width - 2].rgbtRed +
		image[1][width - 1].rgbtRed + image[1][width -
						       2].rgbtRed) / 4.0);
    temp[0][width - 1].rgbtGreen =
      (round) ((image[0][width - 1].rgbtGreen +
		image[0][width - 2].rgbtGreen + image[1][width -
							 1].rgbtGreen +
		image[1][width - 2].rgbtGreen) / 4.0);
    temp[0][width - 1].rgbtBlue =
      (round) ((image[0][width - 1].rgbtBlue + image[0][width - 2].rgbtBlue +
		image[1][width - 1].rgbtBlue + image[1][width -
							2].rgbtBlue) / 4.0);

    temp[height - 1][0].rgbtRed =
      (round) ((image[height - 1][0].rgbtRed + image[height - 1][1].rgbtRed +
		image[height - 2][0].rgbtRed + image[height -
						     2][1].rgbtRed) / 4.0);
    temp[height - 1][0].rgbtGreen =
      (round) ((image[height - 1][0].rgbtGreen +
		image[height - 1][1].rgbtGreen + image[height -
						       2][0].rgbtGreen +
		image[height - 2][1].rgbtGreen) / 4.0);
    temp[height - 1][0].rgbtBlue =
      (round) ((image[height - 1][0].rgbtBlue +
		image[height - 1][1].rgbtBlue + image[height -
						      2][0].rgbtBlue +
		image[height - 2][1].rgbtBlue) / 4.0);

    temp[height - 1][width - 1].rgbtRed =
      (round) ((image[height - 1][width - 1].rgbtRed +
		image[height - 1][width - 2].rgbtRed + image[height -
							     2][width -
								1].rgbtRed +
		image[height - 2][width - 2].rgbtRed) / 4.0);
    temp[height - 1][width - 1].rgbtGreen =
      (round) ((image[height - 1][width - 1].rgbtGreen +
		image[height - 1][width - 2].rgbtGreen + image[height -
							       2][width -
								  1].
		rgbtGreen + image[height - 2][width - 2].rgbtGreen) / 4.0);
    temp[height - 1][width - 1].rgbtBlue =
      (round) ((image[height - 1][width - 1].rgbtBlue +
		image[height - 1][width - 2].rgbtBlue + image[height -
							      2][width -
								 1].rgbtBlue +
		image[height - 2][width - 2].rgbtBlue) / 4.0);

  }


  for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
	{
	  image[i][j] = temp[i][j];
	}
    }
  return;
}

// Detect edges
void
edges (int height, int width, RGBTRIPLE image[height][width])
{

  RGBTRIPLE temp[height][width];
  int gx, gy;
  for (int i = 1; i < height - 1; i++)
    {
      for (int j = 1; j < width - 1; j++)
	{

	  gx =
	    (-image[i - 1][j - 1].rgbtRed - (2 * image[i][j - 1].rgbtRed) -
	     image[i + 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed +
	     (2 * image[i][j + 1].rgbtRed) + image[i + 1][j + 1].rgbtRed);
	  gy =
	    (-image[i - 1][j - 1].rgbtRed - (2 * image[i - 1][j].rgbtRed) -
	     image[i - 1][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
	     (2 * image[i + 1][j].rgbtRed) + image[i + 1][j + 1].rgbtRed);
	  temp[i][j].rgbtRed = rounds ((sqrt ((gx * gx) + (gy * gy))));

	  gx =
	    (-image[i - 1][j - 1].rgbtGreen -
	     (2 * image[i][j - 1].rgbtGreen) - image[i + 1][j - 1].rgbtGreen +
	     image[i - 1][j + 1].rgbtGreen + (2 * image[i][j + 1].rgbtGreen) +
	     image[i + 1][j + 1].rgbtGreen);
	  gy =
	    (-image[i - 1][j - 1].rgbtGreen -
	     (2 * image[i - 1][j].rgbtGreen) - image[i - 1][j + 1].rgbtGreen +
	     image[i + 1][j - 1].rgbtGreen + (2 * image[i + 1][j].rgbtGreen) +
	     image[i + 1][j + 1].rgbtGreen);
	  temp[i][j].rgbtGreen = rounds ((sqrt ((gx * gx) + (gy * gy))));

	  gx =
	    (-image[i - 1][j - 1].rgbtBlue - (2 * image[i][j - 1].rgbtBlue) -
	     image[i + 1][j - 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
	     (2 * image[i][j + 1].rgbtBlue) + image[i + 1][j + 1].rgbtBlue);
	  gy =
	    (-image[i - 1][j - 1].rgbtBlue - (2 * image[i - 1][j].rgbtBlue) -
	     image[i - 1][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
	     (2 * image[i + 1][j].rgbtBlue) + image[i + 1][j + 1].rgbtBlue);
	  temp[i][j].rgbtBlue = rounds ((sqrt ((gx * gx) + (gy * gy))));

	}

    }

  for (int j = 1; j < width - 1; j++)
    {


      gx =
	(-2 * image[0][j - 1].rgbtRed + (2 * image[0][j + 1].rgbtRed) -
	 image[1][j - 1].rgbtRed + image[1][j + 1].rgbtRed);
      gy =
	(image[1][j - 1].rgbtRed + (2 * image[1][j].rgbtRed) +
	 image[1][j + 1].rgbtRed);
      temp[0][j].rgbtRed = rounds ((sqrt ((gx * gx) + (gy * gy))));

      gx =
	(-2 * image[0][j - 1].rgbtGreen + (2 * image[0][j + 1].rgbtGreen) -
	 image[1][j - 1].rgbtGreen + image[1][j + 1].rgbtGreen);
      gy =
	(image[1][j - 1].rgbtGreen + (2 * image[1][j].rgbtGreen) +
	 image[1][j + 1].rgbtGreen);
      temp[0][j].rgbtGreen = rounds ((sqrt ((gx * gx) + (gy * gy))));

      gx =
	(-2 * image[0][j - 1].rgbtBlue + (2 * image[0][j + 1].rgbtBlue) -
	 image[1][j - 1].rgbtBlue + image[1][j + 1].rgbtBlue);
      gy =
	(image[1][j - 1].rgbtBlue + (2 * image[1][j].rgbtBlue) +
	 image[1][j + 1].rgbtBlue);
      temp[0][j].rgbtBlue = rounds ((sqrt ((gx * gx) + (gy * gy))));

      gx =
	(-image[height - 2][j - 1].rgbtRed +
	 image[height - 2][j + 1].rgbtRed - 2 * image[height - 1][j -
								  1].rgbtRed +
	 2 * image[height - 1][j + 1].rgbtRed);
      gy =
	(-image[height - 2][j - 1].rgbtRed -
	 2 * image[height - 2][j].rgbtRed - image[height - 2][j + 1].rgbtRed);
      temp[height - 1][j].rgbtRed = rounds ((sqrt ((gx * gx) + (gy * gy))));

      gx =
	(-image[height - 2][j - 1].rgbtGreen +
	 image[height - 2][j + 1].rgbtGreen - 2 * image[height - 1][j -
								    1].
	 rgbtGreen + 2 * image[height - 1][j + 1].rgbtGreen);
      gy =
	(-image[height - 2][j - 1].rgbtGreen -
	 2 * image[height - 2][j].rgbtGreen - image[height - 2][j +
								1].rgbtGreen);
      temp[height - 1][j].rgbtGreen = rounds ((sqrt ((gx * gx) + (gy * gy))));

      gx =
	(-image[height - 2][j - 1].rgbtBlue +
	 image[height - 2][j + 1].rgbtBlue - 2 * image[height - 1][j -
								   1].
	 rgbtBlue + 2 * image[height - 1][j + 1].rgbtBlue);
      gy =
	(-image[height - 2][j - 1].rgbtBlue -
	 2 * image[height - 2][j].rgbtBlue - image[height - 2][j +
							       1].rgbtBlue);
      temp[height - 1][j].rgbtBlue = rounds ((sqrt ((gx * gx) + (gy * gy))));


    }



  for (int i = 1; i < height - 1; i++)
    {
      gx =
	(image[i - 1][1].rgbtRed + 2 * image[i][1].rgbtRed +
	 image[i + 1][1].rgbtRed);
      gy =
	(-2 * image[i - 1][0].rgbtRed + 2 * image[i + 1][0].rgbtRed -
	 image[i - 1][1].rgbtRed + image[i + 1][1].rgbtRed);
      temp[i][0].rgbtRed = rounds ((sqrt ((gx * gx) + (gy * gy))));

      gx =
	(image[i - 1][1].rgbtGreen + 2 * image[i][1].rgbtGreen +
	 image[i + 1][1].rgbtGreen);
      gy =
	(-2 * image[i - 1][0].rgbtGreen + 2 * image[i + 1][0].rgbtGreen -
	 image[i - 1][1].rgbtGreen + image[i + 1][1].rgbtGreen);
      temp[i][0].rgbtGreen = rounds ((sqrt ((gx * gx) + (gy * gy))));

      gx =
	(image[i - 1][1].rgbtBlue + 2 * image[i][1].rgbtBlue +
	 image[i + 1][1].rgbtBlue);
      gy =
	(-2 * image[i - 1][0].rgbtBlue + 2 * image[i + 1][0].rgbtBlue -
	 image[i - 1][1].rgbtBlue + image[i + 1][1].rgbtBlue);
      temp[i][0].rgbtBlue = rounds ((sqrt ((gx * gx) + (gy * gy))));

      gx =
	(-image[i - 1][width - 2].rgbtRed - 2 * image[i][width - 2].rgbtRed -
	 image[i + 1][width - 2].rgbtRed);
      gy =
	(-2 * image[i - 1][width - 1].rgbtRed +
	 2 * image[i + 1][width - 1].rgbtRed - image[i - 1][width -
							    2].rgbtRed +
	 image[i + 1][width - 2].rgbtRed);
      temp[i][width - 1].rgbtRed = rounds ((sqrt ((gx * gx) + (gy * gy))));

      gx =
	(-image[i - 1][width - 2].rgbtGreen -
	 2 * image[i][width - 2].rgbtGreen - image[i + 1][width -
							  2].rgbtGreen);
      gy =
	(-2 * image[i - 1][width - 1].rgbtGreen +
	 2 * image[i + 1][width - 1].rgbtGreen - image[i - 1][width -
							      2].rgbtGreen +
	 image[i + 1][width - 2].rgbtGreen);
      temp[i][width - 1].rgbtGreen = rounds ((sqrt ((gx * gx) + (gy * gy))));

      gx =
	(-image[i - 1][width - 2].rgbtBlue -
	 2 * image[i][width - 2].rgbtBlue - image[i + 1][width - 2].rgbtBlue);
      gy =
	(-2 * image[i - 1][width - 1].rgbtBlue +
	 2 * image[i + 1][width - 1].rgbtBlue - image[i - 1][width -
							     2].rgbtBlue +
	 image[i + 1][width - 2].rgbtBlue);
      temp[i][width - 1].rgbtBlue = rounds ((sqrt ((gx * gx) + (gy * gy))));

    }

  {
    gx = (2 * image[0][1].rgbtRed + image[1][1].rgbtRed);
    gy = (2 * image[1][0].rgbtRed + image[1][1].rgbtRed);
    temp[0][0].rgbtRed = rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx = (BYTE) (int) (2 * image[0][1].rgbtGreen + image[1][1].rgbtGreen);
    gy = (BYTE) (int) (2 * image[1][0].rgbtGreen + image[1][1].rgbtGreen);
    temp[0][0].rgbtGreen = rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx = (2 * image[0][1].rgbtBlue + image[1][1].rgbtBlue);
    gy = (2 * image[1][0].rgbtBlue + image[1][1].rgbtBlue);
    temp[0][0].rgbtBlue = rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx = (-2 * image[0][width - 2].rgbtRed - image[1][width - 2].rgbtRed);
    gy = (image[1][width - 2].rgbtRed + 2 * image[1][width - 1].rgbtRed);
    temp[0][width - 1].rgbtRed = rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx = (-2 * image[0][width - 2].rgbtGreen - image[1][width - 2].rgbtGreen);
    gy = (image[1][width - 2].rgbtGreen + 2 * image[1][width - 1].rgbtGreen);
    temp[0][width - 1].rgbtGreen = rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx = (-2 * image[0][width - 2].rgbtBlue - image[1][width - 2].rgbtBlue);
    gy = (image[1][width - 2].rgbtBlue + 2 * image[1][width - 1].rgbtBlue);
    temp[0][width - 1].rgbtBlue = rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx = (image[height - 2][1].rgbtRed + 2 * image[height - 1][1].rgbtRed);
    gy = (-2 * image[height - 2][0].rgbtRed - image[height - 2][1].rgbtRed);
    temp[height - 1][0].rgbtRed = rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx =
      (image[height - 2][1].rgbtGreen + 2 * image[height - 1][1].rgbtGreen);
    gy =
      (-2 * image[height - 2][0].rgbtGreen - image[height - 2][1].rgbtGreen);
    temp[height - 1][0].rgbtGreen = rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx = (image[height - 2][1].rgbtBlue + 2 * image[height - 1][1].rgbtBlue);
    gy = (-2 * image[height - 2][0].rgbtBlue - image[height - 2][1].rgbtBlue);
    temp[height - 1][0].rgbtBlue = rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx =
      (-2 * image[height - 1][width - 2].rgbtRed -
       image[height - 2][width - 2].rgbtRed);
    gy =
      (-2 * image[height - 2][width - 1].rgbtRed -
       image[height - 2][width - 2].rgbtRed);
    temp[height - 1][width - 1].rgbtRed =
      rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx =
      (-2 * image[height - 1][width - 2].rgbtGreen -
       image[height - 2][width - 2].rgbtGreen);
    gy =
      (-2 * image[height - 2][width - 1].rgbtGreen -
       image[height - 2][width - 2].rgbtGreen);
    temp[height - 1][width - 1].rgbtGreen =
      rounds ((sqrt ((gx * gx) + (gy * gy))));

    gx =
      (-2 * image[height - 1][width - 2].rgbtBlue -
       image[height - 2][width - 2].rgbtBlue);
    gy =
      (-2 * image[height - 2][width - 1].rgbtBlue -
       image[height - 2][width - 2].rgbtBlue);
    temp[height - 1][width - 1].rgbtBlue =
      rounds ((sqrt ((gx * gx) + (gy * gy))));


  }


  for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
	{
	  image[i][j] = temp[i][j];
	}
    }

  return;
}
