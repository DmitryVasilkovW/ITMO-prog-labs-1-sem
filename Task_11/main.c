#include <stdio.h>
#include "d.h"
int main()
{
	struct Rhombus rhombus;
	printf("Enter the coordinates of the first point: ");
	scanf("%lf %Lf", &rhombus.x1, &rhombus.y1);
	printf("\n");
	printf("Enter the coordinates of the second point: ");
	scanf("%lf %lf", &rhombus.x2, &rhombus.y2);
	printf("\n");
	printf("Enter the coordinates of the third point: ");
	scanf("%Lf %Lf", &rhombus.x3, &rhombus.y3);
	printf("\n");
	printf("Enter the coordinates of the fourth point: ");
	scanf("%Lf %Lf", &rhombus.x4, &rhombus.y4);
	printf("\n");
	printf("Perimeter = %.21f \n", Perimeter(rhombus));
	printf("Square = %.21f \n", Square(rhombus));
	return 0;
}
