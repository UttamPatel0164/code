// Longest Span in two Binary Arrays
// Given two binary arrays, a1[] and a2[]. Find the length of longest common span (i, j) where j>= i such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].

// Examples:

// Input: a1[] = [0, 1, 0, 0, 0, 0], a2[] = [1, 0, 1, 0, 0, 1]
// Output: 4
// Explanation: The longest span with same sum is from index 1 to 4 following zero based indexing.
class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) 
    {
        int n=a1.size();
        int sum1=0,sum2=0;
        unordered_map <int, int> mp;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            sum1+=a1[i];
            sum2+=a2[i];
            if(sum1==sum2)
            {
                ans=max(ans,i+1);
            }
            else
            {
                int diff=sum1-sum2;
                if(mp.count(diff))
                    ans=max(ans,i-mp[diff]);
                else
                    mp[diff]=i;
            }
        }
        return ans;
    }
};