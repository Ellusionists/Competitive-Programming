#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	int test; cin >> test;
	string input;
	set<char> allcharsofstrings;
	int n;
	char c;

	while(test--) {
		cin >> n;
		int answer = 0;
		int flag = 1;
		allcharsofstrings.clear();
		set<char> eachstring[n];
		for (int i = 0; i < n; ++i)
		{
			eachstring[i].clear();
			cin >> input;
			for (int j = 0; j < input.length(); ++j) {
				eachstring[i].insert(input[j]);
				allcharsofstrings.insert(input[j]);
			}
		}
		set<char>::iterator it;
		set<char>::iterator eachit;
		for(it = allcharsofstrings.begin(); it != allcharsofstrings.end(); it++) {
			flag = 1;
			c = *it;

			for(int i = 0; i < n; i++) {
				eachit = eachstring[i].find(c);
				if(eachit == eachstring[i].end()){
					flag = 0;
					break;

				}
			}

			if(flag)
				answer++;
		}

		cout << answer << endl;
	}
	return 0;
}