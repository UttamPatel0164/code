1717. Maximum Score From Removing Substrings
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
class Solution {
public:
    int fun(string s, int x, int y)
    {
        stack<char> st;
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(!st.empty() && st.top() == 'a' && s[i] == 'b')
            {
                st.pop();
                ans += y;
            }
            else
            {
                st.push(s[i]);
            }
        }
        stack<char> st2;
        while(!st.empty())
        {
            char curr = st.top();
            st.pop();
            
            if(!st2.empty() && st2.top() == 'a' && curr == 'b')
            {
                st2.pop();
                ans += x;
            }
            else
            {
                st2.push(curr);
            }
        }
        
        return ans;
    }
    
    int fun1(string s, int x, int y)
    {
        stack<char> st;
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(!st.empty() && st.top() == 'b' && s[i] == 'a')
            {
                st.pop();
                ans += x;
            }
            else
            {
                st.push(s[i]);
            }
        }
        stack<char> st2;
        while(!st.empty())
        {
            char curr = st.top();
            st.pop();
            
            if(!st2.empty() && st2.top() == 'b' && curr == 'a')
            {
                st2.pop();
                ans += y;
            }
            else
            {
                st2.push(curr);
            }
        }
        
        return ans;
    }
    
    int maximumGain(string s, int x, int y) 
    {
        return max(fun(s, x, y), fun1(s, x, y));
    }
};
class SolutionOptimized {
public:
    int removeSubstring(string s, string sub, int points) {
        stack<char> st;
        int score = 0;
        
        for(char c : s) {
            if(!st.empty() && st.top() == sub[0] && c == sub[1]) {
                st.pop();
                score += points;
            } else {
                st.push(c);
            }
        }
        string remaining = "";
        while(!st.empty()) {
            remaining = st.top() + remaining;
            st.pop();
        }
        s = remaining;
        
        return score;
    }
    
    int maximumGain(string s, int x, int y) {
        int score = 0;
        
        if(x >= y) {
            // Remove "ab" first, then "ba"
            score += removeSubstring(s, "ab", x);
            score += removeSubstring(s, "ba", y);
        } else {
            // Remove "ba" first, then "ab"
            score += removeSubstring(s, "ba", y);
            score += removeSubstring(s, "ab", x);
        }
        
        return score;
    }
};