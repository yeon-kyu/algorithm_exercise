#include <stdio.h>


int main() {

	char a[100];
	scanf("%s", a);

	int i = 0;
	while (a[i] != NULL) {
		printf("%c", a[i]);
		if (i % 10 == 9)
			puts("");
		i++;

	}


}