#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
int num[101];

int maxi;

void brute(int pos,int cnt, int val) {
	cnt++;
	if (cnt == 3) {
		int temp = val + num[pos];
		if (temp > maxi && temp<=M) {
			maxi = temp;
			//cout << temp<< " "<<pos<<endl;
		}
		//cout << temp << " " << pos << endl;
		if(pos+1<N)
			brute(pos + 1, cnt - 1, val);
	}
	
	else if (pos + 1 < N) {
		brute(pos + 1, cnt - 1, val);
		brute(pos + 1, cnt, val + num[pos]);
	}
}

int main() {
	
	cin >> N >> M; // N < 100, M<300 000
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	//시간 복잡도 : 100 * 99 * 98 O(n^3)

	maxi = 0;

	brute(0, 0, 0);
	for (int i = 0; i <= N - 3; i++) {
		//brute(i,0,0);
	}
	cout << maxi;

}