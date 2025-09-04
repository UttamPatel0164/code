1493. Longest Subarray of 1's After Deleting One Element
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

class Solution {
    public int longestSubarray(int[] a) 
    {
        int n=a.length;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int left=0,right=0;
            if(a[i]==0)
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(a[j]==1)
                        left++;
                    else
                        break;
                }
                for(int j=i+1;j<n;j++)
                {
                    if(a[j]==1)
                        right++;
                    else
                        break;
                }

            }
            ans=Math.max(ans,left+right);

        }
        int ctr=-1;
        for(int i=0;i<n;i++)
        {   
            if(a[i]==1)
                ctr++;
            else{
                ctr=0;
                break;
            }
        }
        ans=Math.max(ans,ctr);
        return ans;
    }
}