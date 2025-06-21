Police and Thieves
Given an array arr[], where each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police. 
Keep in mind the following conditions :

Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than k units away from him.
Examples:

Input: arr[] = ['P', 'T', 'T', 'P', 'T'], k = 1
Output: 2
Explanation: Maximum 2 thieves can be caught. First policeman catches first thief and second police man can catch either second or third thief.
Input: arr[] = ['T', 'T', 'P', 'P', 'T', 'P'], k = 2
Output: 3
Explanation: Maximum 3 thieves can be caught.
class Solution {
  public:
    int catchThieves(vector<char> &a,int k) 
    {
        int ans=0;
        int p=0,t=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            //next police
            while(p<n &&a[p]!='P')
                p++;
            //next thieves
            while(t<n && a[t]!='T')
                t++;
            if(t<n && p<n&& abs(t-p)<=k)
            {
                ans++;
                t++;
                p++;
            }
            else if(t<n && t<p)
            {
                t++;
            }
            else if(p<n && p<t)
            {
                p++;
            }
        }
        return ans;
        
    }
};