#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[10001];


struct line_info {
	int a, b, c;
};
vector<line_info> line;

bool compare(struct line_info X, struct line_info Y) { 
	//line_info의 c를 기준으로 오름차순 정렬하자
	if (X.c < Y.c) {
		return true;
	}
	else {
		return false;
	}
}

int get_parent(int x) {
	int p = parent[x];
	if (p == x) {
		return x;
	}
	else {
		return parent[x] = get_parent(p);
	}
}

void union_parent(int x, int y) {
	int X = get_parent(x);
	int Y = get_parent(y);
	if (X < Y) { //작은 애를 바라보게
		parent[Y] = X;
	}
	else {
		parent[X] = Y;
	}
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;//v<=10000 E<=100000
	int A, B, C;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		
		struct line_info temp;
		temp.a = A; temp.b = B; temp.c = C;
		line.push_back(temp);
	}
	sort(line.begin(), line.end(), compare);
	
	for (int i = 1; i <= V; i++) { //parent초기화
		parent[i] = i;
	}

	//크루스컬
	int ans = 0;
	for (int i = 0; i < E; i++) { //v개의 노드가 있으므로 그만큼 반복
		int a = line[i].a;
		int b = line[i].b;
		//사이클 체크만 하면됨
		
		if (get_parent(a)==get_parent(b)) { //사이클인 경우	
			continue;
		}
		else {
			union_parent(a, b); //그래프 연결
			ans += line[i].c;
		}
	}
	cout << ans;
	
}
