#include <stdbool.h>
#include <string.h>

bool isMatch(const char *s, const char *p) {
    int m = strlen(s), n = strlen(p);
    bool dp[m + 1][n + 1];

    // Initialize all cells to false
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    // Initialize patterns like a*, a*b*, a*b*c* matching empty string
    for (int j = 2; j <= n; ++j) {
        if (p[j - 1] == '*' && dp[0][j - 2]) {
            dp[0][j] = true;
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                // Compare with zero occurrence of prev char
                dp[i][j] = dp[i][j - 2];
                // Compare if prev char matches s[i-1]
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] |= dp[i - 1][j];
                }
            } else {
                // Direct character match, or .
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
    }

    return dp[m][n];
}
