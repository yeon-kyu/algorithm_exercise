#include <stdio.h>

int findalpha(char S[], int i, int size) {
	//return position where 'i' is..
	int position = -1;
	for (int j = 0; j < size; j++) {
		if (S[j] == 'a' + i)
			return j;
	}
	return position;


}
int main() {

	char S[100];
	fgets(S, 100, stdin);

	int size;
	for (int i = 0; i < 100; i++) {
		if (S[i] == NULL) {
			size = i - 1; //\n도 포함되어있으므로 -1한다
			break;
		}

	}

	//int alphabet[26];

	for (int i = 0; i < 26; i++) {

		int num = findalpha(S, i, size);
		printf("%d ", num);


	}






}