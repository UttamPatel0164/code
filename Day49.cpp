Balancing Consonants and Vowels Ratio
Difficulty: MediumAccuracy: 67.04%Submissions: 3K+Points: 4
You are given an array of strings arr[], where each arr[i] consists of lowercase english alphabets. You need to find the number of balanced strings in arr[] which can be formed by concatinating one or more contiguous strings of arr[].
A balanced string contains the equal number of vowels and consonants. 

Examples:

Input: arr[] = ["aeio", "aa", "bc", "ot", "cdbd"]
Output: 4
Explanation: arr[0..4], arr[1..2], arr[1..3], arr[3..3] are the balanced substrings with equal consonants and vowels.
Input: arr[] = ["ab", "be"]
Output: 3
Explanation: arr[0..0], arr[0..1], arr[1..1] are the balanced substrings with equal consonants and vowels.
Input: arr[] = ["tz", "gfg", "ae"]
Output: 0
Explanation: There is no such balanced substring present in arr[] with equal consonants and vowels.

class Solution {
  public:
    int countBalanced(vector<string>& a) 
    {
        vector<int> arr;
        for(string i:a)
        {
            int sum=0;
            for(char j:i)
            {
                if(j=='a'||j=='e'||j=='i'||j=='o'||j=='u')
                {
                    sum++;
                }
                else
                {
                    sum--;
                }
            }
            arr.push_back(sum);
        }
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int sum=0;
        int ans=0;
        for(int i:arr)
        {
            sum+=i;
            int rem=sum-0;
            if(mpp.find(rem)!=mpp.end())
            {
                ans+=mpp[rem];
            }
            mpp[sum]++;
            
        }
        return ans;
        
    }
};