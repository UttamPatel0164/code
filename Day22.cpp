3333. Find the Original Typed String II
Solved
Hard
Topics
premium lock icon
Companies
Hint
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.

Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: word = "aabbccdd", k = 7

Output: 5

Explanation:

The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
class Solution {
public:
    static constexpr int mod=1e9+7;
    int possibleStringCount(string& word, int k) {
        const int n=word.size();
        if (n<k) return 0;// edge case
        if (n==k) return 1;

        // Deal with segments of consecutive same letters
        vector<int> seg={1};
        for (int i=1; i<n; i++)
            if (word[i]==word[i-1]) seg.back()++;
            else seg.push_back(1);
        const int m=seg.size();

        // number of all total typed string, each seg has at least 1
        long long total=1;
        bool takeMod=0;
        for(int x: seg){
            total*=x;
            if (total>=mod) {
                total%=mod;
                takeMod=1;
            }
        }
        if (total==1 && !takeMod) return 1; // special case

        if (k<=m) return total;

        // invalid strings where original len < k
        // Use Prefix sum & DP to count based on the following inequalities
        // z0+z1+....+z[m-1]<=k-m-1
        // 0<=zi<=si-1=seg[i]-1
        int maxT=k-m-1;
        long long dp[2][2000]={0}, prefix[2001]={0};
        dp[0][0]=1;

        for (int j=0; j<m; j++) {
            const int s=seg[j];
            for (int i=0; i<=maxT; i++){
                prefix[i+1]=(prefix[i]+dp[j&1][i])%mod;// 1-indexed prefix sum
                int L=max(0, i-(s-1)), R=i;
                dp[(j+1)&1][i]=(prefix[R+1]-prefix[L]+mod)%mod;
            }
        }

        long long lessK=0;
        for (long long x : dp[m&1])
            lessK=(lessK+x)%mod;

        return (total-lessK+mod) % mod;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();