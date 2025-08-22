Maximize the minimum difference between k elements
Difficulty: MediumAccuracy: 78.97%Submissions: 3K+Points: 4
Given an array arr[] of integers and an integer k, select k elements from the array such that the minimum absolute difference between any two of the selected elements is maximized. Return this maximum possible minimum difference.

Examples:

Input: arr[] = [2, 6, 2, 5], k = 3
Output: 1
Explanation: 3 elements out of 4 elements are to be selected with a minimum difference as large as possible. Selecting 2, 2, 5 will result in minimum difference as 0. Selecting 2, 5, 6 will result in minimum difference as 6 - 5 = 1.
Input: arr[] = [1, 4, 9, 0, 2, 13, 3], k = 4
Output: 4
Explanation: Selecting 0, 4, 9, 13 will result in minimum difference of 4, which is the largest minimum difference possible.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 106
2 ≤ k ≤ arr.size() 

 class Solution {
    bool elementsWithGivenDiff(vector<int>& arr, int d, int k){
        int cnt = 1, j = 0, n = arr.size();
        for(int i=1; i<n; i++){
            if((arr[i] - arr[j]) >= d){
                cnt++;
                j = i;
            }
        }
        return cnt >= k;
    }
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), l = 1, h = (arr[n-1] - arr[0]), res = 0;
        while(l<=h){
            int m = l + ((h-l+1)/2);
            if(elementsWithGivenDiff(arr, m, k)){
                res = m;
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return res;
    }
};