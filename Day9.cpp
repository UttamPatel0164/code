// Exactly one swap
// Given a string s, return the number of distinct strings that can be obtained by exactly one swap of two different indices (i < j).

// Examples:

// Input: s = "geek"
// Output: 6
// Explanation: After one swap, There are only 6 distinct strings possible.(i.e "egek","eegk","geek","geke","gkee" and "keeg") 
class Solution {
  public:
    int countStrings(string &s) 
    {
        vector<int> freq(26,0);
        for(auto i:s)
        {
            freq[i-'a']++;
        }
        int div=0;
        for(i:freq)
        {
            if(i>0)
                div +=i*(i-1)/2;
        }
        int n=s.size();
        int ans=(n*(n-1))/2;
        ans=ans-div;
        if (div > 0) ans += 1;
        return ans;
        
        
    }
};
