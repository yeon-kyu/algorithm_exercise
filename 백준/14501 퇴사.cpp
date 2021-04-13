#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
struct Table {
	int t;
	int p;
};
Table table[16];
int maxi;

void brute(int pos,int sum) {

	if (pos >= N) {
		maxi = max(maxi, sum);
		return;
	}

	brute(pos + 1, sum);//현재 날짜 선택 안할때

	if (pos + table[pos].t <= N) {
		brute(pos + table[pos].t, sum + table[pos].p);//현재 날짜 선택할때
	}

}

int main() {

	maxi = 0;
	cin >> N; //N<=15
	//brute force는 n제곱임. n이 1만까지 가능

	for (int i = 0; i < N; i++) {
		cin >> table[i].t >> table[i].p;
	}

	brute(0,0);
	cout << maxi;

}