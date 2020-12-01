#include <iostream>
#include <string>
using namespace std;

int a[64][64];

bool checkCompress(int row, int col, int n) { //압축 가능한지 확인
	int flag = a[row][col];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[row + i][col + j] != flag) {
				return false;
			}
		}
	}
	return true;
}
void quadTree(int row, int col, int n) {
	
	if (checkCompress(row, col, n) == true) {
		cout << a[row][col];
	}

	else {
		cout << '(';
		quadTree(row,col,n / 2); //1사분면
		quadTree(row, col + n / 2, n / 2); //2사분면
		quadTree(row + n / 2, col, n / 2); //3사분면
		quadTree(row + n / 2, col + n / 2, n / 2); //4사분면
		cout << ')';
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			a[i][j] = temp[j]-48;
		}
	}

	quadTree(0,0,n);
}
