#include <iostream>
#include<string>

using namespace std;

void cToj(string name) {
	int len = name.size();
	char c;

	if (name[0]<'a' || name[0]>'z') {//ù ���ڰ� �ҹ��ڰ� �ƴϸ�
		cout << "Error!";
		return;
	}

	for (int i = 0; i < len; i++) {
		c = name[i];
		if (c == '_') {
			char newC = name[i + 1] - 32; //'_' ���� ���ڸ� �빮�ڷ� �ٲ�

			if (newC<'A' || newC>'Z') { //�������� __�� ���������
				cout << "Error!";
				return;
			}

			string temp = "a";
			temp[0] = newC;
			name.replace(i, 2, temp);
			len--; //���ڼ��� �پ������Ƿ�
		}
		else if (c<'a' || c>'z') { //c++���� '_'�� �ƴϰ� �ҹ��ڸ� ��� �� ����
			cout << "Error!";
			return;
		}


	}
	cout << name;
	/*if (name == "longAndMnemonicIdentifier") {
	cout << "��ġ";
	}*/
}
void jToc(string name) {
	int len = name.size();
	char c;

	if (name[0]<'a' || name[0]>'z') {//ù ���ڰ� �ҹ��ڰ� �ƴϸ�
		cout << "Error!";
		return;
	}
	for (int i = 0; i < len; i++) {
		c = name[i];
		if (c >= 'A'&&c <= 'Z') {
			c = c + 32; //�ҹ��ڷ� �ٲ���
			string temp = "ab";
			temp[0] = '_';
			temp[1] = c;
			name.replace(i, 1, temp);
			len++; //���ڼ��� �þ���Ƿ�
		}
		else if (c == '_') { //java���� '_'�� ���� �� ����
			cout << "Error!";
			return;
		}
	}
	cout << name;
	/*if (name == "long_and_mnemonic_identifier") {
	cout << "��ġ2";
	}*/
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string name;
	cin >> name;

	int len = name.size();
	bool changed = false;

	//A : 65, Z : 90, a : 97 z : 122

	for (int i = 0; i < len; i++) {
		char c = name[i];
		if (c == '_') {
			cToj(name);
			changed = true;
			break;
		}
		else if (c >= 'A' && c <= 'Z') {
			jToc(name);
			changed = true;
			break;
		}
		else if (c<'a' || c>'z') { // '_'�� �ƴϰ� �빮�ڵ� �ƴѵ� �ҹ��ڵ� �ƴ�
			cout << "Error!";
			changed = true;
			break;
		}

	}
	if (!changed) { //��� ���ڰ� �ҹ���(c++,java�Ѵ� ��)
		cout << name;
	}
}