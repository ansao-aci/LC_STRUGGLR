#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace  std;
/*

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/

*/

class int_overflow{
    public:

    int reverse(int a);
};

int int_overflow::reverse(int a){

    cout << "int_max: " << INT32_MAX << endl;
    cout << "int_min: " << INT32_MIN << endl;
    int res  = 0;

    while (a){
        int pop = a % 10;
        a  = a/10;

        int temp = res*10 + pop;     

         // res * 10  + pop > int32_max   
        // res  > (int32_max  - pop )/ 10  
         //  res == int32_max/ 10 && pop > 7    overflow
         // res < int32_max /10  ok
         // res > int32_max / 10 overflow 

         // res  == intr32_min / 10 && pop > 8  overflow
         // res  > int32_min / 10  ok
         // res < int32_min / 10   overflow
        

        if  ((res > INT32_MAX / 10 ) || (res == INT32_MAX / 10 && pop > 7 )) { 
            return -1;
        }
        if ( (res < INT32_MIN / 10 ) || ( res == INT32_MIN / 10 && pop < -8)) {
            return -1;
        }

        res =  temp;

    }

    return res;

}

/*
link  to get related questions.

https://leetcode.com/problems/perfect-squares/



Return least number of sqaures needed to make sum of n.
12  = 4+4+4  < 9+1+1+1   == 3
11  = 9+1+1  = 2
10  = 9+1 = 2

axiom : n is positive integer.
Solution: 
  This problem can be solved by dynamic programming. 
  It has optimal substructure and overlapping subproblems. 
  dp[12] = min (1 + dp[3], 1+ dp[9], 1 + dp[11])  (1,4,9)
  dp[10] = min(1+dp[6], 1+dp[9], 1+dp[1])
  
  for all j , where j*j <= i
  dp[i] = min (dp[i], 1 + dp[i-j*j])

  using above recurrence relation, calculate and return dp[n]

  Solution1 time taken is 12ms although algorithm is same. 
  Used static vector.
  using above recurrence relation, calculate and return dp[n].
  If we use non-static vector for memoization, time taken shoots up to ~200ms.
  If we make it static, it is down to ~10ms. Static vector preserves its state across 
  function calls hence we can reuse results computed in earlier function calls.


Solution using bfs:
put all square upto n in VecS;
put all sqaure upto n in Q;

till Q is empty, combine every element in Q with VecS
and create new elements, count of sqaure depends upon number of pops 
done from Q.
if the new element is n, return count.
if new element is < n, preserve count and push element to Q.
if new element is > n, ignore this and any elements later this. 


*/

class leastSquareSum{
    public:
    int solution1(int n);
    int solution2(int n);
};
int leastSquareSum::solution1(int n){
    int m = sqrt(n);
    if (m*m == n) return 1;
        
    static vector<int> dp(10001,INT_MAX);  dp[0] = 0; dp[1] = 1;
    if (dp[n]!= INT_MAX) return dp[n];

    for(int i=2;i<=n;i++){
        for(int  j=1;j*j<=i;j++) {
            dp[i] = min(dp[i], 1+ dp[i-j*j]);
        }
    }
    return dp[n];
}

int leastSquareSum::solution2(int n){
    vector<int> perfectSquares;
    vector<int> cntPerfectSquares(n+1);
        
    for (int i = 1; i*i <= n; i++)
    {
        perfectSquares.push_back(i*i);
        cntPerfectSquares[i*i] = 1;
    }
        
    if (perfectSquares.back() == n)
    {
        return 1;
    }
        
    queue<int> searchQ;
    for (auto& i : perfectSquares)
    {
        searchQ.push(i);
    }
        
    int currCntPerfectSquares = 1;
    while (!searchQ.empty())
    {
        currCntPerfectSquares++;
        for (int i = 0; i < searchQ.size(); i++){
            int tmp = searchQ.front();
            for (auto& j : perfectSquares){
                if (tmp + j == n){
                    return currCntPerfectSquares;
                }
                else if ((tmp + j < n) && (cntPerfectSquares[tmp + j] == 0)){
                    cntPerfectSquares[tmp + j] = currCntPerfectSquares;
                    searchQ.push(tmp + j);
                }
                else{
                    break;
                }
            }
            searchQ.pop();
        }
    }        
    return 0;
}
