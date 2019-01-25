#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


vector <int> v[100002];
int level[100002];
int numlevel[500];
bool visited[100002];

void bfs(int s, int nodes) {
	queue <int> q;
	q.push(s);
	level[s] = 0;
	visited[s] = true;
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		for(int i = 0; i < v[p].size(); i++) {
			if(visited[v[p][i]] == false) {
				level[v[p][i]] = level[p] + 1;
				numlevel[level[p] + 1]++;
				q.push(v[p][i]);
				visited[v[p][i]] = true;
			} 
		}
	}
}

int main() {
	int nodes; cin >> nodes;
	int n1, n2;
	for(int i = 0; i < nodes - 1; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	int x; cin >> x;
	bfs(1, nodes);
	numlevel[0] = 1;
	cout << numlevel[x-1] << endl;
	return 0;
}
