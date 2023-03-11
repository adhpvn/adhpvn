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
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (graph[u][v] != 0 && !visited[v] && graph[u][v] < dist[v]) {
                    dist[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }

        int totalCost = 0;
        for (int i : R) {
            int u = i;
            while (u != -1) {
                int v = parent[u];
                if (v != -1) {
                    totalCost += graph[u][v];
                }
                u = v;
            }
        }

        return totalCost;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Khởi tạo ma trận kề
        graph = new int[n][n];
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            int w = scanner.nextInt();
            graph[u][v] = w;
            graph[v][u] = w;
        }

        int k = scanner.nextInt();

        // Khởi tạo tập R
        R = new HashSet<>();
        for (int i = 0; i < k; i++) {
            R.add(scanner.nextInt() - 1);
        }

        int minCost = prim();
        System.out.println(minCost);
    }
}
