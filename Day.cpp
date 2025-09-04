Smallest window containing all characters
Difficulty: HardAccuracy: 30.19%Submissions: 181K+Points: 8Average Time: 30m
Given two strings s and p. Find the smallest substring in s consisting of all the characters (including duplicates) of the string p. Return empty string in case no such substring is present.
If there are multiple such substring of the same length found, return the one with the least starting index.

Examples:

Input: s = "timetopractice", p = "toc"
Output: "toprac"
Explanation: "toprac" is the smallest substring in which "toc" can be found.
Input: s = "zoomlazapzo", p = "oza"
Output: "apzo"
Explanation: "apzo" is the smallest substring in which "oza" can be found.
Input: s = "zoom", p = "zooe"
Output: ""
Explanation: No substring is present containing all characters of p.
Constraints: 
1 ≤ s.length(), p.length() ≤ 106
s, p consists of lowercase english letters
class Solution {
  public:
    string smallestWindow(string &s, string &p) 
    {
        int n=s.size(),ctr=0,ans=s.size(),ind=-1;
        vector<int> freq(26,0);
        for(char i:p)
        {
            if(freq[i-'a']==0)
                ctr++;
            freq[i-'a']++;
        }
        int left=0,right=0;
        while(right<n)
        {
            freq[s[right]-'a']--;
            if(freq[s[right]-'a']==0)
                ctr--;
            while(ctr==0)
            {
                
                if(right-left+1 <ans)
                {
                    ans=right-left+1;
                    ind=left;
                }
                freq[s[left]-'a']++;
                if(freq[s[left]-'a']>0)
                    ctr++;
                left++;
            }
            right++;
        }
        string res;
        if(ind!=-1)
            res=s.substr(ind,ans);
        return res;
    }
};