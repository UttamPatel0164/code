3446. Sort Matrix by Diagonals
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an n x n square matrix of integers grid. Return the matrix such that:

The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
The diagonals in the top-right triangle are sorted in non-decreasing order.
 

Example 1:

Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

Output: [[8,2,3],[9,6,7],[4,5,1]]

Explanation:



The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:

[1, 8, 6] becomes [8, 6, 1].
[9, 5] and [4] remain unchanged.
The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:

[7, 2] becomes [2, 7].
[3] remains unchanged.
Example 2:

Input: grid = [[0,1],[1,2]]

Output: [[2,1],[1,0]]

Explanation:



The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to [2, 0]. The other diagonals are already in the correct order.

Example 3:

Input: grid = [[1]]

Output: [[1]]

Explanation:

Diagonals with exactly one element are already in order, so no changes are needed.

 

Constraints:

grid.length == grid[i].length == n
1 <= n <= 10
-105 <= grid[i][j] <= 105
class Solution {
    public int[][] sortMatrix(int[][] a) 
    {
        int n=a.length,m=a[0].length;
        int i=n-2;
        while(i>=0)
        {
            int row=i,col=n-1;
            ArrayList<Integer> temp=new ArrayList<>();
            while(row>=0 && col>=0)
            {
                temp.add(a[row][col]);
                row--;
                col--;
            }
            Collections.sort(temp,Collections.reverseOrder());
            row=i;
            col=n-1;
            for(int x:temp)
            {
                a[row][col]=x;
                row--;
                col--;
            }
            i--;
        }
        i=n-1;
        while(i>=0)
        {
            int row=n-1;
            int col=i;
            ArrayList<Integer> temp=new ArrayList<>();
            while(row>=0 && col>=0)
            {
                temp.add(a[row][col]);
                row--;
                col--;
            }
            Collections.sort(temp);
            row=n-1;
            col=i;
            for(int x:temp)
            {
                a[row][col]=x;
                row--;
                col--;
            }
            i--;

        }
        return a;

    }
}