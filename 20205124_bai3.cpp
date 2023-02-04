#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, k, m, a[N], ans;

void dfs(int i, int sum, int cnt) {
  if (sum == m && cnt == k) {
    ans++;
    return;
  }
  if (sum > m || cnt > k || i == n) return;
  dfs(i + 1, sum + a[i], cnt + 1);
  dfs(i + 1, sum, cnt);
}

int main() {
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  dfs(0, 0, 0);
  cout << ans << endl;
  return 0;
}
