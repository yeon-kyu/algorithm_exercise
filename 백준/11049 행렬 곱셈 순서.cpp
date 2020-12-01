#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <memory.h>
using namespace std;

//void show_matrix(int** C, int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << left << setw(12) << C[i][j];
//		}
//		cout << endl;
//	}
//}

int main() {
	int n;
	cin >> n;
	int* d = new int[n + 1];
	//int d[501];
	for (int i = 0; i < n; i++) {
		cin >> d[i] >> d[i + 1];
	}

	int** C = new int*[n];
	for (int i = 0; i < n; i++) {
		C[i] = new int[n];
		memset(C[i], 0, sizeof(int)*n);
	}
	//int C[501][501];
	for (int i = 0; i < n; i++) {
		C[i][i] = 0;
	}
	//show_matrix(C, n); //n : 3

	//for (int i = 0; i < n-1; i++) { //0,1,2
	//	for (int j = 1; j < n - i;j++) { //i가 0일때 j는1,2
	//		C[i][j] = 9999999999;
	//		cout << C[i][j - 1]+d[i]
	//	}
	//}
	for (int L = 1; L < n; L++) {
		for (int i = 0; i < n - L; i++) {
			int j = i + L;
			C[i][j] = numeric_limits<int>::max();
			for (int k = i; k < j; k++) {
				int temp = C[i][k] + C[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
				if (temp < C[i][j]) {
					C[i][j] = temp;
					//S[i][j] = k + 1;
				}
			}
		}
	}
	//show_matrix(C, n);
	cout << C[0][n - 1];
	return 0;
}