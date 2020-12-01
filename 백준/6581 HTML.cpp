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

	string line = ""; //현재 진행중인 줄에 대해 저장하는 변수
	string temp;
	while (cin>>temp) {

		int len = line.size(); //현재 줄의 글자 수

		if (temp == "<br>") {
			cout << "\n";
			line.clear();
			continue;
		}
		else if (temp == "<hr>") {
			if (len != 0) { //줄의 첫부분이 아니라면
				cout << "\n";
			}
			cout << hr << "\n";
			line.clear();
			continue;
		}

		if (len + temp.size() <= 80) { //80글자 이하라면
			//뒤에 갖다 붙인다
			if (len != 0) {
				line += " ";
				cout << " ";
			}
			line += temp;
			cout << temp;
		}
		else { //80글자를 초과한다면
			cout << "\n" << temp;
			line.clear();
			line = temp;
		}

	}

}