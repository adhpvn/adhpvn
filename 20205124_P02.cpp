#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    // Ma trận kề của đồ thị
    vector<vector<int>> g(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;
    }

    // Đọc thông tin các cạnh
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }

    // Đọc tập R
    int k;
    cin >> k;
    vector<int> r(k);
    for (int i = 0; i < k; i++) {
        cin >> r[i];
    }

    // Tính toán tất cả các tập con của tập R
    vector<vector<int>> subsets;
    for (int i = 0; i < (1 << k); i++) {
        vector<int> subset;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                subset.push_back(r[j]);
            }
        }
        subsets.push_back(subset);
    }

    // Tìm cây Steiner nhỏ nhất cho mỗi tập con của tập R
    int ans = INF;
    for (vector<int>& subset : subsets) {
        if (subset.empty()) continue;

        // Tạo đồ thị mới chỉ chứa các đỉnh trong tập con
        int m2 = subset.size();
        vector<vector<int>> g2(m2 + 1, vector<int>(m2 + 1, INF));
        for (int i = 1; i <= m2; i++) {
            g2[i][i] = 0;
        }
        for (int i = 0; i < m2; i++) {
            for (int j = i + 1; j < m2;
        j++) {
            int u = subset[i], v = subset[j];
            g2[i + 1][j + 1] = g2[j + 1][i + 1] = g[u][v];
        }

        // Tìm cây Steiner nhỏ nhất trong đồ thị con mới tạo
        vector<int> dist(m2 + 1, INF);
        vector<bool> vis(m2 + 1, false);
        dist[1] = 0;
        for (int i = 1; i <= m2; i++) {
            int u = -1;
            for (int j = 1; j <= m2; j++) {
                if (!vis[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }
            vis[u] = true;
            for (int v = 1; v <= m2; v++) {
                dist[v] = min(dist[v], dist[u] + g2[u][v]);
            }
        }
        int sum = 0;
        // Cập nhật kết quả
        for (int v : subset) {
            sum += dist[find(subset.begin(), subset.end(), v) - subset.begin() + 1];
        }
        ans = min(ans, sum);
    }
}

cout << ans << endl;

return 0;
}