#include <bits/stdc++.h>
#include <stack>
using namespace std;


int main(){
    int nums; cin >> nums;
    int arr[nums];
    for(int i = 0; i < nums; i++){
        cin >> arr[nums - i - 1];
    }
    int max = arr[0];
    stack <int> s;
    s.push(max);
    for(int i = 1; i < nums; i++){
        if(arr[i] >= max){
            max = arr[i];
            s.push(max);
        }
    }

    while(!(s.empty()))
    {
        int k = s.top();
        cout << k << " ";
        s.pop();
    }
}

