Longest Periodic Proper Prefix
Difficulty: HardAccuracy: 44.35%Submissions: 4K+Points: 8
Given a string s, find the length of longest periodic proper prefix of s. If no such prefix exists, return -1.
A periodic proper prefix is a non empty prefix of s (but not the whole string), such that repeating this prefix enough times produces a string that starts with s.

Examples:

Input: s = "aaaaaa"
Output: 5
Explanation: Repeating the proper prefix "aaaaa" forms "aaaaaaaaaa...", which contains "aaaaa" as a prefix. No longer proper prefix satisfies this.
Input: s = "abcab"
Output: 3
Explanation: Repeating the proper prefix "abc" forms "abcabc., which contains "abcab" as a prefix. No longer proper prefix satisfies this.
Input: s = "ababd"
Output: -1
Explanation: No proper prefix satisfying the given condition.
Constraints:
1 ≤ s.size() ≤ 105
s consists of lowercase English alphabets
class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
        int n = s.size();
        int len = s.size()-1;
        
        while(len){
            int sPtr = len;
            int i = 0;
            
            while(sPtr<n){
                if(s[sPtr] == s[i]){
                    i++;
                    sPtr++;
                }
                else{
                    break;
                }
            }
            
            if(sPtr==n)
              return len;
            
            len--;
        }
        
        
        return -1;
        
    }
};