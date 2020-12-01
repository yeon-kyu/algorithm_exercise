#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int maxx = 0;
bool alpha[26] = { false };
vector<char> v[50]; //anta�� tica�� ������ ���ڵ鸸 ������


void push_extra() { //�ܾ �Է¹ް� �ߺ��Ǵ� �ܾ�� a,n,t,i,c�� �����Ͽ� v�� ����
	string words[50];
	for (int i = 0; i < n; i++) {
		cin >> words[i];
		int len = words[i].size();
		words[i].erase(len - 4, 4);
		words[i].erase(0, 4);
		
		int new_len = words[i].size();
		vector<char>::iterator it;
		for (int j = 0; j < new_len; j++) {
			char c = words[i][j]; //c : ���� ���� �ܾ��� �ش� ����
			if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') {
				continue;
			}

			it = find(v[i].begin(), v[i].end(), c);
			if (it == v[i].end()) { //�ش� ���ڰ� ���°Ÿ�
				v[i].push_back(words[i][j]);
			}
		}
	}
}

void countwords() { //���� �ִ� �ִ� �ܾ� ���

	int cnt = 0;

	for (int i = 0; i < n; i++) {//�� �ܾ�鿡 ����
		bool possible = true;
		int size = v[i].size();
		for (int j = 0; j < size; j++) { //�� �ܾ��� ���ڵ鿡 ����
			if (alpha[v[i][j] - 'a'] == false) {//�ϳ��� ���ŷ� �ܿ������ �ܾ��
				possible = false;
			}
		}
		if (possible == true) {
			cnt++;
		}
	}

	//cout << cnt << endl;
	if (cnt > maxx) {
		maxx = cnt;
	}
}

void check_all_alphabet(int cnt,int cur) {
	
	if (cnt == k) { //���ĺ� ���� k��ŭ ������-> ���� �ִ� �ִ�ܾ� ���
		countwords();
		return;
	}
	else { //���ĺ��� �� ������ϸ�
		for (int i = cur; i < 26; i++) { //���� �� ���� �����ִ� ���ĺ�(cur)������ ���ĺ��� ����
			if (alpha[i] == false) { //���ĺ��� ������ ���� ���� �ʾҴٸ�
				alpha[i] = true;
				check_all_alphabet(cnt + 1, i); //��ͷ� �����ϴ� ���ĺ����� �־������� ����
				alpha[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> k;

	if (k < 5) {
		cout << 0 << " ";
		return 0;
	}
	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;

	push_extra();
	k -= 5;
	check_all_alphabet(0,0);
	cout << maxx;
}