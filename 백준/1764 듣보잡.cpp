#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> hear;
	vector<string> see;
	vector<string> ans;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		hear.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		see.push_back(temp);
	}
	sort(hear.begin(), hear.end());
	//들은 것들을 알파벳순으로 따로 정렬..아마 o(nlogn)
	sort(see.begin(), see.end());
	//본것들을 알파벳순으로 따로 정렬
	int i = 0, j = 0;
	int h_size = hear.size();
	int s_size = see.size();
	//merge sort의 merging하는 방법과 비슷하게 해결
	while (i < h_size && j < s_size) {
		if (hear[i] == see[j]) {
			ans.push_back(hear[i]);
			i++; j++;
		}
		else if (hear[i]<see[j]) {
			i++;
		}
		else if (hear[i] > see[j]) {
			j++;
		}
	}
	int ans_size = ans.size();
	cout << ans_size << " ";
	for (int i = 0; i < ans_size; i++) {
		cout << ans[i] << " ";
	}

}