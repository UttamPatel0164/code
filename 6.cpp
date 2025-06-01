// Count pairs Sum in matrices
// Difficulty: EasyAccuracy: 45.66%Submissions: 52K+Points: 2
// Given two matrices mat1[][] and mat2[][] of size n x n, where the elements in each matrix are arranged in strictly ascending order. Specifically, each row is sorted from left to right, and the last element of a row is smaller than the first element of the next row.
// You're given a target value x, your task is to find and count all pairs {a, b} such that a is from mat1 and b is from mat2 where the sum of a + b is equal to x.

// Examples:

// Input: n = 3, x = 21,
// mat1[][] = [[1, 5, 6], [8, 10, 11], [15, 16, 18]],
// mat2[][] = [[2, 4, 7], [9, 10, 12], [13, 16, 20]]
// OUTPUT: 4
// Explanation: The pairs whose sum is found to be 21 are (1, 20), (5, 16), (8, 13) and (11, 10).
class Solution {
  public:
    int countPairs(vector<vector<int>> &m1, vector<vector<int>> &m2, int x) 
    {
        int n=m1.size();
        int i=0, j=0;
        int k=n-1,l=n-1;
        int ctr=0;
        while(1)
        {
            int a=m1[i][j];
            int b=m2[k][l];
            if(a+b==x)
            {
                ctr ++;
                j++;
                l--;
            }
            else if((a+b)<x)
            {
                j ++;
            }
            else
            {
                l--;
            }
            if(j==n)
            {
                i++;
                j=0;
            }
            if(l==-1)
            {
                k --;
                l=n-1;
            }
            if(i==n || k==-1)
                break;
        }
        return ctr;
        
    }
};