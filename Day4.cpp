// LCS of three strings
// Given three strings s1, s2, and s3 containing uppercase letters, lowercase letters, and digits, find the length of longest common sub-sequence in all three given strings.

// Examples:

// Input: s1 = "geeks", s2 = "geeksfor", s3 = "geeksforgeeks"
// Output: 5
// Explanation: "geeks"is the longest common subsequence with length 5.
class Solution {
  public:
    int lcs(string s1,string s2,string s3,int n1,int n2,int n3,int i,int j,int k,vector<vector<vector<int>>> &dp)
    {
        if(i>=n1 || j>=n2||k>=n3)
            return 0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(s1[i]==s2[j] && s2[j]==s3[k])
        {
            return dp[i][j][k]=1+lcs(s1,s2,s3,n1,n2,n3,i+1,j+1,k+1,dp);
        }
        return dp[i][j][k]=max(lcs(s1,s2,s3,n1,n2,n3,i+1,j,k,dp),max(lcs(s1,s2,s3,n1,n2,n3,i,j+1,k,dp),lcs(s1,s2,s3,n1,n2,n3,i,j,k+1,dp)));
    }
    int lcsOf3(string& s1, string& s2, string& s3) 
    {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
        lcs(s1,s2,s3,n1,n2,n3,0,0,0,dp);
        return dp[0][0][0];
    }
};
