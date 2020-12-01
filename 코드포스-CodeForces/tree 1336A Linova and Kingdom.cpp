#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long ans = 0;
int n, k;
vector<int> tree[200001];

struct node {
	int num; //노드 번호
	int child_cnt; //자식 수
	int parent_cnt; //조상 수(루트까지 거리)
	int greedy;
	bool travel_city = 0; //여행도시이면 1
};
vector<struct node> v_node;

void get_tree(int v, int parent) { //부모를 지워 단일 방향 tree로 만듬(tree)
	vector<int>::iterator it = find(tree[v].begin(), tree[v].end(), parent);
	if(it != tree[v].end())
		tree[v].erase(it);
	int s = tree[v].size();
	//cout << v << endl;
	for (int i = 0; i < s; i++) {
		get_tree(tree[v][i], v);
	}
}

void set_child_cnt(int v) {
	if (tree[v].size() == 0) {
		v_node[v - 1].child_cnt = 1;
	}
	else if (v_node[v - 1].child_cnt > 0) { 
		//이미 set_child_cnt가 된 경우
		return;
	}
	else {
		int cnt = 1;
		for (int i = 0; i < tree[v].size(); i++) {
			if (v_node[tree[v][i] - 1].child_cnt == -1) {
				set_child_cnt(tree[v][i]);
			}
			cnt += v_node[tree[v][i] - 1].child_cnt;
		}
		v_node[v - 1].child_cnt = cnt;
	}

}
void set_parent_cnt(int v, int cnt) { //bfs
	v_node[v - 1].parent_cnt = cnt;
	//cout << v << " 의 parent_cnt : " << cnt << endl;
	cnt++;
	int s = tree[v].size();
	for (int i = 0; i < s; i++) {
		set_parent_cnt(tree[v][i], cnt);
	}
}


bool compare1(struct node A, struct node B) {
	return A.greedy < B.greedy;//오름차순
}
bool compare2(struct node A, struct node B) {
	return A.num < B.num;
}

void count_happiness(int v,int t_cnt) {//dfs로 탐색하며 happiness 계산

	if (v_node[v-1].travel_city == 1) {
		//cout << v << endl;
		t_cnt++;
	}
	else {
		ans += t_cnt;
	}
	
	int s = tree[v].size();
	for (int i = 0; i < s; i++) {
		count_happiness(tree[v][i], t_cnt);
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//n개의 도시, n-1개의 양방향 도로
	//각 도시는 1~n으로 번호가 있음
	//1번 도시는 수도임
	//k개의 도시를 선택-> 산업 도시
	// 나머지 도시는 관광도시
	// 산업도시의 envoy는 매년 최단거리로 수도로 가야함
	//envoy의 행복은 가는 길의 관광도시 수와 동일함
	//모든 envoy의 행복의 합이 최대가 되도록 k 도시를 선택해야함
	
	scanf("%d%d",&n,&k);
	//cin >> n >> k;
	int u, v;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		//cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	int t_city = n - k;

	get_tree(1,0);
	node temp;
	for (int i = 1; i <= n; i++) { //각 노드마다 자식수 구하기
		//cout<<get_child_cnt(i)<<endl;
		temp.num = i;
		temp.child_cnt = -1; //get_child_cnt(i);
		//temp.parent_cnt;
		v_node.push_back(temp);
	}
	for (int i = 1; i <= n; i++) {
		set_child_cnt(i);
	}
	set_parent_cnt(1,0);

	for (int i = 0; i < n; i++) {
		v_node[i].greedy = v_node[i].parent_cnt - v_node[i].child_cnt;
	}

	sort(v_node.begin(), v_node.end(),compare1);//greedy의 오름차순

	for (int i = 0; i < t_city; i++) { //여행도시 지정
		v_node[i].travel_city = 1;
	}
	sort(v_node.begin(), v_node.end(), compare2);//다시 노드 번호 순으로 정렬

	count_happiness(1,0);
	printf("%lld", ans);
	//cout << ans;
}