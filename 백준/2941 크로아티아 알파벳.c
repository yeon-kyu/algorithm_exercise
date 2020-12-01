#include <stdio.h>

int main() {

	char word[101];
	scanf("%s", &word);

	int count = 0;
	for (int i = 0; word[i] != NULL; i++) {
		if (word[i] == 'c'&&word[i + 1] == '=') {
			count++;
			i++;
		}
		else if (word[i] == 'c'&&word[i + 1] == '-') {
			count++;
			i++;
		}
		else if (word[i] == 'd') {
			if (word[i + 1] == 'z'&&word[i + 2] == '=')
			{
				count++;
				i += 2;
			}
			else if (word[i + 1] == '-') {
				count++;
				i++;
			}
			else {
				count++;
			}

		}
		else if (word[i] == 'l'&&word[i + 1] == 'j') {
			count++;
			i++;
		}
		else if (word[i] == 'n'&&word[i + 1] == 'j') {
			count++;
			i++;
		}
		else if (word[i] == 's'&&word[i + 1] == '=') {
			count++;
			i++;
		}
		else if (word[i] == 'z' &&word[i + 1] == '=') {
			count++;
			i++;
		}
		else {
			count++;
		}

	}
	printf("%d", count);
}