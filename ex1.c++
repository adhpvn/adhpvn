#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, A, B, count = 0;
    cin >> n >> k >> A >> B;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) sum += a[j];
        if (sum >= A && sum <= B) count++;
    }
    cout << count << endl;
    return 0;
}
