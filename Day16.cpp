Minimum sum
Given an array arr[ ] consisting of digits, your task is to form two numbers using all the digits such that their sum is minimized. Return the minimum possible sum as a string with no leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: "604"
Explanation: The minimum sum is formed by numbers 358 and 246.
class Solution {
  public:
    string addStrings(string num1, string num2) {
        string result = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';

            result += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        string a = "", b = "";
        int x=0;
        for (int i = 0; i < arr.size(); i++) 
        {   if(arr[i]==0)
                continue;
            if (x % 2 == 0)
                b += to_string(arr[i]);
            else
                a += to_string(arr[i]);
            x++;
        }

        return addStrings(a, b);
    }
};
