#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int test;
	cin >> test;
	while(test--){
		int n; cin >> n;
		int a[n];
		long int sum = 0;
		set<double>newset;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			sum += a[i];
			newset.insert(a[i]);
		}
		
		if(newset.size() == 1){
			cout << 1 << endl;
			continue;
		}

		double mean = sum * 1.0 / n;
		set<double>::iterator it;
		it = newset.find(mean);
		
		if(it != newset.end()){
			for(int z = 0; z < n; z++){
				if(*it == a[z]){
					cout << (z+1) << endl;
					break;
				}
			}
		}

		else{
			cout << "Impossible" << endl;
		}
	}
	return 0;
}