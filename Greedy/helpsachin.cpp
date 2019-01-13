#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,i,k,b,j,q;
char str[1001];
scanf("%d",&t);
for(i=0;i<=t-1;i++){
    int count=0;
    getchar();
    scanf("%s",str);
    scanf("%d",&k);
    b=strlen(str);
    for(j=0;j<=b-k;j++){
        if(str[j]=='0'){
            for(q=j;q<=j+k-1;q++){
                if(str[q]=='1'){
                    str[q]='0';
                } else{
                    str[q]='1';
                }
            }
            count++;
        }
    }
    for(j=b-k+1;j<=b-1;j++){
        if(str[j]=='0'){
            count=-1;
            break;
        }
    }
    printf("%d\n",count);
    }
return 0;
}
