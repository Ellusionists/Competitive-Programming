#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int test; cin >> test;
	string inp;
	string op;
	int size;
	set<char> s;
	set<char>::iterator itset;
	char d;
	s.insert('a'); s.insert('e'); s.insert('i'); s.insert('o'); s.insert('u'); s.insert('y');
	s.insert('A'); s.insert('E'); s.insert('I'); s.insert('O'); s.insert('U'); s.insert('Y');
	
	while(test--) {
		cin >> inp;
		op = "";
		size = inp.length();
		for (int i = 0; i < size; ++i)
		{
			d = inp[i];
			itset = s.find(d);
			if(itset == s.end()) {
				if(d <= 'Z' && d >= 'A') {
					d = d - 'Z' + 'z';
				}
				
				op.push_back('.');
				op.push_back(d);
			}
		}
		cout << op << endl;
	}
}