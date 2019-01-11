#include <iostream>
using namespace std;

int main() {
    int tc; cin >> tc;
    int in, wake, open;
    int n, t1, t2;
    int start, end;
    int returnTime, selectTime;
    while(tc--){
        // %%%%% INPUT %%%%%%
        cin >> n;
        scanf("%d:%d", &t1, &t2); in = t1 * 60 + t2; 
        scanf("%d:%d", &t1, &t2); wake = t1 * 60 + t2;
        scanf("%d:%d", &t1, &t2); open = t1 * 60 + t2;
        cin >> returnTime >> selectTime;
        int ansIndex = -1, minTime = -1;
        for(int i = 0; i < n; i++){
            
            scanf("%d:%d", &t1, &t2); start = t1 * 60 + t2;
            //  CASE 1. 
            int time1 = max(open, wake + returnTime) + selectTime + returnTime;
            if(time1 < in && time1 < start){
                if(minTime == -1 || minTime > time1){
                    minTime = time1;
                    ansIndex = i + 1;
                }
            }
            // CASE 2.
            scanf("%d:%d", &t1, &t2); end = t1 * 60 + t2;
            int time2 = max(open, max(end, wake) + returnTime)+ selectTime + returnTime;
            if(time2 < in){
                if(minTime == -1 || minTime > time2){
                    minTime = time2;
                    ansIndex = i + 1;
                }
            }
        }
        // // %%%%% LOGIC %%%%%
        // int ans = -1;
        // int minback = 9999;
        // int tback = 0;
        // for(int i = 0; i < n; i++){
            
        //     if(p + r < a){
        //         if(a + r + s < h1[i]){
        //             if(a + r + s < x){
        //                 tback = a+r+s;
        //                 if(tback < minback){
        //                     minback = tback;
        //                     ans = i;
        //                 }
        //             }
        //         }
        //     } 
            
        // }
        
    
        cout << "Case " << (tc+1) <<": " << (ansIndex) << endl;
    }
}
