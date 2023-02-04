#include <iostream>
#include <queue>
using namespace std;

int main() {
int n;
cin >> n;
priority_queue<int> q;
string operation;
while (cin >> operation && operation != "*") {
if (operation == "insert") {
int x;
cin >> x;
q.push(x);
} else if (operation == "delete-max") {
cout << q.top() << endl;
q.pop();
}
}
return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n, m;
// vector<int> nums;

// void insert(int x) {
// nums.push_back(x);
// push_heap(nums.begin(), nums.end());
// }

// int delete_max() {
// int max_num = nums.front();
// pop_heap(nums.begin(), nums.end());
// nums.pop_back();
// return max_num;
// }

// int main() {
// cin >> n;
// int x;
// for (int i = 0; i < n; i++) {
// cin >> x;
// insert(x);
// }
// string operation;
// while (cin >> operation && operation != "*") {
// if (operation == "insert") {
// cin >> x;
// insert(x);
// } else {
// cout << delete_max() << endl;
// }
// }
// return 0;
// }