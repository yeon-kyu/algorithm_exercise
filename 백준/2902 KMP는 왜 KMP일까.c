#include <stdio.h>

int main() {

	char longName[101];
	scanf("%s", &longName);

	printf("%c", longName[0]);

	for (int i = 1; i < 101; i++) {
		if (longName[i] == '-')
			printf("%c", longName[i + 1]);
	}

	return 0;
}