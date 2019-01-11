#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s, t;
    int count = 0;
    cin >> s; cin >> t;
    for(int i = 0; i < n; i++){
        int k = t[i] - s[i];
        if(k < 0) k+= 26;
        while( k != 0){
            if(k >= 13){
                k -= 13;
            }else{
                k--;
            }
            count++;
        }
    }
    cout << count << endl;
}
