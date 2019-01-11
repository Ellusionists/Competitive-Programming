#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[100001];
    memset(arr, 0, sizeof(arr));
    int n; scanf("%d", &n);
    int k;
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        arr[k]++;
    }
    int q; scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &k);
        if(arr[k] == 0)
            printf("NOT PRESENT\n");
        else
            printf("%d\n", arr[k]);
    }
    return 0;
}
