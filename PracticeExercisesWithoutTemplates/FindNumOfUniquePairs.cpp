//
// Created by Nitish Mohan Shandilya on 9/2/20.
// https://leetcode.com/discuss/interview-question/372434

int findNumberOfUniquePairs(vector<int>& nums, int target) {
    unordered_set<int> numsSet(nums.begin(), nums.end());
    int totalCount = 0;
    for (int num : nums) {
        int sumToFind = target-num;
        if (numsSet.find(sumToFind) != numsSet.end()) {
            ++totalCount;
            numsSet.erase(num);
            numsSet.erase(sumToFind);
        }
    }
    return totalCount;
}

int main() {
    vector<int> nums = {3,2,5,0,4,1,0,5,2,3,6,-1,-2,7,7};
    int target = 5;
    cout << findNumberOfUniquePairs(nums, target);
}
