#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int mat[101];
int stuNum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 남학생 : 스위치 번호가 받은 수의 배수의 스위치들 상태 바꾼다.
	// 여학생 : 받은 수의 스위치를 중심으로 최대 좌우대칭 스위치들 상태를 바꾼다.

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> mat[i];
	}
	cin >> stuNum;
	for (int i = 0; i < stuNum; i++) {
		int gender; // 남학생 1, 여학생 2
		int number;
		cin >> gender >> number;
		number;

		if (gender == 1) {
			int target = number;
			while (target <= N) {
				mat[target] = !mat[target];
				target += number;
			}
		}
		else if (gender == 2) {
			int left = number;
			int right = number;
			while (true) {
				left--;
				right++;
				if (left <= 0 || right > N) {
					break;
				}
				if (mat[left] != mat[right]) {
					break;
				}
			}
			for (int k = left + 1; k < right; k++) {
				mat[k] = !mat[k];
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << mat[i];
		if (i % 20 == 0) {
			cout << "\n";
		}
		else {
			cout << ' ';
		}
	}
}