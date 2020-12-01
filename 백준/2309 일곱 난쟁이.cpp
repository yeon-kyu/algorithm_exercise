#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> find2(vector<int> v, int total) {
	for (vector<int>::iterator i = v.begin(); i <v.end(); i++) {
		for (vector<int>::iterator j = i + 1; j < v.end(); j++) {
			if (*i + *j == total) {
				v.erase(j);
				v.erase(i);
				return v;
			}
		}
	}
}

int main() {

	int total = 0;

	vector<int> dwarf;
	//vector<int>::iterator it;

	for (int i = 0; i< 9; i++) {
		int w;
		cin >> w;
		dwarf.push_back(w);
		total += w;

	}
	total -= 100;
	//이제 몸무게의 합이 total이 되는 2명을 선택한다.

	dwarf = find2(dwarf, total);

	sort(dwarf.begin(), dwarf.end());
	for (int i = 0; i < 7; i++) {
		cout << dwarf[i] << endl;
	}
}