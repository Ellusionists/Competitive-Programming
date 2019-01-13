#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int w; cin >> w;
    int ikey, ivalue;
    map <int, int> mm;
    map <int, int>::iterator it;
    for(int i = 0; i < n; i++){
        cin >> ikey >> ivalue;
        mm[ivalue] = ikey;
    }
    // sort(mm.begin(), mm.end());
    int count = 0;
    for(it = mm.begin(); it != mm.end(); it++){
        if(count + it->first <= w){
            count += it->first;
            cout << it->second << " ";
        }
    }
}