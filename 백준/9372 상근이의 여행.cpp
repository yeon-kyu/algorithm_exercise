#include <string>
#include <vector>
#include <iostream>

using namespace std;

int T;
int N, M;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//가장 적은 종류의 비행기를 타고 여행

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		int a, b;
		for (int j = 0; j < M; j++) {
			cin >> a >> b;
		}
		cout << N - 1 << '\n';
	}
	return 0;
}