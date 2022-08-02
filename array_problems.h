#include<vector>
#include<iostream>


using namespace std;


/*
https://leetcode.com/problems/increasing-triplet-subsequence/


Problem: To tell whether an array of integers contains an increasing triplet subsesequence or not? Return a bool.

Solution: Tried with next-greater-element ,  stack, priority_queue, binary search tree, hashtable, nothing worked.
Turns out there is a simple linear non intuitive clever solution for this problem. 

Algorithm:
We maintain two trackers C1 and C2. 

Till ith index, 
C1 contains the smallest element found till i,
C2 contains smallest element to the right of C1, greater than C1.

Once C2  is populated, we can be sure that a C1 exists satisfying C1<C2.
If we find an element A[k] satisfying A[k] > C2,  we conclude increasing triplet subsequence exists.
Else, the  array doesn't contains ITS.  

*/

class ITS{

    public:
    bool solution(vector<int> &A);
};

