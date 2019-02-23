#include <iostream>
// #include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	int test; cin >> test;
	while(test--) {
		int n; cin >> n;
		int attack[n];
		int defence[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> attack[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> defence[i];
		}
		int min = -1;
		for (int i = 0; i < n-1; ++i)
		{
			if( (attack[(i - 1 + n)%n ] + attack[(i+1)%n]) < defence[i]) {
				if(min < defence[i]){
					min = defence[i];
				}
			}
		}
		cout << min << endl;
	}
	return 0;
}

