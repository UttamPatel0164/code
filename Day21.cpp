594. Longest Harmonious Subsequence
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0, r=0, ans=0, n=nums.size();
        while(l<n && r<n){
            int d = nums[r]-nums[l];
            if(d==1) ans=max(ans, r-l+1);
            if(d<=1) r++;
            else l++;

        }
        
        return ans;
    }
};