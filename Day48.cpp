2419. Longest Subarray With Maximum Bitwise AND
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int maxi=0,ans=0;
        for(int i:a)
            maxi=max(maxi,i);
        int ctr=0;
        for(int i=0;i<a.size();i++)
        {

            if(a[i]==maxi)
            {
                ctr++;
                ans=max(ans,ctr);
            }
            else
            {
                ctr=0;
            }
        }
        return ans;
        
    }
};