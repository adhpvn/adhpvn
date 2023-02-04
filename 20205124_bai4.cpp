#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100100;
int n,a[N];
int f[N][4];
int dp(int pos,int k){
    if(pos>n) return 0;
    int &res=f[pos][k];
    if(res!=-1) return res;
    res=dp(pos+1,0);
    if(k<2) res=max(res,dp(pos+1,k+1)+a[pos]);
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(f,-1,sizeof f);
    printf("%d\n",dp(1,0));
    return 0;
}
