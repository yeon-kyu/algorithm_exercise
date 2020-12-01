#include <stdio.h>


int main() {

	int a, b;
	scanf("%d %d", &a, &b);

	int day = b;
	// 31 28 31 30 31 30 31 31 30 31 30 31
	if (a == 1)
		day += 0;
	else if (a == 2)
		day += 31;
	else if (a == 3)
		day += 31 + 28;
	else if (a == 4)
		day += 31 + 28 + 31;
	else if (a == 5)
		day += 31 + 28 + 31 + 30;
	else if (a == 6)
		day += 31 + 28 + 31 + 30 + 31;
	else if (a == 7)
		day += 31 + 28 + 31 + 30 + 31 + 30;
	else if (a == 8)
		day += 31 + 28 + 31 + 30 + 31 + 30 + 31;
	else if (a == 9)
		day += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
	else if (a == 10)
		day += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
	else if (a == 11)
		day += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
	else if (a == 12)
		day += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
	// 31 28 31 30 31 30 31 31 30 31 30 31

	int week = day % 7;
	switch (week) {
	case 0:
		printf("SUN"); break;
	case 1:
		printf("MON"); break;
	case 2:
		printf("TUE"); break;
	case 3:
		printf("WED"); break;
	case 4:
		printf("THU"); break;
	case 5:
		printf("FRI"); break;
	case 6:
		printf("SAT"); break;

	}
}