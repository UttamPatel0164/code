// 1061. Lexicographically Smallest Equivalent String
// You are given two strings of the same length s1 and s2 and a string baseStr.

// We say s1[i] and s2[i] are equivalent characters.

// For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
// Equivalent characters follow the usual rules of any equivalence relation:

// Reflexivity: 'a' == 'a'.
// Symmetry: 'a' == 'b' implies 'b' == 'a'.
// Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
// For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

// Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

 

// Example 1:

// Input: s1 = "parker", s2 = "morris", baseStr = "parser"
// Output: "makkek"
// Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
// The characters in each group are equivalent and sorted in lexicographical order.
// So the answer is "makkek".
class Solution 
{
private:
    int find(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void un(int x,int y)
    {
        int px=find(x),py=find(y);
        if(px==py)
            return;
        if(px<py)
            parent[py]=px;
        else
            parent[px]=py;
    }
public:
    int parent[26];
    string smallestEquivalentString(string s1, string s2, string s) 
    {
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<s1.size();i++)
        {
            un(s1[i]-'a',s2[i]-'a');
        }
        string ans="";
        for(auto ch:s)
        {
            ans +=(char)(find(ch-'a')+'a');
        }
        return ans;

        
    }
};