#include <stdio.h>


int main() {

	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int n;
		float avg = 0;
		int count = 0;
		scanf("%d", &n);
		int* score = malloc(n * sizeof(int));
		for (int i = 0; i < n; i++) {
			scanf("%d", &score[i]);
			avg += score[i];
		}
		avg = avg / n;
		//printf("Æò±ÕÀº : %f", avg);

		for (int i = 0; i < n; i++) {
			if (score[i] > avg)
				count++;
		}

		printf("%.3f%%\n", 100.0*count / n);




	}




}