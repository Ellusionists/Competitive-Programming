#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// void dfs_iterative(int source) {
// 	stack <int> s;
// 	int top;
// 	visited[source] = true;
// 	s.push(source);
// 	while(!s.empty()) {
// 		top = s.top(); s.pop();
// 		for(int i = 0; i < v[top].size(); i++) {
// 			if(visited[v[top][i]] == false) {
// 				s.push(visited[top][i]);
// 				visited[top][i] = true;
// 			}
// 		}
	
// 	}
// }

void dfs_recursive(vector<int> v[], int source, bool visited[]) {
	visited[source] = true;
	for(int i = 0; i < v[source].size(); ++i) {
		if(visited[v[source][i]] == false) {
			dfs_recursive(v ,v[source][i], visited);
		}
	}

}

int main(int argc, char const *argv[])
{
	int n, edge; cin >> n >> edge;
	vector <int> adj[n+1];
	bool visited[n+1];
	for (int i = 0; i <= n; ++i)
	{
		visited[i] = false;
	}
	int n1, n2;
	for (int i = 0; i < edge; ++i)
	{
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}
	int unreachable = 0;
	int start; cin >> start;
	dfs_recursive(adj, start, visited);
	for(int i = 0; i <= n; i++) {
		if( visited[i] == false ) {
			unreachable++;	
		}
	}
	cout << unreachable - 1 << endl;
	return 0;
}
