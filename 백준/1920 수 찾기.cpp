#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[100001];

int find(int tar) {
	int start = 0;
	int end = N - 1;
	int mid;
	while (end >= start) {
		mid = (start + end) / 2;

		if (A[mid] == tar) {
			return 1;
		}
		else if (A[mid] > tar) {
			end = mid - 1;
		}
		else if (A[mid] < tar) {
			start = mid + 1;
		}
	}
	return 0;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A+N);

	cin >> M;
	int temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		cout << find(temp)<<'\n';
	}

	return 0;
}