#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
int A[101];
int op[4];

int mini = 1000000001;
int maxi = -1000000001;

void get_result(vector<int> v) {
	int size = v.size();

	int ans = A[0];
	for (int i = 0; i < size; i++) {
		if (v[i] == 0) {
			ans += A[i + 1];
		}
		else if (v[i] == 1) {
			ans -= A[i + 1];
		}
		else if (v[i] == 2) {
			ans *= A[i + 1];
		}
		else if (v[i] == 3) {
			ans /= A[i+1];
		}
	}

	mini = min(mini, ans);
	maxi = max(maxi, ans);
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	cin >> op[0] >> op[1] >> op[2] >> op[3];

	vector<int> v1;
	for (int i = 0; i < op[0]; i++) {
		v1.push_back(0);
	}
	for (int i = 0; i < op[1]; i++) {
		v1.push_back(1);
	}
	for (int i = 0; i < op[2]; i++) {
		v1.push_back(2);
	}
	for (int i = 0; i < op[3]; i++) {
		v1.push_back(3);
	}

	get_result(v1);
	while (next_permutation(v1.begin(), v1.end())) {
		get_result(v1);
	}

	cout << maxi << endl;
	cout << mini << endl;
}