#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<string> v;
map<char, int> m;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//N���� �ܾ�. �빮�ڷθ�
	//�� ���ĺ� �빮�ڸ� 0���� 9������ ���ڷ� �ٲ� N���� ���� ���ϴ� ����
	
	int answer = 0;

	cin >> N;
	for(int i=0;i<N;i++){
		string temp;
		cin >> temp;
		v.push_back(temp);

		for (int j = 0; j < temp.size(); j++) {
			auto it = m.find(temp[j]);
			if (it == m.end()) {
				m[temp[j]] = pow(10, temp.size() - j - 1);
			}
			else {
				it->second = it->second + pow(10, temp.size() - j - 1);
			}
		}
	}
	
	int multiple = 9;
	int m_size = m.size();
	for (int i = 0; i < m_size; i++) {
		int cur_max = 0;
		auto max_it = m.begin();
		for (auto it = m.begin(); it != m.end(); it++) {
			if (cur_max < it->second) {
				max_it = it;
				cur_max = it->second;
			}
		}
		answer += cur_max * multiple;
		m.erase(max_it);

		multiple--;
	}
	cout << answer;

	return 0;
}