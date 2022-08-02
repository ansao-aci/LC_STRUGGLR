#include <vector>
#include <numeric>

using namespace std;
namespace matrix{

    class Solution{

        public:

        long long gridgame(vector<vector<int>> &G);
    };

/*
1. determine i, where first robot will  go down.
2. second robot will either go down or stay up.
3. answer will be max (down[i-1],  up[i+1]) 

*/

    long long Solution::gridgame(vector<vector<int>>&G){
        long long top = accumulate(begin(G[0]), end(G[0]), 0LL), bottom = 0, ans =0;
        
        int n = G[0].size();
        for (int  i =0;i<n;i++){
        top -=  G[0][i];
        ans = min(ans,max(top, bottom));
        bottom += G[1][i];
        }

    }


    class setMatrixZeros{
        public:
        void setZero(vector<vector<int>> &A);
    };


    /*
    Problem: Mark all  row elements and column elements 0  if that row/column contains atleast one 0.
    Solution: 
    
    TC O(m*n) , SC is the one needs to be optimized. SC O(mn) and O(m+n) and O(m) is easy to come to.
    SC O(1) is tricky. 

    In solutions with SC O(mn), O(m+n) we use extra space to mark which  row and column need to be all zeroed.
    In SC O(1), we use the matrix itself to keep that information. We mark first element of row and column 0 if
    it is to be all zeroed. We travsere the matrix and mark all zero to the elements of rows and column whose first element is zero.

    There are two issues with this approach:

    #1 Issue is if 0,0 is marked 0, and 0th row is all zeroed, then information about columns which need to be zeroed is lost.
    Similarly, 0th column is all zeroed, then information about  rows which needs to zeroed is lost. 

    0th row and 0th column needs to be zeroed at last, to preserve information.
    
    #2 Issue  Meaning of A[0][0] = 0 is ambiguous. It could mean three things
    1. 0th row needs to be zeroed.
    2. 0th column needs to be zeroed.
    3. Both 0th row and column needs to be zeroed.

    Two booleans needs to be maintaind which stores whether 0th row and 0th column needs to be zeroed.
    
    First mark all zeroes in column 1 to n-1 whose first element is 0.
    Then mark all rows from 1 to m-1 whose first element is 0.

    Now, based on the information  of two booleans, mark 0th row and 0th col as all zero.

    */ 
    void setMatrixZeros::setZero(vector<vector<int>> &A){
        int  m = A.size();
        if (m==0) return;
        
        int n = A[0].size();
        
        bool row0=false,col0=false;
        
        
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                if (!A[i][j]){
                    A[i][0] = 0;
                    A[0][j] = 0;
                    
                    if (!i) row0=true;
                    if (!j) col0=true;
                }
            }
        }
        
        for(int j=1; j<n; j++){
            if (!A[0][j]) for(int  i=0;i<m;i++)A[i][j]=0;
        }
        
        for(int i=1; i<m; i++){
            if (!A[i][0]) for(int  j=0;j<n;j++)A[i][j]=0;
        }
        
        if (row0){
            for(int  j=0;j<n;j++) A[0][j] = 0;
        }
        
        
        if (col0){
            for(int  i=0;i<m;i++) A[i][0] = 0;
        }    
    }

}