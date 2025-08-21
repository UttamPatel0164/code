2787. Ways to Express an Integer as Sum of Powers
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given two positive integers n and x.

Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

Since the result can be very large, return it modulo 109 + 7.

For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

 

Example 1:

Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 32 + 12 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
Example 2:

Input: n = 4, x = 1
Output: 2
Explanation: We can express n in the following ways:
- n = 41 = 4.
- n = 31 + 11 = 4.
 

Constraints:

1 <= n <= 300
1 <= x <= 5


class Solution {
public:
    int l;
    const int MOD = 1e9 + 7;

    long long powLL(long long base, long long p,long long M) {
        long long ans = 1;
        while (p > 0) {
            if (p & 1) ans = (ans*base)%M;
            base = (base*base)%M;
            p >>= 1;
        }
        return ans;
    }

    int fun(int ind, int n, int x, vector<vector<int>> &dp) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (ind > l) return 0;

        if (dp[n][ind] != -1) return dp[n][ind];

        long long pw = powLL(ind, x,MOD);
        if (pw > n) return dp[n][ind] = fun(ind + 1, n, x, dp);

        int take = fun(ind + 1, n - pw, x, dp);
        int not_take = fun(ind + 1, n, x, dp);

        return dp[n][ind] = ( (long long)take + not_take ) % MOD;
    }

    int numberOfWays(int n, int x) {
        l = n;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return fun(1, n, x, dp);
    }
};
