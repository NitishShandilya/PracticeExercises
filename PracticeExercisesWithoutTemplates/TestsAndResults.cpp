//
// Created by Nitish Mohan Shandilya on 9/9/20.
//

// Test cases vector 1a, 1b,
// Given two vectors T and R, find the score of passing test cases
// Only if all the tests in the group is passed, then only the entire group is
// a pass.
class Solution {
    unordered_map<int, vector<int>> lookupMap;
    void buildLookupMap(vector<string>& tests, vector<string>& results) {
        string prefix = tests[0];
        int prefixIndex=0;
        while (prefixIndex<prefix.length() && !isdigit(prefix[prefixIndex])) {
            ++prefixIndex;
        }
        for (int i=0; i<tests.size(); ++i) {
            string& test = tests[i];
            int numPart = getNumber(test, prefixIndex);
            auto it = lookupMap.find(numPart);
            if (it == lookupMap.end()) {
                lookupMap.insert({numPart, initializer_list<int>{i}});
            } else {
                lookupMap[numPart].push_back(i);
            }
        }
    }
    int getNumber(string& test, int prefixIndex) {
        string buffer;
        while (prefixIndex<test.length() && isdigit(test[prefixIndex])) {
            buffer.push_back(test[prefixIndex]);
            ++prefixIndex;
        }
        return stoi(buffer);
    }
public:
    int computeResult(vector<string>& tests, vector<string>& results) {
        buildLookupMap(tests, results);

        int totalPassCount = 0;
        for (auto ele : lookupMap) {
            int test = ele.first;
            vector<int>& rIndices = ele.second;
            if (rIndices.size() == 1 && results[rIndices[0]] == "OK") {
                ++totalPassCount;
                continue;
            }
            int passCount = 0;
            for (int rIndex : rIndices) {
                if (results[rIndex] == "OK")
                    ++passCount;
            }
            if (rIndices.size() == passCount)
                ++totalPassCount;
        }

        int result = (totalPassCount*100)/lookupMap.size();
        return result;
    }
};


int main() {
    std::cout << "Hello World!\n";
    vector<string> tests =
        {"codility2", "codility1a", "codility1b", "codility3"};
    vector<string> results = {"OK", "OK", "OK", "Runtime"};
    Solution s;
    cout << s.computeResult(tests, results);
}
