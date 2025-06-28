Counting elements in two arrays
You are given two unsorted arrays a[] and b[]. Both arrays may contain duplicate elements. For each element in a[], your task is to count how many elements in b[] are less than or equal to that element.

Examples:

Input: a[] = [4, 8, 7, 5, 1], b[] = [4, 48, 3, 0, 1, 1, 5]
Output: [5, 6, 6, 6, 3]
Explanation: 
For a[0] = 4, there are 5 elements in b (4, 3, 0, 1, 1) that are ≤ 4.
For a[1] = 8 and a[2] = 7, there are 6 elements in b that are ≤ 8 and ≤ 7.
For a[3] = 5, there are 6 elements in b that are ≤ 5.
For a[4] = 1, there are 3 elements in b (0, 1, 1) that are ≤ 1.
class Solution {
  public:
    int fun(vector<int> b,int k)
    {
        int low=0,high=b.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(b[mid]<=k)
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
    }
    vector<int> countLessEq(vector<int>& a, vector<int>& b) 
    {
        sort(b.begin(),b.end());
        vector<int> ans;
        for(int i:a)
        {
            ans.push_back(fun(b,i)+1);
        }
        return ans;
    }
};