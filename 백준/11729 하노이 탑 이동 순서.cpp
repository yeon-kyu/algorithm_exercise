#include <iostream>

using namespace std;

void f(int start, int dest, int mid, int n) {
	//n���� ������ start���� dest�� �ű��
	if (n == 1) { 
		cout << start << ' ' << dest << '\n';
	}
	else { 
		f(start, mid, dest, n - 1); //start����n-1���� mid�� �ű��
		cout << start << ' ' << dest << '\n'; //�ǾƷ��� �ű��
		f(mid, dest, start, n - 1); //mid�� n-1���� dest�� �ű��
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
