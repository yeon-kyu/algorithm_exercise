#include <iostream>
#include <string>
#include <vector>

using namespace std;

string full_string, fire;
int fsize;
vector<char> ans;

void find_extra() { //full_string은 크기가 너무 크니 크기가 작은ans 벡터를 이용하여 해결
	int full_size = full_string.size();
	for (int i = 0; i < full_size; i++) { //full_string 글자 수만큼 반복(100만번)
		ans.push_back(full_string[i]);
		if (ans.back() == fire[fsize - 1]) {//마지막 글자가 같으면
			bool flag = true;
			int a_size = ans.size();
			for (int j = 1; j < fsize; j++) {//나머지 글자들도 같은지 확인
				if (ans[a_size - j - 1] != fire[fsize - 1 - j]) {
					flag = false;
					break;
				}
			}
			if (flag) { //찾으면 폭발문자열 크기만큼 ans에서 제거
				for (int j = 0; j < fsize; j++) {
					ans.pop_back();
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> full_string >> fire;
	fsize = fire.size();

	find_extra();

	int s = ans.size();
	if (s == 0) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < s; i++) {
			cout << ans[i];
		}
	}

}