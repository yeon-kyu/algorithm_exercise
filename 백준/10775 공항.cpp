#include <iostream>

using namespace std;

int parent[100001] = { 0 };



int find_parent(int temp) {
	if (parent[temp] < 1) { //��ŷ �Ұ����� ����
		return -1;
	}
	if (temp == parent[temp]) { //temp��尡 ���� ��ŷ�������� ����Ʈ�� ��� 
		parent[temp] = parent[temp] - 1; //���� ��带 ����Ű����
		return parent[temp];
	}
	else {
		return parent[temp] = find_parent(parent[temp]);
		//find_parent()�Լ��� ���ȣ����. 
		//find_parent�� ������� ���� temp�� ����Ű�� parent�� ���� ��带 �ٶ󺸰���(�ð� ����)
	}
}

int main() {
	int P, G;
	cin >> G >> P;
	int cnt = 0;
	int x;
	int result = 0;

	for (int i = 0; i <= G; i++) {
		parent[i] = i; //�ʱ�ȭ
	}

	for (int i = 0; i < P; i++) {
		cin >> x;

		if (find_parent(x) < 0) {
			break;
		}
		cnt++;
	}


	cout << cnt << endl;

}