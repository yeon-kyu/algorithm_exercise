#include <iostream>


using namespace std;


int main() {

	int n;
	cin >> n;

	int *x = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		if (i < 100) {
			x[i] = i;
		}
		else {
			int a = i / 100;
			int b = (i - a * 100) / 10;
			int c = i % 10;
			//cout << "x : " << a << " " << b << " " << c << endl;
			if (2 * b == a + c) {
				x[i] = x[i - 1] + 1;
			}
			else {
				x[i] = x[i - 1];
			}
		}
	}
	cout << x[n] << endl;
}