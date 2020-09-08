//
// Created by Nitish Mohan Shandilya on 9/2/20.
// https://leetcode.com/discuss/interview-question/373202

struct SortComp {
    bool operator () (const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
};
vector<vector<int>> findOptimalUtil(vector<vector<int>>& a, vector<vector<int>>& b, int target) {
    sort(a.begin(), a.end(), SortComp());
    sort(b.begin(), b.end(), SortComp());

    int i=0,j=b.size()-1, currentDiff = INT_MAX;
    vector<vector<int>> result;
    while (i<a.size() && j>=0) {
        int currSum = a[i][1] + b[j][1];

        if (currSum <= target && target-currSum < currentDiff) {
            result.clear();
            result.push_back(initializer_list<int>{a[i][0], b[j][0]});
            currentDiff = target-currSum;
        } else if (currSum <= target && (target-currSum == currentDiff)) {
            result.push_back(initializer_list<int>{a[i][0], b[j][0]});
        }

        if (currSum < target) {
            ++i;
        } else {
            --j;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> a = {{1, 3}, {2, 5}, {3, 7}, {4,10}};
    vector<vector<int>> b = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int target = 10;

    // a = [[1, 3], [2, 5], [3, 7], [4, 10]]
    // b = [[1, 2], [2, 3], [3, 4], [4, 5]]
    // target = 10

    vector<vector<int>> optimalUtil = findOptimalUtil(a, b, target);
    for (vector<int>& ele : optimalUtil) {
        cout << ele[0] << ":" << ele[1] << endl;
    }

}
