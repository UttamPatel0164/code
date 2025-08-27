Count the number of possible triangles
Difficulty: MediumAccuracy: 28.53%Submissions: 146K+Points: 4Average Time: 15m
Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. A triangle with three given sides is only possible if sum of any two sides is always greater than the third side.

Examples:

Input: arr[] = [4, 6, 3, 7]
Output: 3
Explanation: There are three triangles possible [3, 4, 6], [4, 6, 7] and [3, 6, 7]. Note that [3, 4, 7] is not a possible triangle.  
Input: arr[] = [10, 21, 22, 100, 101, 200, 300]
Output: 6
Explanation: There can be 6 possible triangles: [10, 21, 22], [21, 100, 101], [22, 100, 101], [10, 100, 101], [100, 101, 200] and [101, 200, 300].
Input: arr[] = [1, 2, 3]
Output: 0
Explanation: No triangles are possible.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 105

class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size();
        int cnt = 0;
        sort(arr.begin() , arr.end());
        for(int i = 0 ; i<n ; ++i){
            for(int j = i+1 ; j<n ; ++j){
                int pos = j;
                int l = j+1 , h = n-1;
                while(l<=h){
                    int m = l + (h-l)/2;
                    
                    if(arr[m] < arr[i]+arr[j]){
                        pos = m;
                        l = m+1;
                    }else{
                        h = m-1;
                    }
                }
                
                cnt+=pos-j;
            }
        }
        
        return cnt;
    }
};