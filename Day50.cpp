Longest Subarray with Majority Greater than K
Difficulty: MediumAccuracy: 52.63%Submissions: 20K+Points: 4
Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

Examples:

Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
class Solution {
  public:
    int longestSubarray(vector<int> &a, int k) 
    {
        vector<int> arr;
        for(int i:a)
        {
            if(i>k)
                arr.push_back(1);
            else
                arr.push_back(-1);
        }
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
    
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + arr[i];

        vector<int> stack;
        for (int i = 0; i <= n; ++i) 
        {
            if (stack.empty() || prefix[i] < prefix[stack.back()])
                stack.push_back(i);
        }
        int maxLen = 0;
        for (int j = n; j >= 0; --j) 
        {
            while (!stack.empty() && prefix[j] > prefix[stack.back()]) 
            {
                maxLen = max(maxLen, j - stack.back());
                stack.pop_back();
            }
        }
    
        return maxLen;
           
            
    }
};