#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<deque>


using  namespace std;

class slideWindowMax{
    public:

    vector<int> solution1(vector<int>&A, int  k);
    vector<int> solution2(vector<int>&A, int  k);
    vector<int> solution3(vector<int>&A, int  k);
};


/*
    create a PQ  with  {A[i],i}, priority is decided by its value.(not by index)
    0 k n-1
    pop elements if  they are out of window.
    push new elemet.
    store top

    1  2 3 4 5 6   k=3

    (1,0) (2,1) (3,2) ,(4,3),(5,4),(6,5)

    {3,4,5,6}

*/

vector<int>  slideWindowMax::solution1(vector<int> &A,  int  k){
    vector<int> res;

    priority_queue<pair<int,int>> pq;

    int  n = A.size();
    for(int i=0; i<n; i++){
        if (i<k)  pq.push({A[i],i});

        while(pq.size() &&  pq.top().second  <=  i-k) pq.pop();
        pq.push({A[i],i});

        if(i>=k-1) res.push_back(pq.top().first);
    }
    return res;
}

/*

multiset: multiset can  store muliple  keys of same value.

insert elements till  k-1.
for  each new element, remove (i-k)th element erase
and take the max.

*/

vector<int>  slideWindowMax::solution2(vector<int> &A,  int  k){
    vector<int> res;
    multiset<int> mset;

    for(int i=0,n=A.size(); i<n; i++){
        mset.insert(A[i]);
        if (i>=k) mset.erase(mset.find(A[i-k]));

        if (i>=k-1) {
            res.push_back(*mset.rbegin());
        }
    }
    return res;
}


/*
    maintain a deque whose head contains index of the maximum value of the window.

    i<k, insert all elements to deque.

    i>=k  
    insert A[i] while popping A[j] from back where A[j]<A[i]

    pop from front where j <= i-k  

    save front index element as the maximum.

   0 1 2 3 4 5
   1 2 3 4 5 6

   3 
*/

vector<int>  slideWindowMax::solution3(vector<int> &A,  int  k){
    vector<int> res;
    deque<int> dq;

    for(int  i = 0, n = A.size() ; i < n ; i++){
        while(dq.size() && A[dq.back()] < A[i]) dq.pop_back();
        dq.push_back(i);

        while(dq.front() <= i-k) dq.pop_front();

        if  (i>=k-1) res.push_back(A[dq.front()]);
    }
    return res;
}