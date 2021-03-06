/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Problem:    Pascal's Triangle II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_119
 Notes:
 Given an index k, return the kth row of the Pascal's triangle.
 For example, given k = 3,
 Return [1,3,3,1].
 Note:
 Could you optimize your algorithm to use only O(k) extra space?

 Solution: from back to forth...
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal;
        for (int i = 0; i <= rowIndex; ++i)
        {
            for (int j = i - 1; j > 0; --j)
                pascal[j] += pascal[j-1];
            pascal.push_back(1);
        }
        return pascal;
    }
};
