#include <iostream>
using namespace std;
typedef long long ll ;
ll dp1[100005];
ll dp2[100005];

int main(){
	ll n;
	cin >> n;
	ll arr1[n+1];
	ll arr2[n+1];
	for(int i = 1; i <= n; i++){
		cin >> arr1[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> arr2[i];
	}
	dp1[n] = arr1[n]; 
	dp2[n] = arr2[n]; 

	if(n >= 1){
		dp1[n-1] = dp2[n] + arr1[n-1];
		dp2[n-1] = dp1[n] + arr2[n-1];

		for(int i = n-2; i >= 1; i--){
			dp1[i] = arr1[i] + max(dp2[i+1], dp2[i+2]);
			dp2[i] = arr2[i] + max(dp1[i+1], dp1[i+2]);
		}
	}
	// cout << dp1[1] << " " << dp2[1] << endl;
	cout << max(dp1[1], dp2[1]) << endl;
}



