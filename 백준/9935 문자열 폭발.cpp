#include <iostream>
#include <string>
#include <vector>

using namespace std;

string full_string, fire;
int fsize;
vector<char> ans;

void find_extra() { //full_string�� ũ�Ⱑ �ʹ� ũ�� ũ�Ⱑ ����ans ���͸� �̿��Ͽ� �ذ�
	int full_size = full_string.size();
	for (int i = 0; i < full_size; i++) { //full_string ���� ����ŭ �ݺ�(100����)
		ans.push_back(full_string[i]);
		if (ans.back() == fire[fsize - 1]) {//������ ���ڰ� ������
			bool flag = true;
			int a_size = ans.size();
			for (int j = 1; j < fsize; j++) {//������ ���ڵ鵵 ������ Ȯ��
				if (ans[a_size - j - 1] != fire[fsize - 1 - j]) {
					flag = false;
					break;
				}
			}
			if (flag) { //ã���� ���߹��ڿ� ũ�⸸ŭ ans���� ����
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