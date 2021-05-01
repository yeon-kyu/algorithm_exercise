#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M, K;
int color[51];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	N = 0;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> color[i];
		N += color[i];
	}
	cin >> K;

	double answer = 0.0;
	for (int i = 0; i < M; i++) {
		double temp = 1.0;
		for (int j = 0; j < K; j++) {
			temp = temp * (color[i] - j) / (N - j);
		}

		answer += temp;
	}
	cout.precision(9);
	cout << answer;


	return 0;
}