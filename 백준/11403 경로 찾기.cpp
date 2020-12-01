#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int** matrix;


void doDFS(int v) { //노드 v에서 어디까지 연결될수 있는가를 탐색
	for (int i = 1; i <= n; i++) {
		if (matrix[v][i] == 1) {
			//cout << "1발견" << endl;
			for (int j = 1; j <= n; j++) {
				if (matrix[i][j] == 1) {
					matrix[v][j] = 1;
					//cout << v<<" "<<j << endl;
				}
			}
		}
	}
}

int main() {
	cin >> n;

	matrix = new int*[n + 1];

	for (int i = 0; i <= n; i++) {
		matrix[i] = new int[n + 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> matrix[i][j];
		}
	}


	for (int m = 0; m < n; m++) {
		for (int i = 1; i <= n; i++) {
			doDFS(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}