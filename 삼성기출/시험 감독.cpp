#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;
int A[1000001];
int B;// B : 총감독관이 감시할 수 있는 응시자 수
int C; // C : 부감독관이 감시할 수 있는 응시자 수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		int sub = A[i] - B;
		if (sub <= 0) {
			continue;
		}
		sub = ceil((double)sub / C);
		answer += sub;
	}
	answer += N;
	cout << answer;
}