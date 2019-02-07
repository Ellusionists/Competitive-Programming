#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	int test; cin >> test;
	set<char> s;
	string inp;
	int size = 0;

	while(test--) {
		long long int total = 1;
		cin >> inp;
		for (int i = 0; i < inp.length(); ++i)
		{	
			if(inp[i] == 'a' || inp[i] == 'e' || inp[i] == 'i' || inp[i] == 'o' || inp[i] == 'u') {
				s.insert(inp[i]);
			}
			if(inp[i] == '_') {
				size = s.size();
				total *= size;
			}
		}
		s.clear();
		cout << total << endl;
	}
}