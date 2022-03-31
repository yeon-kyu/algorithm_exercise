#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int N;
vector<int> pizzaA;
vector<int> pizzaB;

int sumA[2000001];
int sumB[2000001];

void init() {
	int a, b;
	cin >>  N >> a >> b;

	for (int i = 0; i < a; i++) {
		int temp;
		cin >> temp;
		pizzaA.push_back(temp);
	}
	for (int i = 0; i < b; i++) {
		int temp;
		cin >> temp;
		pizzaB.push_back(temp);
	}

	for (int i = 0; i < 2000001; i++) {
		sumA[i] = 0;
		sumB[i] = 0;
	}
}

void calcSum() {
	int size = pizzaA.size();
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int k = 0; k < size - 1; k++) {
			int curIndex = (i + k) % size;
			sum += pizzaA[curIndex];
			sumA[sum]++;
		}
	}
	int a = 0;
	for (int i = 0; i < size; i++) {
		a += pizzaA[i];
	}
	sumA[0] = 1;
	sumA[a] = 1;

	size = pizzaB.size();
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int k = 0; k < size - 1; k++) {
			int curIndex = (i + k) % size;
			sum += pizzaB[curIndex];
			sumB[sum]++;
		}
	}

	int b = 0;
	for (int i = 0; i < size; i++) {
		b += pizzaB[i];
	}
	sumB[0] = 1;
	sumB[b] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 피자 개수 m, n <= 1000
	// 피자조각의 크기 <= 1000

	init();
	calcSum();

	int answer = 0;
	for (int i = 0; i <= N; i++) {
		answer += sumA[i] * sumB[N - i];
	}
	cout << answer;
}