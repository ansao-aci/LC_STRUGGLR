#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;


// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}


class Spliter{
    public:
    void split(string A, char delim, vector<string> &res);
};

void Spliter::split(string A, char delim, vector<string>&res){
    trim(A);
    stringstream ss(A);
    string item;
    while(getline(ss, item, delim)){
        if(item.size()) res.push_back(item);
    }
}

/*

Problem : To fine length of longest substring in a string containing unique characters.
Solution:
 BF solution is O(n^3). With little modification, can be improved to O(n^2)
 Optimized solution is O(2n). Further optimization gives us O(n) solution. 

Two pointer  and sliding window solution:
Invariant: Windows always contains substring with unique characters.

Start two pointers on the string and stretch right till we encounter a duplicate. 


Duplication can only occure due to character at right. 

How to quickly check if invariant is broken? Check frequency of character pointed by right. 
(Naive way to be traverse whole map and check frequency of each character)

To maintain the invariant condition, move left till all characters are unique again.
We have to increment left till character at right is unique again. 

Length of the substring is rigth-left+1.
Maintain a variable to tracks the maximum lenght of the substring.


Further Optimization:
Once we hit a duplicate, we slip left ptr one by one till substring becomes unique again.
This takes O(n)  time. 
Instead of this, if we had a map of char pointing to next index.  We can use the map to find
the next index of the duplicate and set left to it. Time taken is O(1).


*/
class longestSubstring{
    public:
    static int solution(string  A){

        return 1;
    }
};



/*
Problem: Find the longest palindromic substring. 
Solution: 
Reverse the string and find longest common substring is incorrect.
Solution fails for the case if the reverse of the string occurs in somwhere in the input

Using the palindromic nature P(i,j) = true if P(i-1,j-1) && S[i] == S[j].
We precalculate P[n][n]. Iterate though every possible start and end indices of all substring
and track the longest substring.  

Total time is : O(n^2 + n^2) == O(n^2). Space : O(n^2)

Further optimization:
Finding maximum length of a substring that can be formed around at center can be done in O(n).
There are n centers in the string.
Hence total time taken is O(n^2) and space taken in O(1). 
We just need to make sure to count even and odd length palindromes from any center.



*/
class longestPalindromicSubstring{
    public:
    static string solution(string A);
};
