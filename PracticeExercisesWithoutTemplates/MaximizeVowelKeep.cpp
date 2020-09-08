//
// Created by Nitish Mohan Shandilya on 9/7/20.
// You are given with a string . Your task is to remove atmost two
// substrings of any length from the given //string such that
// the remaining string contains vowels('a','e','i','o','u') only.
// Your aim is the maximise //the length of the remaining string.
// Output the length of remaining string after removal of atmost two //substrings.
//NOTE: The answer may be 0, i.e. removing the entire string.

//Sample Input
//2
//earthproblem
//letsgosomewhere
//Sample Output
//3
//2
//https://leetcode.com/discuss/interview-question/233724

bool isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int keepVowels(string& str) {
    if (str.empty()) return 0;
    int begin=0, end=str.length()-1;
    while (isVowel(str[begin])) ++begin;
    if (begin==str.length()) return begin;

    while (isVowel(str[end])) --end;
    int firstLen = begin + str.length()-1 - end;
    int secondLen=0, currLen=0;
    for (int i=begin; i<=end; ++i) {
        if (isVowel(str[i])) {
            ++currLen;
        } else {
            currLen=0;
        }
        secondLen = max(secondLen, currLen);
    }
    return firstLen + secondLen;
}

int main() {
    vector<string> strs = {"earthproblem", "leetcode", "aeiou", "dqeiou", "baab", "", "a", "fghj"};
    for (string str : strs)
        cout << keepVowels(str) << endl;
}

