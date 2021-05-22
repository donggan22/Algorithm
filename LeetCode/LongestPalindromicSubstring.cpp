#include <string>

using namespace std;


string findPalindrome(int lIdx, int rIdx, string s) {
    string palindrome = "";
    while (lIdx >= 0 && rIdx < s.length()) {
        if (s[lIdx] == s[rIdx]) {
            lIdx--;
            rIdx++;
        } else {
            palindrome = s.substr(lIdx + 1, rIdx - lIdx - 2);
            return palindrome;
        }
    }
    palindrome = s.substr(lIdx + 1, rIdx - lIdx - 2);
    return palindrome;
}

class Solution {
public:
    string longestPalindrome(string s) {
        string ans ="";
        for(int i = 0 ; i < s.length() ; i++) {
            string palindrome = findPalindrome(i, i, s);
            if (palindrome.length() > ans.length())
                ans = palindrome;
            if (i < s.length() - 1) {
                if (s[i] == s[i + 1]) {
                    palindrome = findPalindrome(i, i + 1, s);
                    if (palindrome.length() > ans.length())
                        ans = palindrome;
                }
            }
        }
        return ans;
    }
};
/* string s = "0123456789";
 * s.substr(2,3) = "234" 2 : startIDX , 3: substrs length
 */
//
// Created by donggwan.koo on 2021/05/22.
//

