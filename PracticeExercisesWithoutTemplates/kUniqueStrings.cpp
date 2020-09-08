//
// Created by Nitish Mohan Shandilya on 8/28/20.
// https://leetcode.com/discuss/interview-question/370112
// Given a string s and an int k, return all unique substrings
// of s of size k with k distinct characters.

using namespace std;
vector<string> findKUniqueStrings(string s, int k) {
    int i=0, j=0;
    vector<bool> bitset(26, false);
    vector<string> result;
    while (i<s.length()-k && j<s.length()) {
        int diff = j-i;
        if (diff == k || bitset[s[j]-'a']) {
            if (diff == k)
                result.emplace_back(s.substr(i, diff));
            bitset[s[i]-'a'] = false;
            ++i;
        } else {
            bitset[s[j]-'a'] = true;
            ++j;
        }
    }
    return result;
}
int main() {
    std::cout << "Hello World!\n";
    string s = "awaglknagawunagwkwagl";
    int k = 4;
    vector<string> result = findKUniqueStrings(s, k);
    for (string word : result)
        cout << word << ", ";
    //Output: ["wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag"]
}
