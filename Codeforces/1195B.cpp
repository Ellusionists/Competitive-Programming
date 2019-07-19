#include <iostream>
using namespace std;

int main(){
	long long int n, k, total = 0;
	cin >> n >> k;

	for(int i = 1; i <= n; i++){
		total += i;
		if((total-k) == (n-i)){
			cout << (n-i) << endl;
			return 0;
		}
	}
	return 0;
}