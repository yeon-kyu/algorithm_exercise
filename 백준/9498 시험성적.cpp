#include <stdio.h>


int main() {

	int a;
	scanf("%d", &a);

	if (a > 89)
		puts("A");
	else if (a > 79)
		puts("B");
	else if (a > 69)
		puts("C");
	else if (a > 59)
		puts("D");
	else
		puts("F");


}