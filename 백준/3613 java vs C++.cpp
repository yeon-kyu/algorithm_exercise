#include <iostream>
#include<string>

using namespace std;

void cToj(string name) {
	int len = name.size();
	char c;

	if (name[0]<'a' || name[0]>'z') {//첫 문자가 소문자가 아니면
		cout << "Error!";
		return;
	}

	for (int i = 0; i < len; i++) {
		c = name[i];
		if (c == '_') {
			char newC = name[i + 1] - 32; //'_' 뒤의 문자를 대문자로 바꿈

			if (newC<'A' || newC>'Z') { //연속으로 __가 나왔을경우
				cout << "Error!";
				return;
			}

			string temp = "a";
			temp[0] = newC;
			name.replace(i, 2, temp);
			len--; //글자수가 줄어들었으므로
		}
		else if (c<'a' || c>'z') { //c++에선 '_'가 아니고선 소문자를 벗어날 수 없음
			cout << "Error!";
			return;
		}


	}
	cout << name;
	/*if (name == "longAndMnemonicIdentifier") {
	cout << "일치";
	}*/
}
void jToc(string name) {
	int len = name.size();
	char c;

	if (name[0]<'a' || name[0]>'z') {//첫 문자가 소문자가 아니면
		cout << "Error!";
		return;
	}
	for (int i = 0; i < len; i++) {
		c = name[i];
		if (c >= 'A'&&c <= 'Z') {
			c = c + 32; //소문자로 바꿔줌
			string temp = "ab";
			temp[0] = '_';
			temp[1] = c;
			name.replace(i, 1, temp);
			len++; //글자수가 늘어났으므로
		}
		else if (c == '_') { //java에선 '_'가 있을 수 없음
			cout << "Error!";
			return;
		}
	}
	cout << name;
	/*if (name == "long_and_mnemonic_identifier") {
	cout << "일치2";
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
		else if (c<'a' || c>'z') { // '_'도 아니고 대문자도 아닌데 소문자도 아님
			cout << "Error!";
			changed = true;
			break;
		}

	}
	if (!changed) { //모든 글자가 소문자(c++,java둘다 됨)
		cout << name;
	}
}