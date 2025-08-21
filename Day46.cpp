Make Matrix Beautiful
Difficulty: MediumAccuracy: 64.75%Submissions: 59K+Points: 4Average Time: 20m
A beautiful matrix is defined as a square matrix in which the sum of elements in every row and every column is equal. Given a square matrix mat[][], your task is to determine the minimum number of operations required to make the matrix beautiful.
In one operation, you are allowed to increment the value of any single cell by 1.

Examples:

Input: mat[][] = [[1, 2], 
                [3, 4]]
Output: 4
Explanation:
Increment value of cell(0, 0) by 3, 
Increment value of cell(0, 1) by 1. 
Matrix after the operations: [[4, 3], 
                            [3, 4]]
Here, sum of each row and column is 7.
Hence total 4 operation are required.
class Solution {
  public:
    int balanceSums(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int maxi=0;
        for(int row=0;row<n;row++)
        {
            int sum=0;
            for(int col=0;col<m;col++)
            {
                sum+=a[row][col];
            }
            maxi=max(maxi,sum);
        }
        for(int col=0;col<n;col++)
        {
            int sum=0;
            for(int row=0;row<m;row++)
            {
                sum+=a[row][col];
            }
            maxi=max(maxi,sum);
        }
        int ans=0;
        for(int row=0;row<n;row++)
        {
            int sum=0;
            for(int col=0;col<m;col++)
            {
                sum+=a[row][col];
            }
            ans+=(maxi-sum);
        }
        for(int col=0;col<n;col++)
        {
            int sum=0;
            for(int row=0;row<m;row++)
            {
                sum+=a[row][col];
            }
            ans+=(maxi-sum);
        }
        return ans/2;
        
        
    }
};