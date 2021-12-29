#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	int size = prices.size();
	for (int i = 0; i < size-1; i++) {
		int price = prices[i];
		int cnt = 1;
		for (int j = i + 1; j < size-1; j++) {
			int next = prices[j];
			if (price <= next) {
				cnt++;
			}
			else {
				break;
			}
		}
		answer.push_back(cnt);
	}
    answer.push_back(0);

	return answer;
}