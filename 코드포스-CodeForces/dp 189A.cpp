#include <iostream>

using namespace std;

int D[5000] = {0}; // D[i] : optimal count for length i

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//n������ ����. �ڸ�������
	//�ڸ� ���� ���� ������ ���̴� a,b,c�� �ϳ���
	//�ڸ� ���� ���� ������ ���� �ִ밡 �Ǿ����
	//�Է� : n a b c
	//��� : �ִ� �������� ��
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	D[0] = 0;
	for (int i = 1; i <= n; i++) {
		
		int max = -1;
		if (i - a >= 0 && D[i-a] >=0 ) {
			if (D[i - a] >= 0) {
				max = D[i - a] + 1;
			}
		}
		if (i - b >= 0 && D[i-b] >= 0) {
			if (D[i - b] + 1 > max) {
				max = D[i - b] + 1;
			}
		}
		if (i - c >= 0 && D[i-c] >= 0) {
			if (D[i - c] + 1 > max) {
				max = D[i - c] + 1;
			}
		}
		D[i] = max;
	}
	cout << D[n];
	

}