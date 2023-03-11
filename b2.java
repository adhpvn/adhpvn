import java.util.*;

public class SteinerTree {
    static final int INF = Integer.MAX_VALUE; // Số vô cực
    static int[][] graph; // Ma trận kề của đồ thị
    static int[] dist; // Mảng lưu khoảng cách từ cây đến các đỉnh chưa xét
    static boolean[] visited; // Mảng đánh dấu các đỉnh đã xét
    static int[] parent; // Mảng lưu cha của mỗi đỉnh trong cây Steiner
    static Set<Integer> R; // Tập R

    static int prim() {
        int n = graph.length;
        dist = new int[n];
        visited = new boolean[n];
        parent = new int[n];
        Arrays.fill(dist, INF);
        Arrays.fill(visited, false);
        Arrays.fill(parent, -1);

        int start = R.iterator().next();
        dist[start] = 0;

        for (int i = 0; i < n - 1; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }
            visited[u] = true; // Cập nhật khoảng cách đến các đỉnh chưa xét
            for (int j = 0; j < n; j++) {
                if (!visited[j] && graph[u][j] != INF && graph[u][j] < dist[j]) {
                    dist[j] = graph[u][j];
                    parent[j] = u;
                }
            }
        }

        int sum = 0;
        for (int v : R) {
            if (parent[v] != -1) {
                sum += dist[v];
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        graph = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(graph[i], INF);
        }
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            int w = sc.nextInt();
            graph[u][v] = w;
            graph[v][u] = w;
        }
        int k = sc.nextInt();
        R = new HashSet<>();
        for (int i = 0; i < k; i++) {
            int v = sc.nextInt() - 1;
            R.add(v);
        }
        int ans = prim();
        System.out.println(ans);
    }
