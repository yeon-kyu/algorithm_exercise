#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long ans = 0;
int n, k;
vector<int> tree[200001];

struct node {
	int num; //��� ��ȣ
	int child_cnt; //�ڽ� ��
	int parent_cnt; //���� ��(��Ʈ���� �Ÿ�)
	int greedy;
	bool travel_city = 0; //���൵���̸� 1
};
vector<struct node> v_node;

void get_tree(int v, int parent) { //�θ� ���� ���� ���� tree�� ����(tree)
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
		//�̹� set_child_cnt�� �� ���
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
	//cout << v << " �� parent_cnt : " << cnt << endl;
	cnt++;
	int s = tree[v].size();
	for (int i = 0; i < s; i++) {
		set_parent_cnt(tree[v][i], cnt);
	}
}


bool compare1(struct node A, struct node B) {
	return A.greedy < B.greedy;//��������
}
bool compare2(struct node A, struct node B) {
	return A.num < B.num;
}

void count_happiness(int v,int t_cnt) {//dfs�� Ž���ϸ� happiness ���

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

	//n���� ����, n-1���� ����� ����
	//�� ���ô� 1~n���� ��ȣ�� ����
	//1�� ���ô� ������
	//k���� ���ø� ����-> ��� ����
	// ������ ���ô� ��������
	// ��������� envoy�� �ų� �ִܰŸ��� ������ ������
	//envoy�� �ູ�� ���� ���� �������� ���� ������
	//��� envoy�� �ູ�� ���� �ִ밡 �ǵ��� k ���ø� �����ؾ���
	
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
	for (int i = 1; i <= n; i++) { //�� ��帶�� �ڽļ� ���ϱ�
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

	sort(v_node.begin(), v_node.end(),compare1);//greedy�� ��������

	for (int i = 0; i < t_city; i++) { //���൵�� ����
		v_node[i].travel_city = 1;
	}
	sort(v_node.begin(), v_node.end(), compare2);//�ٽ� ��� ��ȣ ������ ����

	count_happiness(1,0);
	printf("%lld", ans);
	//cout << ans;
}