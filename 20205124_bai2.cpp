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
