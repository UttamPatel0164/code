Trail of ones
Difficulty: MediumAccuracy: 51.16%Submissions: 36K+Points: 4
Given an integer n, the task is to count the number of binary strings of length n that contains at least one pair of consecutive 1's.
Note: A binary string is a sequence made up of only 0's and 1's.

Examples:

Input: n = 2
Output: 1
Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.
Input: n = 3
Output: 3
Explanation: There are 8 strings of length 3, the strings are 000, 001, 010, 011, 100, 101, 110 and 111. The strings with consecutive 1's are 011, 110 and 111.
Input: n = 5
Output: 19
Explanation: There are 19 strings having at least one pair of consecutive 1's.
class Solution {
public:
    int countConsec(int n) {
        if (n <= 2) return n-1;
        vector<int> dp(n + 1, 0);
        dp[2]=1;
        for (int i = 3; i <= n; i++) {
            dp[i] =pow(2, i-2)+dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
