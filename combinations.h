#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void comb(int i, int k,  vector<int> &A, vector<int>&res, set<string> &ans){
    int n = A.size();
    if ( k == res.size()){
        stringstream tmp; 
        copy (res.begin(), res.end(), ostream_iterator<int> (tmp));
        ans.insert(tmp.str());
        return ;
    }

    if (i >= n  || res.size() > k) return;

    for (int x = i ; x < n ; x++){
        res.push_back(A[x]);
        comb (x+1, k, A, res, ans);
        res.pop_back();
    }
}


void comb1(int i , int k,  vector<int> &A, vector<int> &res, set<string> &ans){
    int n = A.size();
    if ( k == res.size() ) {
        stringstream tmp; 
        copy (res.begin(), res.end(), ostream_iterator<int> (tmp));
        ans.insert(tmp.str());
        return ;
    }

    if (i >= n  || res.size() > k) return;
    res.push_back(A[i]);
    comb1(i+1, k, A, res, ans);

    res.pop_back();
    comb1(i+1, k, A, res, ans);

}


#endif
