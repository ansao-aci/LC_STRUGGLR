#include<iostream>
#include<stack>

using namespace std;
//blog_material

class minStack{
    public:
        stack<long long> st;
        long long smin;

        void push(int x){
            long long val = (long long) x;
            if (st.empty()){
                st.push(0L);
                smin = val;
            }else{
                long long ps = val - smin;
                if (ps < 0) smin  = val;
                st.push(ps);
            }
        }
       
       int min(){
           return smin;
       }
        void pop(){
            int pp = st.top(); 
            if (pp < 0) smin = smin - pp;
        }

        int top(){
            long long tp = st.top();
            if (tp < 0 ) return smin;
            else return tp + smin;  
        }

};

class MinStack {
public:
    stack<long long>st;
    long long smin;
    
    MinStack() {
    }
    
    void push(int val) {
        long long x  = val;
        if (st.empty()){
            smin = x;
            st.push(x);
        } else if (x >= smin){
            st.push(x);
        } else{
            st.push(2*x-smin);
            smin   = x;
        }
    }

    void pop() {
        long long tp = st.top();
        if (tp < smin) smin  = 2*smin - tp;
        st.pop();
    }
    
    int top() {
      
        long  long tp = st.top();
        if (tp < smin)  return  smin;
        else return tp;
    }
    
    int getMin() {
        return smin;
    }
};


/*

https://www.techiedelight.com/design-a-stack-which-returns-minimum-element-without-using-auxiliary-stack/

x < min
top = 2*x -min 
min  = x

a , b
a < b

a-b           

t < b   composed  of a and b
a     t  = 2a-b  b:oldMin a:newMin
  
-3, 5 , -6,2



t  = 2a-b
b= 2a-t


minStack two:
along with all operation of stack, implement getMin with O(1)

push() : x > min, push(x);   x < min, push(2*x - min);   newMin = x;

pop(): x > min, pop(x);  x < min,  orig  = min. min = 2*min - top;

top(): x > min, top(x); x < min, return min;


time complexity discussion:


*/