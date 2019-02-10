#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	long int test; cin >> test;
	long long int answer = 0;
	long long int n, a, b, k; 
	long long int lcm;

	while(test--){
		cin >> n >> a >> b >> k;		
		answer = 0;
		answer += (n/a);
		answer += (n/b);
		lcm = (a*b)/__gcd(a,b);
		answer -= ((n/lcm)*2);
	
		if(answer >= k) 
			cout << "Win" << endl;
		else 
			cout << "Lose" << endl;
	}
	return 0;
}