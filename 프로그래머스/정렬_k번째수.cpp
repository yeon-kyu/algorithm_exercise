#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int get_num(vector<int> array, vector<int> command) {
	int array_size = array.size();
	vector<int> temp;

	for (int i = 0; i < array_size; i++) {
		if (i + 1 >= command[0] && i + 1 <= command[1]) {
			temp.push_back(array[i]);
		}
	}
	sort(temp.begin(), temp.end());

	return temp[command[2] - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	int s = commands.size();



	for (int i = 0; i<s; i++) {
		int temp = get_num(array, commands[i]);
		cout << "°á°ú : " << temp << endl;
		answer.push_back(temp);
	}


	return answer;
}