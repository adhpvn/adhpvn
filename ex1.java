import java.util.Scanner;

import java.util.Scanner;

public class ex1 {
    static int n, k, A, B;
    static int[] a;
    static int[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();
        a = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }
        dp = new int[n + 1][B + 1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= B; j++) {
                for (int l = 0; l <= k && l <= i; l++) {
                    if (j - l * a[i] >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - l][j - l * a[i]]) % 1000000007;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = A; i <= B; i++) {
            ans = (ans + dp[n][i]) % 1000000007;
        }
        System.out.println(ans);
    }
}
