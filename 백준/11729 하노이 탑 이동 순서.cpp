#include <iostream>

using namespace std;

void f(int start, int dest, int mid, int n) {
	//n개의 원판을 start에서 dest로 옮기기
	if (n == 1) { 
		cout << start << ' ' << dest << '\n';
	}
	else { 
		f(start, mid, dest, n - 1); //start위의n-1개를 mid에 옮기기
		cout << start << ' ' << dest << '\n'; //맨아랫거 옮기기
		f(mid, dest, start, n - 1); //mid의 n-1개를 dest에 옮기기
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int a[21];
	cin >> N;

	a[1] = 1;
	for (int i = 2; i <= N; i++) {
		a[i] = 2 * a[i - 1] + 1;
	}
	cout << a[N] << '\n';

	f(1, 3, 2, N);
}
