#include <stdio.h>


int main() {

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	//√÷¥Î a : 15 b:28 c 19

	int i = 0;

	while (1) {

		while (1) {
			if ((28 * i + b - a) % 15 == 0)
				break;
			i++;
		}

		if ((28 * i + b - c) % 19 == 0)
			break;
		i++;
	}
	printf("%d", 28 * i + b);






}