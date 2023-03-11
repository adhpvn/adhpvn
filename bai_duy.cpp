#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Citizen {
    string code;
    string date_of_birth;
    string father_code;
    string mother_code;
    char is_alive;
    string region_code;
};

// Hàm đọc thông tin về công dân từ input
vector<Citizen> read_citizens() {
    vector<Citizen> citizens;
    string line;
    while (getline(cin, line) && line != "*") {
        Citizen citizen;
        stringstream ss(line);
        ss >> citizen.code >> citizen.date_of_birth >> citizen.father_code >> citizen.mother_code >> citizen.is_alive >> citizen.region_code;
        citizens.push_back(citizen);
    }
    return citizens;
}

// Hàm đọc các câu truy vấn từ input và thực hiện trả về kết quả tương ứng
vector<int> execute_queries(vector<Citizen> &citizens) {
    vector<int> results;
    string query;
    while (getline(cin, query)) {
        stringstream ss(query);
        string command;
        ss >> command;
        if (command == "NUMBER_PEOPLE") {
            results.push_back(citizens.size());
        }
        else if (command == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            ss >> date;
            int count = 0;
            for (Citizen &citizen : citizens) {
                if (citizen.date_of_birth == date) {
                    count++;
                }
            }
            results.push_back(count);
        }
        else if (command == "MOST_ALIVE_ANCESTOR") {
            string code;
            ss >> code;
            map<string, int> ancestor_depths;
            int max_depth = 0;
            for (Citizen &citizen : citizens) {
                if (citizen.code == code) {
                    continue;
                }
                int depth = 0;
                string curr_code = citizen.code;
                while (curr_code != "0000000") {
                    depth++;
                    if (ancestor_depths.count(curr_code) > 0) {
                        depth += ancestor_depths[curr_code];
                        break;
                    }
                    for (Citizen &ancestor : citizens) {
                        if (ancestor.code == curr_code) {
                            curr_code = ancestor.father_code;
                            break;
                        }
                        else if (ancestor.code == curr_code) {
                            curr_code = ancestor.mother_code;
                            break;
                        }
                    }
                }
                if (depth > max_depth) {
                    max_depth = depth;
                }
                ancestor_depths[citizen.code] = depth;
            }
            results.push_back(max_depth);
        }
        else if (command == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string from_date, to_date;
            ss >> from_date >> to_date;
            int count = 0;
            for (Citizen &citizen : citizens) {
                if (citizen.date_of_birth >= from_date && citizen.date_of_birth <= to_date) {
                    count++;
                }
            }
            results.push_back(count);
        }
    }
    return results;
}

int main() {
    vector<Citizen> citizens = read_citizens();
    vector<int> results = execute_queries(citizens);
    for (int &result : results) {
        cout << result << endl;
    }
    return 0;
}
