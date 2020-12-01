#include <stdio.h>


int main() {
	int i, j = 0;
	char buffer[100];

	for (int k = 0; k < 101; k++) {
		if (fgets(buffer, 101, stdin) != 0)
			printf(buffer);
	}


}