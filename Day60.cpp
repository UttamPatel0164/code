Count Reverse Pairs
Difficulty: HardAccuracy: 50.0%Submissions: 11K+Points: 8
You are given an array arr[] of positive integers, find the count of reverse pairs. A pair of indices (i, j) is said to be a reverse pair if both the following conditions are met:

0 ≤ i < j < arr.size()
arr[i] > 2 * arr[j]
Examples:
Input: arr[] = [3, 2, 4, 5, 1, 20]
Output: 3
Explanation:
The Reverse pairs are 
(0, 4), arr[0] = 3, arr[4] = 1, 3 > 2*1 
(2, 4), arr[2] = 4, arr[4] = 1, 4 > 2*1 
(3, 4), arr[3] = 5, arr[4] = 1, 5 > 2*1 
Input: arr[] = [5, 4, 3, 2, 2]
Output: 2
Explanation:
The Reverse pairs are
(0, 3), arr[0] = 5, arr[3] = 2, 5 > 2*2
(0, 4), arr[0] = 5, arr[4] = 2, 5 > 2*2
Constraints:
1 ≤ arr.size() ≤ 5*104
1 ≤ arr[i] ≤ 109

class Solution {
public:
    int merge(vector<int> &a, int low, int mid, int high) {
        int cnt = 0;

        // Count reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)a[i] > 2LL * a[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        // Merge two sorted halves
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (a[left] <= a[right])
                temp.push_back(a[left++]);
            else
                temp.push_back(a[right++]);
        }
        while (left <= mid) temp.push_back(a[left++]);
        while (right <= high) temp.push_back(a[right++]);

        // Copy sorted elements back
        for (int i = low; i <= high; i++) {
            a[i] = temp[i - low];
        }

        return cnt;
    }

    int ms(vector<int> &a, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2;
        int cnt = 0;
        cnt += ms(a, low, mid);
        cnt += ms(a, mid + 1, high);
        cnt += merge(a, low, mid, high);
        return cnt;
    }

    int countRevPairs(vector<int> &a) {
        return ms(a, 0, a.size() - 1);
    }
};
