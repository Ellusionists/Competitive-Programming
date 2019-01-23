#include <iostream>
using namespace std;

int main()
{
	long int test; cin >> test;
	while(test--) {
		long int n; cin >> n;
		long int costofpetrol[n], l[n];
		long int minpetcost = 999999, mincostindex = 0;
		long int journeycost = 0;
		// memset(costofpetrol, 0, sizeof(costofpetrol));
		// memset(l, 0, sizeof(l));
		for (long int i = 0; i < n; ++i) {
			cin >> costofpetrol[i];
			if(costofpetrol[i] < minpetcost) {
				minpetcost = costofpetrol[i];
				mincostindex = i;
			}
		}
		for (long int i = 0; i < n; ++i) {
			cin >> l[i];
		}
		for (long int i = mincostindex; i < n; ++i) {
			journeycost += minpetcost * l[i];
		}
		long int initialcost = costofpetrol[0];
		for ( i = 0; i < mincostindex; ++i) {
			journeycost += initialcost * l[i];
			if(costofpetrol[i] < initialcost) {
				journeycost -= initialcost * l[i];
				initialcost = costofpetrol[i];
				journeycost += initialcost * l[i];
			}
			// cout << journeycost << " " << i << endl;
		}
		cout << journeycost << endl;

	}
	return 0;
}