#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
	string answer = number;
	int rest = 0;
	for (int i = 0; i < k; i++) {
		bool flag = false;
		for (int j = 0; j < answer.size()-1; j++) {
			if (answer[j] < answer[j + 1]) {
				answer.erase(answer.begin() + j);
				flag = true;
				break;
			}
		}
		if (flag == false) {
			rest++;
		}
	}
	//answer.size() - rest //Á¤´äÀÇ size
	
	answer.erase(answer.size() - rest, answer.size() - 1);
	

	return answer;
}

