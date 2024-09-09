#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    
    // DP table
    vector< vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
    
    // Empty pattern matches empty string
    dp[0][0] = true;
    
    // Handle patterns like a*, a*b*, a*b*c* which can match an empty string
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    
    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    // Example 1
    string s1 = "aa";
    string p1 = "a";
    cout << isMatch(s1, p1) << endl;  // Output: false
    
    // Example 2
    string s2 = "aa";
    string p2 = "a*";
    cout << isMatch(s2, p2) << endl;  // Output: true
    
    // Example 3
    string s3 = "ab";
    string p3 = ".*";
    cout << isMatch(s3, p3) << endl;  // Output: true
    
    return 0;
}
