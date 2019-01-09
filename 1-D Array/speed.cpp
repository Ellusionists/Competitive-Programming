#include <bits/stdc++.h>
using namespace std;

int main(){
    int test; cin >> test;
    while(test--){
        int n; cin >> n;
        int cars[n];
        for(int i = 0; i < n; i++){
            cin >> cars[i];
        }
        int max = cars[0];
        int count = 0;
        for(int i = 0; i < n; i++){
            if(cars[i] <= max){
                max = cars[i];
                count++;
            }
        }
        cout << count << endl;
    }
}
