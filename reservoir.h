#include<vector>

using namespace std;

// blog_material

class Solution {
public:
    vector<int>A;
    Solution(vector<int>& nums) {
        this->A = nums;
        
    }
    
    vector<int> reset() {
        return A;
    }
    
    static int myrandom (int i) { return rand()%i;}
    vector<int> shuffle() {
        vector<int> B(A);
        
        int  n = B.size();
        
        for(int i=0; i<n;i++){
            int pos = rand() % (n-i);
            swap(B[i],B[i+pos]);      //i+pos <= n-1   rand() % (n-i)
        }
        return B;
    }
};