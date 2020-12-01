#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class loc {
public:
	int x;
	int y;
	char d;
	
	bool operator == (const loc& a)const {
		if (x == a.x && y == a.y && d == a.d) return true;
		else return false;
	}

};

int solution(string dirs) {
	int answer = 0;

	loc cur;
	loc temp;
	cur.x = 0; cur.y = 0;

	int cnt = 0;
	vector<class loc> v;
	vector<class loc>::iterator it;
	int s = dirs.size();
	//cout << "s : " << s << endl;
	for (int i = 0; i < s; i++) {
		char dir = dirs[i];
		//cout << i << " : ";
		bool plus = true;
		if (dirs[i] == 'R') {
			cur.x++; cur.d = 'l';
			if (cur.x > 5) {
				plus = false; cur.x--;
			}
			else {
				it = find(v.begin(), v.end(), cur);
				if (it == v.end()) { //기존에 없는경우=> 추가
					v.push_back(cur);
					temp = cur;
					temp.x--; temp.d = 'r';
					v.push_back(temp);
				}
				else plus = false;
			}
		}
		else if (dirs[i] == 'L') {
			cur.x--; cur.d = 'r';
			if (cur.x < -5) { plus = false; cur.x++; }
			else {
				it = find(v.begin(), v.end(), cur);
				if (it == v.end()) { //기존에 없는경우=> 추가
					v.push_back(cur);
					temp = cur;
					temp.x++; temp.d = 'l';
					v.push_back(temp);
				}
				else {
					plus = false; cout << cur.x << ' ' << cur.y << ' ' << cur.d <<' '<<dir<< endl;
					//cout << it->x << ' ' << it->y << ' ' << cur.d << endl;
				}
			}
		}
		else if (dirs[i] == 'D') {
			cur.y--; cur.d = 'u';
			if (cur.y < -5) { plus = false;  cur.y++; }
			else {
				it = find(v.begin(), v.end(), cur);
				if (it == v.end()) { //기존에 없는경우=> 추가
					v.push_back(cur);
					temp = cur;
					temp.y++; temp.d = 'd';
					v.push_back(temp);
				}
				else plus = false;
			}
		}
		else if (dirs[i] == 'U') {
			cur.y++; cur.d = 'd';
			if (cur.y > 5) { plus = false; cur.y--; }
			else {
				it = find(v.begin(), v.end(), cur);
				if (it == v.end()) { //기존에 없는경우=> 추가
					v.push_back(cur);
					temp = cur;
					temp.y--; temp.d = 'u';
					v.push_back(temp);
				}
				else plus = false;
			}
		}
		
		if (plus) {
			answer++;
			/*cout << i <<' '<< dir << endl;
			for (auto it2 = v.begin(); it2 != v.end(); it2++) {
				cout << '(' << it2->x << ',' << it2->y << ',' << it2->d << ')';
			}cout << endl;*/
		}
	
	}

	cout << "ans : ";
	return answer;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<< solution("ULURRDLLU");
	
}