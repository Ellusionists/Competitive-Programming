#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    int temp1, temp2;
    vector<int> vertices[V];
    for(int i = 0; i < E; i++){
    	cin >> temp1 >> temp2;
    	vertices[temp1].push_back(temp2);
    	vertices[temp2].push_back(temp1);
    }

    queue<int> nodes;
    bool visited[V];

    for(int i = 0; i < V; i++){
    	visited[V] = false;
    }

    nodes.push(0);
    visited[0] = true;
    std::vector<int>::iterator it;

    while(!(nodes.empty())){
    	int top = nodes.front(); 
    	cout << top << " ";
    	nodes.pop();

    	for(it = vertices[top].begin(); it != vertices[top].end(); it++){
    		if(!visited[(*it)]){
    			visited[(*it)] = true;
    			nodes.push((*it));

    		}
    	}
    }
    // cout << endl;
	return 0;
}
