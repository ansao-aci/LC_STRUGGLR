#include<iostream>
#include<deque>
#include<stack>

using namespace std;

/*
    1 > 2 > 3 > 4


    2 > 3 > 4  > -2 > -4 > -9

    inbox: -2 >  -4 > 9
    outbox: 4  >3 >2 
  
    enqueue: push to inbox.
    dequeue: pop from outbox. but if outbox is empty, dump inbox to outbox and then pop from outbox.

    problem: implement O(1) min function in queue. 
    solution: 
     implement a normal queue using two stack.
     maintain smin for each stack.
     to get qmin, take the min of  smin1, smin2. 

     push(x):
     smin1 = s1.empty()? x : min(smin1, x)
     s1.push(x);

     pop():
     if (s2.empty()){
         while(!s1.empty()){
             x  = s1.top().first
            smin2 = s2.empty()? x : min(smin2,x);
            s2.push((x,smin2));
            s1.pop();
         }
     }
     s2.pop();

     getMin();
     if (s1.empty() || s2.empty()):
         return s1.empty()?  s2.top().second : s1.top.second()

     return min(s1.top().second, s2.top().second)  


*/

class minQueue{
    public:
    stack<pair<int,int>> s1,s2;
    

    void push(int x){
        int smin1  = s1.empty() ? x : min(s1.top().second, x);
        s1.push({x, smin1});
    }

    void pop(){
        if (s2.empty()){
            while(!s1.empty()){
                int x = s1.top().first;
                int smin2 = s2.empty() ? x  : min (s2.top().second, x);
                s2.push({x,smin2});
                s1.pop();
            }
        }
        s2.pop();
    }

    int  top(){
        return s1.top().first;
    }

    int getMin(){
        if (s1.empty() || s2.empty()){
            return s1.empty() ? s2.top().second : s1.top().second;
        }
        return  min(s1.top().second,s2.top().second);
    }

};

class maxQueue{
    public:
    stack<pair<int,int>> s1,s2;
    

    void push(int x){
        int smax1  = s1.empty() ? x : max(s1.top().second, x);
        s1.push({x, smax1});
    }

    void pop(){
        if (s2.empty()){
            while(!s1.empty()){
                int x = s1.top().first;
                int smax2 = s2.empty() ? x  : max(s2.top().second,x);
                s2.push({x,smax2});
                s1.pop();
            }
        }
        s2.pop();
    }

    int  top(){
        return s1.top().first;
    }

    int getMax(){
        if (s1.empty() || s2.empty()){
            return s1.empty() ? s2.top().second : s1.top().second;
        }
        return  max(s1.top().second,s2.top().second);
    }

};

// min queue implementation without stacks

const int N = 1e5 + 100;

int a[N];
deque<int> dq;

int maxWindow() {
  int n, cq;
  scanf(" %d %d", &n, &cq);
  for (int i = 0; i < n; i++) {
    scanf(" %d", a + i);
  }
  for (int it = 0; it < cq; it++) {
    int d;
    scanf(" %d", &d);
    dq.clear();
    int best = 1 << 29;
    for (int i = 0; i < n; i++) {
      
      while (dq.size() && a[dq.back()] < a[i])
        dq.pop_back();
      
      dq.push_back(i);
      
      while (dq.size() && dq.front() <= i - d)
        dq.pop_front();
      
      if (i >= d - 1) {
        assert(dq.size());
        if (best > a[dq.front()]) {
          best = a[dq.front()];
        }
      }

    }
    printf("%d\n", best);
  }
  return 0;
}