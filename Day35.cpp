Divisible by 13
Difficulty: MediumAccuracy: 55.82%Submissions: 7K+Points: 4
Given a number represented as a string s (which may be very large), check whether it is divisible by 13 or not.

Examples:

Input : s = "2911285"
Output : true
Explanation: 2911285 ÷ 13 = 223945, which is a whole number with no remainder.
Input : s = "27"
Output : false
Explanation: 27 / 13 ≈ 2.0769..., which is not a whole number (there is a remainder).
class Solution {
  public:
    bool divby13(string &s) 
    {
        long long a=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            a=(a*10+(s[i]-'0'))%13;
        }
        return a%13==0;
        
    }
};