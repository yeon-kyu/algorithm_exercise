#include <stdio.h>


int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a;
		char S[21];
		//int count = 0;
		//char SS[160] = {NULL};
		scanf("%d %s", &a, S);
		//scanf("%s", S);
		//fgets(S,20,stdin);

		int size;
		for (int j = 0; j < 21; j++) {
			if (S[j] == NULL) {
				size = j;
				break;
			}
		}//S[]크기 구함

		 //printf("size는 : %d", size);

		for (int j = 0; j < size; j++) {

			for (int k = 0; k < a; k++) {
				printf("%c", S[j]);
				//SS[count] = S[j];
				//count++;
			}
		}
		//printf("%s\n", SS);
		puts("");
	}


}