#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int cities, routes, changetime, flighttime;
	cin >> cities >> routes >> changetime >> flighttime;
	std::vector<int> graph[cities+1];

	int start, end;
	for(int i = 0; i < routes; i++) {
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	int prev[cities+1]; 
	bool visited[cities+1];

	for (int i = 0; i <= cities; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
		visited[i] = false;
		prev[i] = -1;
	}

	int source, destination;
	cin >> source >> destination;
	queue <int> q;
	q.push(source);
	visited[source] = true;
	int ttime, count = 1;

	while(!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i = 0; i < graph[p].size(); ++i){
			if(visited[graph[p][i]] == false) {
				visited[graph[p][i]] = true;
				prev[graph[p][i]] = p;
				q.push(graph[p][i]);
			}
		}
	}
	stack <int> st;
	int currentposition = destination;
	prev[source] = -1;
	while(prev[currentposition] != -1) {
		st.push(currentposition);
		currentposition = prev[currentposition];
		count++;
	}
	st.push(source);
	cout << count << endl;
	while(!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	return 0;

}