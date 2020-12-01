#include <stdio.h>


int main() {

	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {//첫번째줄 i : 0  j : 0,1,2,3,4
									 //두번재줄 i : 1   j : 0,1,2,3,4
									 //다섯번째줄 i: 4  j : 0,1,2,3,4
			if (j + i > a - 2)
				printf("*");
			else
				printf(" ");
		}
		puts("");
	}

}