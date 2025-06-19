Case-specific Sorting of Strings
Given a string s consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

Examples :

Input: s = "GEekS"
Output: EGekS
Explanation: Sorted form of given string with the same case of character will result in output as EGekS.
Input: s = "XWMSPQ"
Output: MPQSWX
Explanation: Since all characters are of the same case We can simply perform a sorting operation on the entire string.
class Solution {
public:
    string caseSort(string &s) {
        string upper, lower;

        for (char c : s) {
            if (isupper(c))
                upper += c;
            else
                lower += c;
        }

        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());

        int u = 0, l = 0;
        string result = "";

        for (char c : s) {
            if (isupper(c))
                result += upper[u++];
            else
                result += lower[l++];
        }

        return result;
    }
};
