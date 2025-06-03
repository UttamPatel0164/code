// Substrings with K Distinct
// Given a string consisting of lowercase characters and an integer k, the task is to count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

// Examples :

// Input: s = "abc", k = 2
// Output: 2
// Explanation: Possible substrings are ["ab", "bc"]

class Solution {
  public:
  int ctr(string s,int k)
    {
        if(k<=0)
            return 0;
        int ans=0;
        int n=s.size();
        vector<int> ch(26,0);
        int l=0,r=0;
        int ct=0;
        while(r<n)
        {
            if(ch[s[r]-'a']==0)
                ct ++;
            ch[s[r]-'a']++;
            while(ct>k)
            {
                ch[s[l]-'a']--;
                if(ch[s[l]-'a']==0)
                    ct--;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int countSubstr(string& s, int k) 
    {
        return ctr(s,k)-ctr(s,k-1);
    }
};