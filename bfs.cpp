#include<iostream>
#include<stack>
#include<set>
#include<unordered_map>
#include<sstream>
#include<string>

#include  "int_overflow.h"
#include "transform_use.h"
#include "Tree.h"
#include "linked_list.h"
#include "min_stack.h"
#include "queue_stack.h"
#include "sliding_window_max.h"
#include "palindrome_int.h"

#include<cmath>
#include "slidingWindow.h"
#include "string_problem.h"
#include "level_order_queue.h"
#include "comparator.h"
#include "array_problems.h"
#include "combinations.h"
#include "binary_search.h"

using namespace std;


#define nl cout<<endl

shared_ptr<ListNode<int>> makeList(vector<int> A){
    auto h1 = make_shared<ListNode<int>> (ListNode<int>{0});
    auto t = h1;
    for(int a:A){
        t->next = make_shared<ListNode<int>>(ListNode<int>{a});
        t = t->next;
    }
    return h1->next;
}


void printVector(vector<int>&A){
    for_each(A.begin(), A.end(), [](int i) {
        cout << i << " ";
    });
    cout << endl;
}

int main(){

    
    auto comp = [](int a, int b){
        return a < b;
    };

    priority_queue<int, vector<int>, decltype(comp)> pq(comp);

    pq.push(10); pq.push(4);pq.push(5);pq.push(1);

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }

    cout<<endl;

    vector<int> A= {2,4,4,8};
    int ans = bsearchns::lower_bound(A, 10);
    int ans2 = bsearchns::upper_bound(A, 1);
    cout << "lower bound index: " << ans << endl;
    cout << "upper bound index: " << ans2 << endl;

    cout << endl;

    
    auto comp1 = [] (pair<int,int> A, pair<int,int>B){ return A.first > B.first;};
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp1)> pq1(comp1);

    vector<pair<int,int> > B = { {1,3}, {2,6}, {8,10}, {15,18}};
    for (auto p : B){
        pq1.push(p);
    }

    while(!pq1.empty()){
        cout << pq1.top().first << " , " << pq1.top().second << endl;
        pq1.pop(); 
    }


        
    return 0;
}