#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> number;

bool checkConsistency(int n) {
	bool flag = true;
	for (int i = 0; i < n - 1; i++) {
		string a = number[i];
		string b = number[i + 1];


		int a_size = a.size();
		int b_size = b.size();
		if (a > b) {
			continue;
		}
		bool containFlag = true;
		for (int k = 0; k < a_size; k++) {
			if (a[k] == b[k]) {

			}
			else {
				containFlag = false;
				break;
			}
		}
		if (containFlag) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	int N;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N;
		string num;
		for (int j = 0; j < N; j++) {
			cin >> num;
			number.push_back(num);
		}
		sort(number.begin(), number.end());

		if (checkConsistency(N)) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

		number.clear();
	}



	return 0;
}