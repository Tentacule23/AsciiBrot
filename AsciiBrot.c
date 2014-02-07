////////////////////////////////////////////////////////////////////////
// ASCII-BROT :: Student Exercise
/*
TASK ONE:   Implement the incomplete functions:

- int mandelbrot(double x, double y);
- void square(point * p);
- double lengthSquared(point * p);

TASK TWO:   Allow the user to specify a different centre point:

- Currently the centre point is always (0,0).
- By modifying the range values for X/Y axis, you can
set the centre point to be any 2D point you like.

CHALLENGE:  Provide a way for the user to specify a 'zoom' level for
rendering the mandelbrot set.

- In order to implement zoom you will have to replace
the calculation for scaling the provided x/y values.
- The zoom level is the number of complex plane units
between each coordinate represented by a character
in the Ascii-Brot.
- For example, initially we have a height of 30 characters,
with a Y-Axis range of (1 - -1) == 2. This means that
there are 30/2 units between each coordinate represented
by a character in the Ascii-Brot.

For this example if we replaced the axis ranges with zoom,
then a zoom level of 30/2 would give us the same mandelbrot.
*/
////////////////////////////////////////////////////////////////////////

// std headers
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>


// logic defines
#define TRUE   1
#define FALSE  0

// ascii-brot size
#define HEIGHT 30
#define WIDTH  72
#define MAX_ITERATIONS 255

// ascii-brot viewport
#define MIN_X -1.5
#define MAX_X  1
#define MIN_Y -1
#define MAX_Y  1
#define X_RANGE (MAX_X - MIN_X)
#define Y_RANGE (MAX_Y - MIN_Y)

// *** STUDENT REQUIRED TO COMPLETE THESE FUNCTIONS *** //
int mandelbrot(double x, double y);
double squareX(double x, double y);
double squareY(double x, double y);
double lengthSquared(double x, double y);
double zeConvertX(double x);
double zeConvertY(double y);


////////////////////////////////////////////////////////////////////////
// complete the mandelbrot algorithm to render a beautiful ASCII-BROT!

int main(int argc, char * argv[]) {
	printf(" UNSW Computing 1 - ASCII-BROT\n");

	// iterate through each row
	int x = 0;
	int y = 0;

	while (y < HEIGHT) 
	{
		// iterate through each column
		while (x < WIDTH) 
		{
			if (mandelbrot(x, y)) 
			{
				printf("*");
			}
			else {
				printf(" ");
			}
			x++;
		}
 
		printf("\n");
		x = 0;
		y++;
	}
	//scanf("%d", &x);

	return EXIT_SUCCESS;
}


////////////////////////////////////////////////////////////////////////
// implement mandelbrot escape-time algorithm for a given x,y coordinate
// (whether or not a point is in the mandelbrot set or not)

int mandelbrot(double x, double y) 
{
	int result = TRUE;

	double Zx = 0;
	double Zy = 0;

	double ZZx = 0;
	double ZZy = 0;

	int counter;
	counter = 0;

	double conX = zeConvertX(x);
	double conY = zeConvertY(y);
	
	while ((result == TRUE)&&(counter <= MAX_ITERATIONS))
	{
		Zx = (ZZx) + conX;
		Zy = (ZZy) + conY;
		
		if (lengthSquared(Zx, Zy) > 4 )
		{
			result = FALSE;
		}
		else
		{

			ZZx = squareX(Zx, Zy);
			ZZy = squareY(Zx, Zy);

			counter ++;

		}

	}

	return result;
}

////////////////////////////////////////////////////////////////////////
// compute the length/magnitude (squared) of a 2D vector
// in other words the distance squared of a point from the origin.

double lengthSquared(double x, double y) 
{
	
	double valueLengthSquared = ((x * x) + (y * y));

	return valueLengthSquared;

}


////////////////////////////////////////////////////////////////////////
// performs the calculation Z^2 for the real part of a complex number

double squareX(double x, double y) 
{
	double valueSquareX = ((x * x) - (y * y));
	
	return valueSquareX;

}

////////////////////////////////////////////////////////////////////////
// performs the calculation Z^2 for the imaginary part of a complex number

double squareY(double x, double y)
{
	double valueSquareY = (x*y + x*y);

	return valueSquareY;
}

double zeConvertX(double x)
{

	double stepOne = x / WIDTH;
	double stepTwo = stepOne * X_RANGE;
	double stepThree = stepTwo + MIN_X;

	return stepThree;

}

double zeConvertY(double y)
{
	double stepOne = y / HEIGHT;
	double stepTwo = stepOne * Y_RANGE;
	double stepThree = stepTwo + MIN_Y;


	return stepThree;
}

// EOF