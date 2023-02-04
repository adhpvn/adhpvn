#include <bits/stdc++.h> 
using namespace std; 
  
priority_queue<int> pq; 
  
int main() 
{ 
    int n, x; 
    cin >> n; 
  
    for (int i = 0; i < n; i++) { 
        cin >> x; 
        pq.push(x); 
    } 
  
    string operation; 
    while (cin >> operation && operation != "*") { 
        if (operation == "insert") { 
            cin >> x; 
            pq.push(x); 
        } 
        else if (operation == "delete-max") { 
            cout << pq.top() << endl; 
            pq.pop(); 
        } 
    } 
    return 0; 
} 