#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int matrix[101][101];
bool isGround[101][101];

int maxi = 0;

void resetGround() {
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			isGround[a][b] = false;
		}
	}
}

void deleteFriends(int a, int b) {
	isGround[a][b] = false;
	//����
	if (b > 0) {
		if (isGround[a][b - 1]) {
			deleteFriends(a, b - 1);
		}
	}
	//������
	if (b < N - 1) {
		if (isGround[a][b + 1]) {
			deleteFriends(a, b + 1);
		}
	}
	//��
	if (a > 0) {
		if (isGround[a - 1][b]) {
			deleteFriends(a - 1, b);
		}
	}

	//�Ʒ�
	if (a < N - 1) {
		if (isGround[a + 1][b]) {
			deleteFriends(a + 1, b);
		}
	}
}

void getSafeZone(int h) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] > h) {
				isGround[i][j] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (isGround[i][j]) {
				cnt++;
				deleteFriends(i, j);
			}

		}
	}
	maxi = max(maxi, cnt);

}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
	
	//�ð� ���⵵ : ����� ����� �� 100 * �ִ� ���� �� 10000 => 100��
	maxi = 0;

	for (int i = 1; i <= 100; i++) {
		resetGround();
		getSafeZone(i);
	}
	cout << maxi << endl;
}