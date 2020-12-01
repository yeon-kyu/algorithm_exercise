#include <stdio.h>


int main() {

	int a; //9
	scanf("%d", &a);

	int i = 0;
	int num[2];
	int flag = 0;
	num[0] = a / 5; //1
	num[1] = (a % 5) / 3; //1

	while (a > 5 * i) {
		num[1] = (a - 5 * num[0]) / 3; //4/3 = 1 , 3

		if ((a - 5 * num[0]) % 3 == 0) { // 1 , 0
			flag = 1;
			break;
		}

		i++;  // 1
		num[0]--; // 0 
	}

	if (flag == 1)
		printf("%d", num[0] + num[1]);
	else
		printf("%d", -1);




}