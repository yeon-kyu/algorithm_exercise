#include <stdio.h>


int main() {

	//���� '1'�� 49

	int n;
	scanf("%d", &n);

	char* x;
	x = malloc(sizeof(char)*n);
	scanf("%s", x);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += x[i] - 48;
	}
	printf("%d", sum);
}