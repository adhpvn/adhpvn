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

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> nums;

// void insert(int x) {
//     nums.push_back(x);
// }

// int deleteMax() {
//     int maxNum = *max_element(nums.begin(), nums.end());
//     nums.erase(remove(nums.begin(), nums.end(), maxNum), nums.end());
//     return maxNum;
// }

// int main() {
//     int n;
//     cin >> n;
//     int x;
//     for (int i = 0; i < n; i++) {
//         cin >> x;
//         insert(x);
//     }

//     string command;
//     while (cin >> command && command != "*") {
//         if (command == "delete-max") {
//             cout << deleteMax() << endl;
//         } else if (command == "insert") {
//             int x;
//             cin >> x;
//             insert(x);
//         }
//     }

//     return 0;
// }
