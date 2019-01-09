#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int lsize; cin >> lsize;
    int a[lsize], b[lsize];
    int c[lsize]; memset(c, 0, sizeof(c));
    for(int j = 0; j < lsize; j++){
        cin >> a[j];
    }
    for(int j = 0; j < lsize; j++){
        cin >> b[j];
    }
    int count = 0;
    for(int i = 0; i < lsize; i++){
        for(int j = i; j < lsize; j++){
            if(a[j] > a[i]){
                c[i]++;
            }
        }
    }
    for(int i = 0; i < lsize; i++){
        for(int j = 0; j < lsize; j++){
            if(b[j] > a[i]){
                count += c[i];
            }
        }
    }
    cout << count << endl;
}
