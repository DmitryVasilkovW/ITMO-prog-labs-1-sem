#include <stdio.h>
#include <cmath>

int main() 
{
	float first_arg, second_arg, z1, z2;
	scanf("%f", &first_arg);
	scanf("%f", &second_arg);
	z1 = (sin(2 * first_arg) + sin(5 * first_arg) - sin(3 * first_arg)) / (cos(first_arg) - cos(3 * first_arg) + cos(5 * first_arg));
	z2 = tan(3 * second_arg);
	printf("8f\n %f\n", z1, z2);
	return 0;
}
