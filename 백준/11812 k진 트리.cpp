#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long N;
long long K, Q;

vector<long long> parent_array;

void getParentArray(long long a) {
	while (true) {
		if (a == 0) {
			break;
		}
		else {
			parent_array.push_back(a);
			a = (a + K - 2) / K;
		}
	}
	reverse(parent_array.begin(), parent_array.end());
}

long long getDistance(long long a, long long b) {
	parent_array.clear();
	getParentArray(a);
	vector<long long> a_parent = parent_array;
	
	parent_array.clear();
	getParentArray(b);
	vector<long long> b_parent = parent_array;

	int a_size = a_parent.size();
	int b_size = b_parent.size();

	int size;
	if (a_size > b_size) {
		size = b_size;
	}
	else {
		size = a_size;
	}
	int parent = -1;
	for (int i = 1; i < size; i++) {
		if (a_parent[i] != b_parent[i]) {
			parent = i;
			break;
		}
	}
	if (parent == -1) {
		parent = size;
	}

	int a_distance = a_size - parent;//a부터 parent까지 거리
	int b_distance = b_size - parent;//b부터 parent까지 거리

	return a_distance + b_distance;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> Q;

	long long a, b;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		if (K == 1) {
			cout << abs(a - b) << '\n';
		}
		else {
			cout << getDistance(a, b) << '\n';
		}
	}

	return 0;
}