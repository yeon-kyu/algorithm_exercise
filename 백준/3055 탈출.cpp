#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int R,C;
bool visited[51][51];
bool survived[51][51];
bool isUpdated[51][51];
bool isWater[51][51];
bool isWaterUpdated[51][51];
bool isRock[51][51];
bool isGoal[51][51];
bool isDone = false;

void resetUpdate() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			isUpdated[i][j] = false;
		}
	}
}

void resetWaterUpdate() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			isWaterUpdated[i][j] = false;
		}
	}
}

void spreadS(int a, int b) {
	if (!visited[a][b] && !isRock[a][b] && !isWater[a][b]) {
		visited[a][b] = true;
		survived[a][b] = true;
		isUpdated[a][b] = true;
	}
	if (isGoal[a][b]) {
		isDone = true;
	}
}

void checkSide(int a, int b) {
	if (a > 0) {
		spreadS(a - 1, b);
	}
	if (a < R-1) {
		spreadS(a + 1, b);
	}
	if (b > 0) {
		spreadS(a, b - 1);
	}
	if (b < C - 1) {
		spreadS(a, b + 1);
	}
}

void moveS() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (survived[i][j] && !isUpdated[i][j]) {
				checkSide(i, j);
			}
		}
	}
}

void spreadWater(int a, int b) {
	if (!isRock[a][b] && !isGoal[a][b] &&!isWater[a][b]) {
		isWater[a][b] = true;
		survived[a][b] = false;
		isWaterUpdated[a][b] = true;
	}
}

void moveWater() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (isWater[i][j] && !isWaterUpdated[i][j]) {
				if (i > 0) {
					spreadWater(i - 1, j);
				}
				if (i < R - 1) {
					spreadWater(i + 1, j);
				}
				if (j > 0) {
					spreadWater(i, j - 1);
				}
				if (j < C - 1) {
					spreadWater(i, j + 1);
				}
			}
			
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			visited[i][j] = false;
			survived[i][j] = false;
			isWater[i][j] = false;
			isRock[i][j] = false;
			isGoal[i][j] = false;
		}
	}
	char temp;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> temp;
			if (temp == '.') {}
			else if (temp == '*') {
				isWater[i][j] = true;
			}
			else if (temp == 'X') {
				isRock[i][j] = true;
			}
			else if (temp == 'S') {
				visited[i][j] = true;
				survived[i][j] = true;
			}
			else if (temp == 'D') {
				isGoal[i][j] = true;
			}
		}
	}
	int cnt = 0;
	while (true) {

		resetUpdate();
		resetWaterUpdate();

		moveS();
		moveWater();

		cnt++;
		if (isDone) {
			cout << cnt;
			break;
		}
		if (cnt == 1000) {
			cout << "KAKTUS";
			break;
		}
	}
	
	return 0;
}