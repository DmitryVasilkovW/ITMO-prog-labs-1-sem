#include <stdio.h>
int summa = 0;

int Sum(int digit)
{
	if(digit == 0)
		return summa;
	else
	{
		summa += digit % 10;
		return Sum(digit /= 10);
	}
}

void Arr(int digit, int *array, int number_of_elements)
{
	for (int i = 0; i < number_of_elements; i++)
	{
		array[i] = digit % 10;
		digit /= 10;
	}
}


int main()
{
	int digit, number_of_elements;
	scanf("%d", &digit);
	scanf("%d", &number_of_elements);
	int array[number_of_elements];
	printf("%d\n", Sum(digit));
	Arr(digit, array, number_of_elements);
	for (int i = 0; i < number_of_elements; i++)
	{
		printf("%d ", array[i]);
	}
}
