#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int solve()
{
    int a[1001];
    int n;
    int k;
    int A, B;
    cin >> n;
    cin >> k;
    cin >> A >> B;
    int count = 0, sum = 0;
    if (A > B){
        cout << "0" << endl;
    }
    for (int i = 0; i < n ; i++){
        cin >> a[i];
    }
    for (int i = 0; i < k ; i++)
    {
        sum += a[i];
    }
    if (sum >= A && sum <= B ) count++;
    for (int i = k; i < n ; i++){
        sum  = sum - a[i-k] + a[i];
        if (sum >= A && sum <= B ) count++;
        //cout << sum << endl;
    }
   cout << count << endl;

}
int main()
{
    solve();
}