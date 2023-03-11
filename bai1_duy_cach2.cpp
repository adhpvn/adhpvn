#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

class Citizen {
public:
    string code;
    string dob;
    string fatherCode;
    string motherCode;
    bool isAlive;
    string regionCode;

    Citizen(string _code, string _dob, string _fatherCode, string _motherCode, bool _isAlive, string _regionCode) {
        code = _code;
        dob = _dob;
        fatherCode = _fatherCode;
        motherCode = _motherCode;
        isAlive = _isAlive;
        regionCode = _regionCode;
    }
};

vector<Citizen> citizens;

void readInput() {
    string line;
    getline(cin, line);
    while (getline(cin, line)) {
        if (line == "*") {
            break;
        }
        string code = line.substr(0, 7);
        string dob = line.substr(8, 10);
        string fatherCode = line.substr(19, 7);
        string motherCode = line.substr(27, 7);
        bool isAlive = (line[35] == 'Y');
        string regionCode = line.substr(37, 2);
        citizens.push_back(Citizen(code, dob, fatherCode, motherCode, isAlive, regionCode));
    }
}

int numberOfPeople() {
    return citizens.size();
}

int numberOfPeopleBornAt(string date) {
    int count = 0;
    for (Citizen c : citizens) {
        if (c.dob == date) {
            count++;
        }
    }
    return count;
}

int dfs(string code, map<string, vector<string>>& graph, map<string, int>& depths) {
    if (graph.count(code) == 0) {
        return 0;
    }
    int maxDepth = 0;
    for (string parentCode : graph[code]) {
        if (depths.count(parentCode) == 0) {
            depths[parentCode] = dfs(parentCode, graph, depths) + 1;
        }
        maxDepth = max(maxDepth, depths[parentCode]);
    }
    return maxDepth;
}

int mostAliveAncestor(string code) {
    map<string, vector<string>> graph;
    for (Citizen c : citizens) {
        if (c.code != code) {
            if (c.fatherCode != "0000000") {
                graph[c.code].push_back(c.fatherCode);
            }
            if
        (c.motherCode != "0000000") {
            graph[c.code].push_back(c.motherCode);
        }
    }
}
map<string, int> depths;
depths[code] = 0;
int maxDepth = dfs(code, graph, depths);
int aliveCount = 0;
string mostAliveAncestorCode = "";
for (auto const& [ancestorCode, depth] : depths) {
    for (Citizen c : citizens) {
        if (c.code == ancestorCode && c.isAlive) {
            aliveCount++;
        }
    }
    if (depth == maxDepth && aliveCount > 0 && (mostAliveAncestorCode == "" || aliveCount > count)) {
        mostAliveAncestorCode = ancestorCode;
        count = aliveCount;
    }
    aliveCount = 0;
}
return stoi(mostAliveAncestorCode);
}
int main() {
readInput();
string command;
while (cin >> command) {
if (command == "number_of_people") {
cout << numberOfPeople() << endl;
} else if (command == "number_of_people_born_at") {
string date;
cin >> date;
cout << numberOfPeopleBornAt(date) << endl;
} else if (command == "most_alive_ancestor") {
string code;
cin >> code;
cout << mostAliveAncestor(code) << endl;
}
}
return 0;
}