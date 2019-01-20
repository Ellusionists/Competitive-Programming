#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int test; cin >> test;
	for(int i = 0; i < test; i++){
	    int n, m; cin >> n >> m;
	    if(n%2){
	        if(m%2)
	            cout << "NO" << endl;
	        else
	            cout << "YES" << endl;
	    }
	    else
	        cout << "YES" << endl;
	}
}

