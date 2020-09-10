//
// Created by Nitish Mohan Shandilya on 9/9/20.
//

// Given Student Id and the courses that he has taken
// Find the overlapping courses of two students

class Solution {

    struct UserGroupNotFoundException : exception {
        const char* what() noexcept {
            return "Bad Input passed";
        }
    };

    unordered_map<string, vector<string>> coursesToIdMap;
    unordered_map<string, vector<string>> result;

    void buildCoursesToIdMap(vector<string>& userIds, vector<vector<string>>& coursesList) {
        for (int i=0; i<userIds.size(); ++i) {
            string& user = userIds[i];
            vector<string>& courses = coursesList[i];
            for (string& course : courses) {
                auto it = coursesToIdMap.find(course);
                if (it == coursesToIdMap.end()) {
                    coursesToIdMap.emplace(course, initializer_list<string>{user});
                } else {
                    coursesToIdMap[course].emplace_back(user);
                }
            }
        }
    }

    void insertPairsIntoResultMap(vector<string>& userIds) {
        for (int i=0; i<userIds.size()-1; ++i) {
            for (int j=i+1; j<userIds.size(); ++j) {
                string& firstUser = userIds[i];
                string& secondUser = userIds[j];
                result.emplace(firstUser+ ","+secondUser, (0));
            }
        }
    }

public:
    void getOverlappingCourses(vector<string>& userIds, vector<vector<string>>& coursesList) {
        buildCoursesToIdMap(userIds, coursesList);
        insertPairsIntoResultMap(userIds);
        for (auto ele : coursesToIdMap) {
            const string& course = ele.first;
            vector<string>& userIds = ele.second;
            if (userIds.size() <= 1) continue;
            for (int i=0; i<userIds.size()-1; ++i) {
                for (int j=i+1; j<userIds.size(); ++j) {
                    string& firstUser = userIds[i];
                    string& secondUser = userIds[j];

                    string group1 = firstUser+","+secondUser;
                    string group2 = secondUser+","+firstUser;

                    auto it1 = result.find(group1);
                    auto it2 = result.find(group2);

                    if (it1 == result.end() && it2 != result.end()) {
                        result[it2->first].emplace_back(course);
                    } else if (it2 == result.end() && it1 != result.end()) {
                        result[it1->first].emplace_back(course);
                    } else {
                        throw UserGroupNotFoundException();
                    }
                }
            }
        }
    }

    void print() {
        for (auto ele : result) {
            const string& pairIds = ele.first;
            vector<string>& courses = ele.second;
            cout << pairIds << "->";
            for (string& course : courses) {
                cout << course << " : ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<string> userIds = {"45", "54", "65", "34", "5566", "1"};
    vector<vector<string>> coursesList = {{"Computer", "Electronics"}, {"Electronics"},
                              {"Social"}, {""}, {""}, {"Computer", "Electronics"}};
    Solution s;
    try {
        s.getOverlappingCourses(userIds, coursesList);
        s.print();
    } catch (exception& e) {
        cout << e.what();
    }
}
