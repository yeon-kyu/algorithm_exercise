#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;

void print_vector(vector<int> v) {
	int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << v[i]<<' ';
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	vector<int> v;

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	
	print_vector(v);
	while (next_permutation(v.begin(), v.end())) {
		print_vector(v);
	}
}