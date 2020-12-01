#include <iostream>

using namespace std;

int D[5000] = {0}; // D[i] : optimal count for length i

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//n길이의 리본. 자를려고함
	//자른 후의 리본 조각의 길이는 a,b,c중 하나임
	//자른 후의 리본 조각의 수는 최대가 되어야함
	//입력 : n a b c
	//출력 : 최대 리본조각 수
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	D[0] = 0;
	for (int i = 1; i <= n; i++) {
		
		int max = -1;
		if (i - a >= 0 && D[i-a] >=0 ) {
			if (D[i - a] >= 0) {
				max = D[i - a] + 1;
			}
		}
		if (i - b >= 0 && D[i-b] >= 0) {
			if (D[i - b] + 1 > max) {
				max = D[i - b] + 1;
			}
		}
		if (i - c >= 0 && D[i-c] >= 0) {
			if (D[i - c] + 1 > max) {
				max = D[i - c] + 1;
			}
		}
		D[i] = max;
	}
	cout << D[n];
	

}