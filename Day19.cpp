Game with String
Given a string s consisting of lowercase alphabets and an integer k, your task is to find the minimum possible value of the string after removing exactly k characters.

The value of the string is defined as the sum of the squares of the frequencies of each distinct character present in the string.

Examples :

Input: s = "abbccc", k = 2
Output: 6
Explaination: We remove two 'c' to get the value as 12 + 22 + 12 = 6 or We remove one 'b' and one 'c' to get the value 12 + 12 + 22 = 6.
class Solution {
  public:
    int minValue(string &s, int k) 
    {
        vector<int> ch(26,0);
        for(auto i:s)
            ch[i-'a']++;
        priority_queue<int> mh;
        for(int i=0;i<26;i++)
        {
            if(ch[i]>0)
                mh.push(ch[i]);
            
        }
        while(k>0)
        {
            int x=mh.top();
            x--;
            mh.pop();
            mh.push(x);
            k--;
        }
        int sum=0;
        while(!mh.empty())
        {
            int y=mh.top();
            sum+=(y*y);
            mh.pop();
        }
        return sum;
        
    }
};