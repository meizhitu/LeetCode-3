/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Problem:    Integer to Roman
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_12
 Notes:
 Given an integer, convert it to a roman numeral.
 Input is guaranteed to be within the range from 1 to 3999.

 Solution: Buffer the roman numbers.
 */

class Solution {
public:
    const string rom[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                               {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                               {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                               {"", "M", "MM", "MMM"}};
    string intToRoman(int num) {
        string res;
        int i = 3;
        while (num > 0)
        {
            int divisor = (int)pow(10, i);
            res += rom[i][num / divisor];
            num %= divisor;
            i--;
        }
        return res;
    }
};
