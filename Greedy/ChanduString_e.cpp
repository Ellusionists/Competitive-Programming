#include <iostream>
#include <string>
using namespace std;

int main(){
    int test; cin >> test;
    while(test--) {
        string s; cin >> s;
        string newstr;
        char current = s[0];
        newstr.push_back(current);
        for (int i = 1; i < s.length(); ++i)
        {
        	if(current != s[i]) {
        		current = s[i];
        		newstr.push_back(current);
        	}
        }
    	cout << newstr << endl;
    }
}