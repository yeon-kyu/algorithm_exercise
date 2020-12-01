#include <stdio.h>


int main() {

	//int n;
	//scanf("%d", &n);

	int a, b;

	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		printf("%d\n", a + b);
	}

}