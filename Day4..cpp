Count Numbers Containing Specific Digits
Difficulty: MediumAccuracy: 70.94%Submissions: 2K+Points: 4Average Time: 25m
You are given an integer n representing the number of digits in a number, and an array arr[] containing digits from 0 to 9. Your have to count how many n-digit positive integers can be formed such that at least one digit from the array arr[] appears in the number.

Examples:

Input: n = 1, arr[] = [1, 2, 3]
Output: 3
Explanation: Only the single-digit numbers [1, 2, 3] satisfy the condition.
Input: n = 2, arr[] = [3, 5]
Output: 34
Explanation: There are a total of 34  two digit numbers which contain atleast  one out of  [3, 5].
Constraints:
  1 ≤ n ≤ 9
  1 ≤ arr.size() ≤ 10
  0 ≤ arr[i] ≤ 9
  class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        int tot=9*pow(10,n-1);
        int isZeroPresent=count(arr.begin(), arr.end(), 0);
        int N=arr.size();
        return tot-(9-N+isZeroPresent)*pow(10-N,n-1);
    }
};