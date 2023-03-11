#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MAX_DATE = 1000000000;

struct Person {
    string code;
    int date_of_birth;
    string father_code;
    string mother_code;
    bool is_alive;
    string region_code;
    int depth;
    vector<Person*> children;
    Person(string code, int date_of_birth, string father_code, string mother_code, bool is_alive, string region_code)
        : code(code), date_of_birth(date_of_birth), father_code(father_code), mother_code(mother_code), is_alive(is_alive), region_code(region_code), depth(-1) {}
};

int n;
Person* people[N];
map<string, int> code_to_id;

int calc_depth(Person* person) {
    if (person->depth != -1) return person->depth;
    if (person->father_code == "0000000" && person->mother_code == "0000000") return person->depth = 0;
    if (!code_to_id.count(person->father_code) || !code_to_id.count(person->mother_code)) return person->depth = -1;
    Person* father = people[code_to_id[person->father_code]];
    Person* mother = people[code_to_id[person->mother_code]];
    int father_depth = calc_depth(father), mother_depth = calc_depth(mother);
    if (father_depth == -1 || mother_depth == -1) return person->depth = -1;
    return person->depth = max(father_depth, mother_depth) + 1;
}

void query_number_people() {
    cout << n << endl;
}

void query_number_people_born_at(int date) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (people[i]->date_of_birth == date) cnt++;
    }
    cout << cnt << endl;
}

void query_most_alive_ancestor(string code) {
    if (!code_to_id.count(code)) {
        cout << "-1" << endl;
        return;
    }
    Person* person = people[code_to_id[code]];
    int depth = calc_depth(person);
    cout << depth << endl;
}

void query_number_people_born_between(int from_date, int to_date) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (people[i]->date_of_birth >= from_date && people[i]->date_of_birth <= to_date) cnt++;
    }
    cout << cnt << endl;
}

void dfs(Person* person, vector<Person*>& group) {
if (person->is_alive) group.push_back(person);
for (auto child : person->children) {
dfs(child, group);
}
}

void query_most_living_descendants(string code) {
if (!code_to_id.count(code)) {
cout << "-1" << endl;
return;
}
Person* person = people[code_to_id[code]];
vector<Person*> descendants;
dfs(person, descendants);
int max_depth = 0, max_count = 0;
for (auto descendant : descendants) {
int depth = calc_depth(descendant);
if (depth == -1) continue;
if (depth > max_depth) {
max_depth = depth;
max_count = 1;
} else if (depth == max_depth) {
max_count++;
}
}
cout << max_count << endl;
}

void query_number_people_in_region(string region_code) {
int cnt = 0;
for (int i = 1; i <= n; i++) {
if (people[i]->region_code == region_code) cnt++;
}
cout << cnt << endl;
}

void query_number_people_alive_at(int date) {
int cnt = 0;
for (int i = 1; i <= n; i++) {
if (people[i]->is_alive && people[i]->date_of_birth <= date && (people[i]->date_of_birth + MAX_DATE) >= date) cnt++;
}
cout << cnt << endl;
}

int main() {
cin >> n;
for (int i = 1; i <= n; i++) {
string code, father_code, mother_code, region_code;
int date_of_birth;
bool is_alive;
cin >> code >> date_of_birth >> father_code >> mother_code >> is_alive >> region_code;
people[i] = new Person(code, date_of_birth, father_code, mother_code, is_alive, region_code);
code_to_id[code] = i;
if (father_code != "0000000") {
people[code_to_id[father_code]]->children.push_back(people[i]);
}
if (mother_code != "0000000") {
people[code_to_id[mother_code]]->children.push_back(people[i]);
}
}

int q;
cin >> q;
while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
        int date;
        cin >> date;
        query_number_people_born_at(date);
    } else if (type == 2) {
        string code;
        cin >> code;
        query_most_alive_ancestor(code);
    } else if (type == 3) {
        int from_date, to_date;
        cin >> from_date >> to_date;
        query_number_people_born_between(from_date, to_date);
    } else if (type == 4) {
        string code;
        cin >> code;
        query_most_living_descendants(code);
    } else if (type == 5) {
        string region_code;
        cin >> region_code;
        query_number_people_in_region(region_code);
    } else if (type == 6) {
        int date;
        cin >> date;
        query_number_people_alive_at(date);
    } else if (type == 7) {
        query_number_people();
    }
}

for (int i = 1; i <= n; i++) {
    delete people[i];
}
return 0;
}