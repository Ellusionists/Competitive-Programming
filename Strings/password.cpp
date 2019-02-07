#include <iostream>
#include <vector>
using namespace std;

bool check_palindrome(string a, string b) {
	int length = a.length();
	for (int i = 0; i < length; ++i)
	{
		if(a[i] != b[length - i - 1])
			return false;
	}
	return true;
}

int main()
{
	int total = 0; cin >> total;
	string inp;
	bool f = false;
	std::vector<string> v;
	for (int i = 0; i < total; ++i)
	{
		cin >> inp;
		v.push_back(inp);
	}
	for(int i = 0; i < total; ++i) {
		for(int j = 0; j < total; ++j) {
			if (v[i].length() == v[j].length()) {
				f = check_palindrome(v[i], v[j]);
				if(f) {
					cout << v[i].length() <<" "<< v[i][(v[i].length()/2)] << endl;
					return 0;
				}
			}
		}
	}

	return 0;
}