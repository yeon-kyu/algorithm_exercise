#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int n;
int maxx = 0;
map<string, vector<string>> m;
string get_lower_case(string str) {
	int s = str.size();
	int gap = 'A' - 'a';
	for (int i = 0; i < s; i++) {
		if (str[i] >= 'A'&&str[i] <= 'Z') {
			str[i] = str[i] - gap;
		}
	}
	//cout << str;
	return str;
}
void doDFS(string str, int cnt) {
	cnt++;
	int s = m[str].size();
	for (int i = 0; i < s; i++) {
		doDFS(m[str][i],cnt);
	}
	if (s == 0) {
		if (cnt > maxx) {
			maxx = cnt;
		}
	}
	
}

int main() {
	//name1 reposted name2
	//name1 : reposter , name2 : name1에게 전달해줬던 사람
	//가장 큰 repost chain의 길이를 구하라.

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	string child, parent, garbage;
	
	for (int i = 0; i < n; i++) {
		cin >> child >> garbage >> parent;
		get_lower_case(child);
		get_lower_case(parent);
		m[get_lower_case(parent)].push_back(get_lower_case(child));

	}
	//cout << m["polycarp"].size();
	doDFS("polycarp",0);
	cout << maxx;
}