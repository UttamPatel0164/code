3195. Find the Minimum Area to Cover All Ones I
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.

 

Example 1:

Input: grid = [[0,1,0],[1,0,1]]

Output: 6

Explanation:



The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

Example 2:

Input: grid = [[1,0],[0,0]]

Output: 1

Explanation:



The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

 

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 0 or 1.
The input is generated such that there is at least one 1 in grid.
class Solution {
    public int minimumArea(int[][] a) 
    {
        int n = a.length;
        int m = a[0].length;
        int mr = 1001, mc = 1001, lr = 0, lc = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 1) 
                    {
                        mr=Math.min(mr,i);
                        mc=Math.min(mc,j);
                        lr=Math.max(lr,i);
                        lc=Math.max(lc,j);
                     
                    }
                }
            }    
        int row = lr - mr + 1;
        int col=lc-mc+1;
        System.out.println(row + " " + mc); 
        return row * col;  
    }
}
