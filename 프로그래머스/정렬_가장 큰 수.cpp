#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int get_pos(int num) {// 예를 들어 123을 넣으면 1000이 나옴
	if (num == 0) {
		return 10;
	}
	return (int)pow(10, (int)log10(num) + 1);
}

bool compare(int a, int b) {
	int x = a * get_pos(b) + b;
	int y = b * get_pos(a) + a;

	return x < y;
}

string solution(vector<int> numbers) {
	string answer = "";


	sort(numbers.begin(), numbers.end(), compare);

	int s = numbers.size();
	
	if (numbers[s - 1] == 0) {
		answer = to_string(0);
		return answer;
	}

	for (int i = s - 1; i >= 0; i--) {
		answer += to_string(numbers[i]);
	}

	return answer;
}