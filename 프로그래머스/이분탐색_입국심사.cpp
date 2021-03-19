#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

long long solution(int n, vector<int> times) {
	unsigned long long answer = 0;

	unsigned long long size = times.size();

	unsigned long long low = 1;
	unsigned long long high = *max_element(times.begin(), times.end()) * n;
	unsigned long long mid;
	unsigned long long cnt;
	answer = LLONG_MAX;
	while (low <= high) {
		mid = (low + high) / 2;
		cnt = 0;
		for (int i = 0; i < size; i++) {
			cnt += mid / times[i];
		}

		if (cnt >= n) {
			answer = min(answer, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		//cout << low <<" "<<high<<" "<<mid<<" "<<answer<< endl;
	}
	return answer;
}
