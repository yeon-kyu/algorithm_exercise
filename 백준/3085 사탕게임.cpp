#include <iostream>
#include <string>

using namespace std;

int N;
char mat[51][51];
int maxi;

void findMax(int r,int c) {
	char cur = mat[r][c];

	//¼¼·Î È®ÀÎ(column °íÁ¤)
	int vertic = 1;
	int row = r - 1;
	while (true) {
		if (row >= 0 && mat[row][c]==cur) {
			vertic++;
			row--;
		}
		else {
			break;
		}
	}
	row = r + 1;
	while (true) {
		if (row < N && mat[row][c] == cur) {
			vertic++;
			row++;
		}
		else {
			break;
		}
	}
	if (vertic > maxi) {
		maxi = vertic;
	}

	//°¡·Î È®ÀÎ(row °íÁ¤)
	int horizon = 1;
	int col = c - 1;
	while (true) {
		if (col >= 0 && mat[r][col] == cur) {
			horizon++;
			col--;
		}
		else {
			break;
		}
	}
	col = c + 1;
	while (true) {
		if (col < N && mat[r][col] == cur) {
			horizon++;
			col++;
		}
		else {
			break;
		}
	}
	if (horizon > maxi) {
		maxi = horizon;
	}
}

void brute(int r, int c) {
	//findMax(r, c);

	if (r > 0) {//À§¿¡¶û ¹Ù²ãµµ µÊ
		char temp = mat[r][c];
		mat[r][c] = mat[r - 1][c];
		mat[r - 1][c] = temp;
		findMax(r, c);

		temp = mat[r - 1][c];
		mat[r - 1][c] = mat[r][c];
		mat[r][c] = temp;
	}

	if (r < N - 1) {//¾Æ·¡¶û ¹Ù²ãµµ µÊ
		char temp = mat[r][c];
		mat[r][c] = mat[r + 1][c];
		mat[r + 1][c] = temp;

		findMax(r, c);
		
		temp = mat[r + 1][c];
		mat[r + 1][c] = mat[r][c];
		mat[r][c] = temp;
	}
	if (c < N - 1) {//¿À¸¥ÂÊÀÌ¶û ¹Ù²ãµµ µÊ
		char temp = mat[r][c];
		mat[r][c] = mat[r][c + 1];
		mat[r][c + 1] = temp;

		findMax(r, c);

		temp = mat[r][c + 1];
		mat[r][c + 1] = mat[r][c];
		mat[r][c] = temp;
	}
	if (c > 0) { //¿ÞÂÊÀÌ¶û ¹Ù²ãµµ µÊ
		char temp = mat[r][c];
		mat[r][c] = mat[r][c - 1];
		mat[r][c - 1] = temp;
		findMax(r, c);
		temp = mat[r][c - 1];
		mat[r][c - 1] = mat[r][c];
		mat[r][c] = temp;
	}


}
int main() {

	/*for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			mat[i][j] = 0;
		}
	}*/
	maxi = 1;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++) {
			mat[i][j] = temp[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			brute(i, j);
		}
	}
	cout << maxi;

}