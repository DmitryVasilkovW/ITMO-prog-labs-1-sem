#include "d.h"
#include <math.h>

double Perimeter (struct Rhombus rhombus)
{
	return 2 * (sqrt(pow(rhombus.x2 - rhombus.x1, 2) + pow(rhombus.y2 - rhombus.y1, 2)) + sqrt(pow(rhombus.x4 - rhombus.x3, 2) + pow(rhombus.y4 - rhombus.y3, 2)));
}

double Square (struct Rhombus rhombus)
{
	return sqrt(pow(rhombus.x2 - rhombus.x1, 2) + pow(rhombus.y2 - rhombus.y1, 2)) * sqrt(pow(rhombus.x4 - rhombus.x3, 2) + pow(rhombus.y4 - rhombus.y3, 2)) * 0.5;
}
