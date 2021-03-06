/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Aug 11, 2013
 Problem:    Simplify Path
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_71
 Notes:
 Given an absolute path for a file (Unix-style), simplify it.

 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"

 Corner Cases:
 Did you consider the case where path = "/../"?
 In this case, you should return "/".
 Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 In this case, you should ignore redundant slashes and return "/home/foo".

 Solution: Add an additional '/' at the end of 'path' for simply detecting the end.
 */

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        path += "/";
        size_t pos = path.find_first_of("/"), last = 0;
        while (pos != string::npos)
        {
            addPath(res, path.substr(last, pos - last));
            last = pos + 1;
            pos = path.find_first_of("/", last);
        }
        return res.empty() ? "/" : res;
    }

    void addPath(string &res, string s)
    {
        if (s.empty() || s == ".")
            return;
        if (s == "..") 
        {
            size_t index = res.find_last_of("/");
            if (index != string::npos)
                res.resize(index);
            return;
        }
        res = res + "/" + s;
    }
};
