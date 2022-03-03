#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> extract110(string str) {
	vector<string> v;
	string x110 = "";

	int lastIdx = 0;
	while (true) {
		bool exitFlag = true;
		int size = str.size();
		for (int i = lastIdx; i<size - 2; i++) {
			if (str[i] == '1' && str[i + 1] == '1' && str[i + 2] == '0') {
				str.erase(i, 3);
				x110 += "110";
				lastIdx = i - 2;
				if (lastIdx<0) {
					lastIdx = 0;
				}
				exitFlag = false;
				break;
			}
		}
		if (exitFlag == true) {
			break;
		}
	}
	v.push_back(str);
	v.push_back(x110);
	return v;
}

string getSmallest(string str) {
	vector<string> extracted = extract110(str);
	string remain = extracted[0];
	string x110 = extracted[1];

	bool frontFlag = true;

	int size = remain.size();
	for (int i = 0; i<size; i++) {
		if (remain[size - 1 - i] == '0') {
			remain.insert(size - i, x110);
			frontFlag = false;
			break;
		}
	}

	if (frontFlag == true) {
		remain.insert(0, x110);
	}

	return remain;
}

vector<string> solution(vector<string> s) {
	vector<string> answer;

	for (string str : s) {
		answer.push_back(getSmallest(str));
	}
	return answer;
}