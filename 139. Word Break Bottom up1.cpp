/*
Time: O(n ^ 3)
Space: O(n)

1  Define subproblems
dp[i]: whether s [0...i-1] can be segmented. Number of subproblems O(n)

2  Guess
the break point: number of choices O(i) or O(n)

3  Relate subproblem solutions
dp[i] = dp[0] && inDict(s[0…i-1]) || dp[1] && inDict(s[1...i-1]) || ...
|| dp[j] && inDict(s[j...i-1]) || … || dp[i - 1] && inDict(s[i - 1]) (0 <= j <= i - 1)

corner case: dp[0] = true
time per problem: O(i ^ 2) or O(n ^ 2)

4  Topological order
for i = 1, …, n

5  Original problem
dp[n]

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.cbegin(), wordDict.cend());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        // Topological order
        for (int i = 1; i <= n; ++i) {
            // Subproblem
            for (int j = 0; j <= i - 1; ++j) {
                // break the "and" relationship for clearness
                if (dp[j]) {
                    const string sub = s.substr(j, i - j);
                    if (wordSet.find(sub) != wordSet.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};
