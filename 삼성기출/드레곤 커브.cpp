#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;

int subMat[101][101];
int mainMat[101][101];

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			mainMat[i][j] = 0;
		}
	}
}
void refresh() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			subMat[i][j] = 0;
		}
	}
}

void doDragonCurve(int x, int y, int g,int end_x, int end_y) {
	if (g < 0) {
		return;
	}
	//1 : 기존 커브 2: 방금 생긴 커브 3 : 기존에 있었지만 방금생긴거랑겹친 커브
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) { 
			if (subMat[i][j] == 1||subMat[i][j]==3) { 
				if (subMat[end_x+end_y-j][end_y-end_x+i] == 1) {
					subMat[end_x + end_y - j][end_y - end_x + i] = 3;
				}
				else {
					subMat[end_x + end_y - j][end_y - end_x + i] = 2;
				}
			}
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (subMat[i][j] > 0) {
				subMat[i][j] = 1;
			}
		}
	}
	//cout << "남은 세대 : "<<g <<",다음 끝점 : "<<end_x + end_y - y <<", "<< end_y - end_x + x <<endl;
	doDragonCurve(x, y, g - 1, end_x + end_y - y, end_y - end_x + x);
}

int main() {
	int x, y, d, g;

	init();

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		refresh();
		subMat[x][y] = 1;
		int endX = -1; int endY = -1;
		switch (d)
		{
		case 0: endX = x + 1; endY = y;
			break;
		case 1: endY = y - 1; endX = x;
			break;
		case 2: endX = x - 1; endY = y;
			break;
		case 3: endY = y + 1; endX = x;
			break;
		default:
			break;
		}
		subMat[endX][endY] = 1;
		
		doDragonCurve(x, y, g - 1,endX,endY);
		for (int a = 0; a < 101; a++) {
			for (int b = 0; b < 101; b++) {
				if (subMat[a][b] == 1) {
					mainMat[a][b] = 1;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (mainMat[j][i] > 0 && mainMat[j + 1][i] > 0 && mainMat[j][i + 1] > 0 && mainMat[j + 1][i + 1] > 0) {
				ans++;
			}
		}
	}
	cout << ans;


	return 0;
}