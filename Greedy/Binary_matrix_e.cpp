#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    string a, b;
    cin >> a;
    int num, max = 0, ans = 1;
    for(int i = 1; i < n; i++)
    {
        cin >> b;
        if( b > a ){
            a = b;
            ans = i + 1;
        }
    }
    cout << ans << endl;
}
