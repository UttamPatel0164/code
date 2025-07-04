3307. Find the K-th Character in String Game II
Solved
Hard
Topics
premium lock icon
Companies
Hint
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation.

 

Example 1:

Input: k = 5, operations = [0,0,0]

Output: "a"

Explanation:

Initially, word == "a". Alice performs the three operations as follows:

Appends "a" to "a", word becomes "aa".
Appends "aa" to "aa", word becomes "aaaa".
Appends "aaaa" to "aaaa", word becomes "aaaaaaaa".
class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) 
    {
        int shift = 0;
        vector<long long> lengths;
        long long len = 1;

        for (int op : operations) {
            len *= 2;
            lengths.push_back(len);
            if (len >= k) break;
        }
        int ans = 0;
        int x = op.size() - 1;
        while (x >=0)
        {
            if (k > p)
            {
                k -= p;
                if (op[x] == 1)
                    ans++;
            }
            x--;
        }
        
        return 'a' + ans;
    }
};
