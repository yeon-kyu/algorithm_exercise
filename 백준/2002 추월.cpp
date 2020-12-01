#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N; //1000����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//N���� ����̰� ���� ������ȣ ���
	//N���� �����̰� ���� ������ȣ ���
	//������ȣ : 6����~8������ ��������
	//��� : �ݵ�� ����� ���� ������ �������� ���� ��
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
		if (temp == inCar.front()) {//���� �������
			inCar.erase(inCar.begin());
		}
		else { //�߿��� ��������
			vector<string>::iterator it;
			it = find(inCar.begin(), inCar.end(), temp);
			inCar.erase(it);
			cnt++;
		}
	}
	cout << cnt;

}