#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	int size = phone_book.size();
	for (int i = 0; i<size; i++) {
		string temp = phone_book[i];
		int s = temp.size(); //Á¢µÎ»ç
		for (int j = 0; j<size; j++) {
			if (i == j) {
				continue;
			}
			if (phone_book[j].size()<s) {
				continue;
			}
			if (phone_book[j].substr(0, s) == temp) {
				return  false;
			}
		}
	}

	return answer;
}