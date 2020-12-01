#include <stdio.h>
void mergeSort(int ar[], int p, int q) { //divide & conquer
	if (p < q) {
		int k = (p + q) / 2;
		mergeSort(ar, p, k);
		mergeSort(ar, k + 1, q);

		int x = p;
		int y = k + 1;
		int* B = (int*)malloc(sizeof(int)*(q - p + 1));
		for (int i = 0; i < q - p + 1; i++) {
			if (x == k + 1) {
				B[i] = ar[y++];
				continue;
			}
			if (y == q + 1) {
				B[i] = ar[x++];
				continue;
			}

			if (ar[x] < ar[y]) {
				B[i] = ar[x++];
			}
			else {
				B[i] = ar[y++];
			}
		}
		for (int i = 0; i < q - p + 1; i++) {
			ar[p + i] = B[i];
		}

		free(B);
	}

}
int main() {
	int size;
	scanf("%d", &size);
	int* ar = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i<size; i++) {
		scanf("%d", &ar[i]);
	}
	mergeSort(ar, 0, size - 1);
	for (int i = 0; i<size; i++) {
		printf("%d\n", ar[size - 1 - i]);
	}
}