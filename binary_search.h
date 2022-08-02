#ifndef BSEARCH_H
#define BSEARCH_H

#include<vector>
#include<iostream>

using namespace std;
namespace bsearchns{

int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}

int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid =  l + (h - l) / 2;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}


int upper_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int mid = (r-l)/2+l;
        if (nums[mid] > target)
            r = mid-1;
        else
            l = mid+1;
    }
    return l;
}


// find pivot in a sorted array rotated at some index.
int findPivot(vector<int>&A){
    int n  = A.size();
    int  l = 0 , r = n-1;
    while (l < r){
        int m = l + (r - l)/ 2;
        if (A[m] < A[r]){
            r = m;
        } else{
            l = m+1;
        }
    }
    return l;
}

}
#endif