#include <stdio.h>

enum Auto
		{
	CAR,
	TRUCK,
	BUS,
	RACING
};

struct Circle
		{
	int radius;
	int diameter;
	float pi;
	float square;
};

union Keyboard
		{
	int x;
	struct
	{
		unsigned char NumLock:1;
		unsigned char CapsLock:1;
		unsigned char ScrollLock:1;
	} status;
};

int main()
{
	int a;
	enum Auto buss;
	buss = BUS;
	printf("%d\n", buss);
	struct Circle ci;
	ci.radius = 8;
	ci.diameter = 16;
	ci.pi = 3.14;
	ci.square = ci.pi * ci.radius * ci.radius;
	printf("%f\n", ci.square);
	union Keyboard k;
	scanf("%x", &k.x);
	printf("NumLock: %s /// CapsLock: %s /// ScrollLock: %s \n", k.status.NumLock ? "ON" : "OFF", k.status.CapsLock ? "ON" : "OFF", k.status.ScrollLock ? "ON" : "OFF");
	return 0;
}
