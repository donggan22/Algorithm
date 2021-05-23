#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x){
        char check = 1;
        int temp;
        string s = to_string(x);
        if(s[0] =='-')
            check = -1;
        std::reverse(s.begin(),s.end());
        try {
            temp = stoi(s);
        }catch(exception e){
            return 0;
        }
        return temp*check;
    }
};

/* Assume the environment dose not allow you to store 64-bit integers
 * using try-catch
 * std::to_string(x)
 * std::reverse()
 **/

//
// Created by Donggwan Koo on 2021/05/23.
//

