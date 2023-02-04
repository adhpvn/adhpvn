#include <bits/stdc++.h>
using namespace std;

const int N=100100;
int n, a[N], f[N];

int main()
{
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++)
    {
        f[i]=a[i];
        if (i>=1) f[i]=max(f[i], f[i-1]);
        if (i>=2) f[i]=max(f[i], f[i-2]+a[i]);
        if (i>=3) f[i]=max(f[i], f[i-3]+a[i-1]+a[i]);
    }
    cout << f[n-1] << endl;
    return 0;
}
