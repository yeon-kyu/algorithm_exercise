#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
int num[101];

int maxi;

void brute(int pos, int cnt, int val) {
	if (cnt == 3) { //그 다음 노드 가기 직전에 검사한다
		if (val > maxi && val <= M) {
			maxi = val;
		}
		return;
	}
	if (cnt >= 4 || pos >= N || val>M) {
		return;
	}

	brute(pos + 1, cnt + 1, val + num[pos]);
	brute(pos + 1, cnt, val);
}

int main() {

	cin >> N >> M; // N < 100, M<300 000
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	//시간 복잡도 : 100 * 99 * 98 O(n^3)

	maxi = 0;

	brute(0, 0, 0);
	cout << maxi;

}