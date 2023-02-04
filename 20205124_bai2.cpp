#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;

void insert(int x) {
    nums.push_back(x);
}

int deleteMax() {
    int maxNum = *max_element(nums.begin(), nums.end());
    nums.erase(remove(nums.begin(), nums.end(), maxNum), nums.end());
    return maxNum;
}

int main() {
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(x);
    }

    string command;
    while (cin >> command && command != "*") {
        if (command == "delete-max") {
            cout << deleteMax() << endl;
        } else if (command == "insert") {
            int x;
            cin >> x;
            insert(x);
        }
    }

    return 0;
}
