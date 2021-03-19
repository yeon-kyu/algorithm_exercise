#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> node[201];
int visited[201] = { false };

void DFS(int pos) {
	int size = node[pos].size();
	visited[pos] = true;
	for (int i = 0; i<size; i++) {
		if (visited[node[pos][i]]==false)
			DFS(node[pos][i]);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j<n; j++) {
			if (computers[i][j] == 1) {
				node[i+1].push_back(j + 1);
			}
			//node[i].push_back(computers[i][j]);
		}
	}

	while (true) {
		int targetNode = -1;
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				//cout << i << "³ëµå Å½»ö µé¾î°©´Ï´Ù" << endl;
				targetNode = i;
				break;
			}
		}
		if (targetNode == -1) {
			break;
		}
		answer++;
		DFS(targetNode);
	}
	return answer;
}

int main() {

	cout<<solution(3, { {1,1,0},{1,1,0},{0,0,1} });


	return 0;
}