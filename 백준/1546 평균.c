#include <stdio.h>


int main() {

	int n;
	scanf("%d", &n);

	//���� �ְ��� ã��
	int* score = malloc(n * sizeof(int));

	float avg = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
		avg += score[i];
	}
	avg = (float)avg / n; // ���� ���

	int max = score[0];
	for (int i = 1; i < n; i++) {
		if (score[i] > max)
			max = score[i];
	}
	/*printf("avg : %f , max : %d", avg,max);
	puts("");*/

	//avg = (float)avg * (100 / max);
	avg = 100.0*avg / max;
	printf("%f", avg);




}