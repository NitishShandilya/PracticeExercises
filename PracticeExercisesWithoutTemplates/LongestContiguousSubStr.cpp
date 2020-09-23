//
// Created by Nitish Mohan Shandilya on 9/23/20.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <sstream>
#include <string>
#include <algorithm>
#include <queue>

// Input: "aabbaaaaabb"
// Output: "aabbaa"

using namespace std;

string findLongestContiguousSubStr(string input) {

  char current;
  pair<int, int> indexAndFreq = make_pair(0,0);
  int maxLen = INT_MIN;
  int maxStart = 0;

  for (int i=0, j=0; j<input.length(); ++j) {
    if (input[j] == current) {
      indexAndFreq.second += 1;
    } else {
      indexAndFreq.first = j;
      indexAndFreq.second = 1;
      current = input[j];
    }

    while (indexAndFreq.second > 2) {
      // Shrink the window
      if (current == input[i] && i>= indexAndFreq.first) {
        --indexAndFreq.second;
      }
      ++i;
    }

    int currLen = j-i+1;
    if (currLen > maxLen) {
      maxStart = i;
      maxLen = currLen;
    }
  }
  return input.substr(maxStart, maxLen);
}

int main() {

  cout << findLongestContiguousSubStr("aaa");
  return 0;
}

