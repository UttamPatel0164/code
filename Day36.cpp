3201. Find the Maximum Length of Valid Subsequence I
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [1,2,3,4]

Output: 4

Explanation:

The longest valid subsequence is [1, 2, 3, 4].

Example 2:

Input: nums = [1,2,1,1,2,1,2]

Output: 6

Explanation:

The longest valid subsequence is [1, 2, 1, 2, 1, 2].
class Solution {
public:
    int maximumLength(vector<int>& a) 
    {
        int even=0,odd=0,alter=1;
        int parity=a[0]%2;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]%2==0)
                even++;
            else
                odd++;
            if(i==0)
                continue;
            int currparity=a[i]%2;
            if(currparity!=parity)
            {
                alter++;
                parity=currparity;
            }
        }    
        return max(alter,max(even,odd));
    }
};