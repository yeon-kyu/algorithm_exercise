#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;


int ticketSize;
map<string, vector<string> > m;
vector<string> ans;
vector<vector<string>> ticket2;
bool checkNotUsed(string start, string dest) { //이 벡터에 있으면 안쓴거임
	for (auto it = ticket2.begin(); it != ticket2.end(); it++) {
		/*cout << "start : " << start << ", dest : " << dest << endl;
		cout << (*it)[0] << ' ' << (*it)[1] << endl;*/
		if ( (*it)[0] == start && (*it)[1] == dest) {
			ticket2.erase(it);
			return true;
		}
	}
	return false;
}

bool doDFS(string str, int cnt) {
	cnt++;
	if (cnt == ticketSize) {
		ans.push_back(str);
		
		return true;
	}
	int s = m[str].size();
	for (int i = 0; i < s; i++) {
		/*cout << str << "에서" << m[str][i] << "가는 티켓 사용" << endl;*/
		if (checkNotUsed(str, m[str][i])) {//사용하지 않은 티켓인 경우
			bool flag =  doDFS(m[str][i], cnt);
			ticket2.push_back({ str, m[str][i] });

			if (flag == true) {
				ans.push_back(str);
				return true;
			}
		}
	}
	return false;
}
bool compare(string a, string b) {
	return a < b;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	ticket2 = tickets;
	ticketSize = tickets.size();
	for (int i = 0; i<ticketSize; i++) {
		m[tickets[i][0]].push_back(tickets[i][1]);
	}
	for (auto it = m.begin(); it != m.end();it++) {
		//m["icn"].begin();
		sort(it->second.begin(),it->second.end(),compare);

		/*int s = it->second.size();
		for (int i = 0; i < s; i++) {
			cout << it->first << ' ' << it->second[i];
			cout << ' ';
		}
		cout << endl;*/
	}
	
	doDFS("ICN",-1);
	for (int i = ans.size() - 1; i >= 0; i--) {
		answer.push_back(ans[i]);
	}
	
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solution({ {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} });

}