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

	brute(pos + 1, sum);//���� ��¥ ���� ���Ҷ�

	if (pos + table[pos].t <= N) {
		brute(pos + table[pos].t, sum + table[pos].p);//���� ��¥ �����Ҷ�
	}

}

int main() {

	maxi = 0;
	cin >> N; //N<=15
	//brute force�� n������. n�� 1������ ����

	for (int i = 0; i < N; i++) {
		cin >> table[i].t >> table[i].p;
	}

	brute(0,0);
	cout << maxi;

}