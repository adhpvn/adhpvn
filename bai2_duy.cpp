#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int INF = 1e9;

int n, m, k;
int c[N + 5][N + 5];
int dp[1 << N][N + 5][N + 5];

int main() {
    ios_base::
    for (int i = 0; i < (1 << k); i++) {
    for (int j = 1; j <= n; j++) {
        for (int p = 1; p <= n; p++) {
            dp[i][j][p] = INF;
        }
    }
}

for (int i = 1; i <= n; i++) {
    dp[(1 << (i - 1))][i][i] = 0;
}

for (int mask = 0; mask < (1 << k); mask++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[mask][i][j] == INF) continue;
            for (int p = 1; p <= n; p++) {
                if (mask & (1 << (p - 1))) continue;
                dp[mask | (1 << (p - 1))][i][p] = min(dp[mask | (1 << (p - 1))][i][p], dp[mask][i][j] + c[j][p]);
            }
        }
    }
}

int ans = INF;
for (int i = 1; i <= n; i++) {
    if (!(mask & (1 << (i - 1)))) continue;
    for (int j = 1; j <= n; j++) {
        if (!(mask & (1 << (j - 1)))) continue;
        ans = min(ans, dp[mask][i][j]);
    }
}

cout << ans << endl;

return 0;
}