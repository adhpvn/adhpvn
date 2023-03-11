#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

struct Citizen {
    string code;
    string date_of_birth;
    string father_code;
    string mother_code;
    char is_alive;
    string region_code;
};

vector<Citizen> citizens;
unordered_map<string, Citizen> citizens_map;
unordered_set<string> found_codes;

int get_number_of_people() {
    return citizens.size();
}

int get_number_of_people_born_at(string date) {
    int count = 0;
    for (auto &citizen : citizens) {
        if (citizen.date_of_birth == date) {
            count++;
        }
    }
    return count;
}

int get_most_alive_ancestor(string code) {
    int max_generation = 0;
    found_codes.clear();
    while (true) {
        if (code == "0000000") {
            break;
        }
        if (found_codes.find(code) != found_codes.end()) {
            break;
        }
        found_codes.insert(code);
        if (citizens_map.find(code) != citizens_map.end()) {
            Citizen citizen = citizens_map[code];
            if (citizen.is_alive == 'Y') {
                max_generation++;
            }
            code = citizen.father_code;
        }
    }
    return max_generation;
}

int get_number_of_people_born_between(string from_date, string to_date) {
    int count = 0;
    for (auto &citizen : citizens) {
        if (citizen.date_of_birth >= from_date && citizen.date_of_birth <= to_date) {
            count++;
        }
    }
    return count;
}

int main() {
    string line;
    getline(cin, line); // skip the first line
    while (getline(cin, line)) {
        if (line == "*") {
            break
    }
    else {
        string query_type;
        stringstream ss(line);
        ss >> query_type;
        if (query_type == "NUMBER_PEOPLE") {
            cout << get_number_of_people() << endl;
        }
        else if (query_type == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            ss >> date;
            cout << get_number_of_people_born_at(date) << endl;
        }
        else if (query_type == "MOST_ALIVE_ANCESTOR") {
            string code;
            ss >> code;
            cout << get_most_alive_ancestor(code) << endl;
        }
        else if (query_type == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string from_date, to_date;
            ss >> from_date >> to_date;
            cout << get_number_of_people_born_between(from_date, to_date) << endl;
        }
    }
}
return 0;
