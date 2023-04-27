#include <stdio.h>

int main()
{
	int digit, sum, month;
	scanf ("%d", &digit) ;
	for (int i = 0; i <= digit; i ++)
	{
		printf("%d ", i);
	}
	float annual_interest_rate; 
	scanf ("%d %d" , &month, &sum) ;
	scanf ("%f", &annual_interest_rate) ;
	for (int i = 0; i < month; i ++)
	{
		float tmp = ( (1 + (annual_interest_rate * month / 100))) ;
		printf("%f\n", tmp * sum) ;
	}
	return 0;
}
