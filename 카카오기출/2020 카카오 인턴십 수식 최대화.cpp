#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<long long> num;
vector<char> op;

long long answer = 0;

void splitOperatorAndOperand(string str) {
	int size = str.size();
	int startIdx = 0;
	for (int i = 0; i<size; i++) {
		char c = str[i];
		if (c == '-' || c == '+' || c == '*') {
			string numString = str.substr(startIdx, i - startIdx);
			startIdx = i + 1;
			num.push_back(stoll(numString));
			op.push_back(c);
		}
	}
	string numString = str.substr(startIdx, size - startIdx);
	num.push_back(stoi(numString));
}

void calcAnswer(vector<char> v) {
    vector<long long> num2 = num;
    vector<char> op2 = op;
    
	for (int i = 0; i<3; i++) {
		char c = v[i];
		int size = op2.size();
		for (int j = 0; j < size ; j++) {
			if (c == op2[j]) {
				op2.erase(op2.begin() + j); 
				long long a = num2[j];
				long long b = num2[j + 1];
				long long ret;
				if (c == '+') {
					ret = a + b;
				}
				else if (c == '-') {
					ret = a - b;
				}
				else if (c == '*') {
					ret = a * b;
				}
				num2[j] = ret;
				num2.erase(num2.begin() + j + 1);
                
                size--; 
                j--;
			}
		}
	}
	long long ans = num2[0];
	if (ans < 0) {
		ans = -ans;
    }
	answer = max(answer, ans);

}

void brute(vector<char> v) {
	if (v.size() == 3) {
		calcAnswer(v);
		return;
	}
	if (find(v.begin(), v.end(), '-') == v.end()) {
		vector<char> nv = v;
		nv.push_back('-');
		brute(nv);
	}
	if (find(v.begin(), v.end(), '+') == v.end()) {
		vector<char> nv = v;
		nv.push_back('+');
		brute(nv);
	}
	if (find(v.begin(), v.end(), '*') == v.end()) {
		vector<char> nv = v;
		nv.push_back('*');
		brute(nv);
	}
}

long long solution(string expression) {
	splitOperatorAndOperand(expression);

	vector<char> v;
	brute(v);

	return answer;
}