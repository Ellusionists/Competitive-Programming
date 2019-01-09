#include <bits/stdc++.h>
using namespace std;

int main() {
    int streets; cin >> streets;
    while(streets--)
    {
        int tmoney = 0;
        int blds, money;
        cin >> blds >> money;
        int count = 1; int maxh; int h;
        cin >> maxh;
        for(int i = 1; i < blds; i++)
        {
            cin >> h;
            if(h > maxh)
            {
                count++;
                maxh = h;
            }
        }
        tmoney += money * count;
        cout << tmoney << endl;
    }
}
