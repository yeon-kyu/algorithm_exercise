#include <stdio.h>

int findSize(char code[]) {
	for (int i = 0; i < 500; i++) {
		if (code[i] == NULL)
		{
			return i - 1;
		}
	}


}



int main() {

	while (1)
	{
		char code[501] = { NULL };
		fgets(code, 501, stdin);

		if (code[0] == 'E'&&code[1] == 'N'&&code[2] == 'D')
			break;

		char decode[501] = { NULL };
		int size = findSize(code);
		//printf("%d", size);

		for (int i = 0; i < size; i++) {
			decode[i] = code[size - i - 1];
		}
		printf("%s\n", decode);


	}

	return 0;
}