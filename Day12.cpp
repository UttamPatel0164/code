Equalize the Towers
You are given an array heights[] representing the heights of towers and another array cost[] where each element represents the cost of modifying the height of respective tower.

The goal is to make all towers of same height by either adding or removing blocks from each tower.
Modifying the height of tower (add or remove) 'i' by 1 unit costs cost[i].
Return the minimum cost to equalize the heights of all towers.

Examples:

Input: heights[] = [1, 2, 3], cost[] = [10, 100, 1000]
Output: 120
Explanation: The heights can be equalized by either "Removing one block from 3 and adding one in 1" or "Adding two blocks in 1 and adding one in 2". Since the cost of operation in tower 3 is 1000, the first process would yield 1010 while the second one yields 120.
class Solution {
  public:
  int getcost(vector<int>& h, vector<int>& c,int k)
    {
        int ans=0;
        for(int i=0;i<c.size();i++)
        {
            ans+=abs(h[i]-k)*c[i];
        }
        return ans;
    }
    int minCost(vector<int>& h, vector<int>& c) 
    {
        int low=*min_element(h.begin(), h.end());
        int high=*max_element(h.begin(), h.end());
        int val;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int val=getcost(h,c,mid);
            int val1=getcost(h,c,mid+1);
            if(val>=val1)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return getcost(h,c,low);
        
    }
};
