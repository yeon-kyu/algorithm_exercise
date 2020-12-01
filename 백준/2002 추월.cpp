#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N; //1000이하

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//N개의 대근이가 적은 차량번호 목록
	//N개의 영식이가 적은 차량번호 목록
	//차량번호 : 6글자~8글자의 영문숫자
	//출력 : 반드시 출력을 했을 것으로 여겨지는 차의 수
	cin >> N;
	vector<string> inCar;
	vector<string> outCar;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		inCar.push_back(temp);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		if (temp == inCar.front()) {//옳은 순서라면
			inCar.erase(inCar.begin());
		}
		else { //추월이 생긴경우라면
			vector<string>::iterator it;
			it = find(inCar.begin(), inCar.end(), temp);
			inCar.erase(it);
			cnt++;
		}
	}
	cout << cnt;

}