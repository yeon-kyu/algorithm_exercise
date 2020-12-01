#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string hr;
	for (int i = 0; i < 80; i++) {
		hr += "-";
	}

	string line = ""; //���� �������� �ٿ� ���� �����ϴ� ����
	string temp;
	while (cin>>temp) {

		int len = line.size(); //���� ���� ���� ��

		if (temp == "<br>") {
			cout << "\n";
			line.clear();
			continue;
		}
		else if (temp == "<hr>") {
			if (len != 0) { //���� ù�κ��� �ƴ϶��
				cout << "\n";
			}
			cout << hr << "\n";
			line.clear();
			continue;
		}

		if (len + temp.size() <= 80) { //80���� ���϶��
			//�ڿ� ���� ���δ�
			if (len != 0) {
				line += " ";
				cout << " ";
			}
			line += temp;
			cout << temp;
		}
		else { //80���ڸ� �ʰ��Ѵٸ�
			cout << "\n" << temp;
			line.clear();
			line = temp;
		}

	}

}