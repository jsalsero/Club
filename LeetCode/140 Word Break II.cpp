#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, vector<string>> memo;

    vector<string> full(int i, string &s, unordered_set<string>& wordDict) {
        if (!memo.count(i))
            for (int j = i + 1; j <= s.size(); ++j)
                if (wordDict.count(s.substr(i, j - i)))
                    for (string tail : full(j, s, wordDict))
                        memo[i].push_back(s.substr(i, j - i) + (tail == "" ? "" : ' ' + tail));
        return memo[i];
    }

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        memo[s.size()] = {""};
        return full(0, s, wordDict);
    }
};

int main() {
    string s = "catsanddog";
    unordered_set<string> US = {"cat", "cats", "and", "sand", "dog"};

    Solution wo;
    auto ans = wo.wordBreak(s, US);
    
    for (auto var : ans)
        cout << var << endl;
    
    return 0;
}
