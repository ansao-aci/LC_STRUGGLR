#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
        int m = l + (r - l) / 2, ml = 0, mr = 0;
        int lmax = maxSubArray(nums, l, m - 1);
        int rmax = maxSubArray(nums, m + 1, r);
        for (int i = m - 1, sum = 0; i >= l; i--) {
            sum += nums[i];
            ml = max(sum, ml);
        }
        for (int i = m + 1, sum = 0; i <= r; i++) {
            sum += nums[i];
            mr = max(sum, mr);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
};



/*
[-2,1,-3,4,-1,2,1,-5,4] 6


[1]  1


[5,4,-1,7,8] 23

kadane algorithm! yes

divide and conquer

contiguous subarray with largest sum

0  1  2  3 

[-1,4,5,-2]

[4,-1,-2,5]

1. for any range, split it in half,
2. calculate max-subarray-sum for left part
3. max-subarray-sum for right part
4. maxsubarray starting from middle. can this be optimized?


mleft[i]  =  max(sum[i --> i,i-1,i-2...b])
mright[i]  = max (sum[i  -->i,i+1,i+2  ..e])

mleft[i][b]    b (0,1,2,3,i-1)

2 -1 2 -3 4
2  1 3  0 4


for(int i =0;i<n;i++){
    tmp = int_min;    
    for(int j=i;j>=0;j--){
     rs = s[i]-s[j]+nums[j];
     mleft[i][j] = max(tmp, rs);
     tmp = max(tmp,rs);
    }
}


for(int i=0;i<n;i++){
    tmp = int_min;
    for(int j=0;j<n;j++){
        rs = s[j]-s[i]+nums[i]
        mright[i][j] = max(tmp,   rs);
        tmp = max(tmp,rs);
    }
}


mright[i][e]    e(i+1,i+2, e)



*/
class SaoSolution {

public:
    
    vector<vector<int>> mleft,mright;
    vector<int>s;
    

    int maxSubSum(vector<int>& nums, int b, int e){
        
        if (b==e) return nums[b];
        int ans = INT_MIN,  m = b + (e-b)/2;
        
        int lmax = maxSubSum(nums, b, m);
        int rmax =  maxSubSum(nums, m+1, e);
        
        ans = max(lmax,rmax);
        int mid = mleft[m][b] + mright[m+1][e];
        return max(ans,mid);
    }
    
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        s.resize(n);
        
        int tmp=0;
        for(int i=0;i<n;i++){
            s[i]   =  nums[i]+tmp;
            tmp =  s[i];
        }
         
        mleft.resize(n,vector<int>(n));
        mright.resize(n,vector<int>(n));
        
        for(int i =0;i<n;i++){
            
            tmp = INT_MIN;    
            for(int j=i;j>=0;j--){
                int rs = s[i]-s[j]+nums[j];
                mleft[i][j] = max(tmp, rs);
                tmp = max(tmp,rs);
            }
        }


        for(int i=0;i<n;i++){
        
            tmp = INT_MIN;
            for(int j=i;j<n;j++){
                int rs = s[j]-s[i]+nums[i];
                mright[i][j] = max(tmp, rs);
                tmp = max(tmp,rs);
            }
        }

        return maxSubSum(nums, 0, n-1);
    }
};


/*
Buy/sell/cool-down stocks to maximize profit.

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)

My O(n^2) took 100ms. 
There is O(n) solution.
*/

class profitStocks {
public:
    int maxProfitnsq(vector<int>& prices) {
        vector<int> &p = prices;
        
        int mp[5001]; mp[0] = 0; int n = prices.size();
        
        for(int j=1; j<n; j++){
            
            int max_sell = 0;
            
            for(int i = 0; i < j; i++){
                int sell = p[j] - p[i];
                if (i>1) sell += mp[i-2];
                max_sell = max(max_sell, sell);
            }
            int not_sell = mp[j-1];
            mp[j] = max(not_sell, max_sell);
        }
        
        return mp[n-1];
    }

    int maxProfitns(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
		vector<int> s0(prices.size(), 0);
		vector<int> s1(prices.size(), 0);
		vector<int> s2(prices.size(), 0);
		s1[0] = -prices[0];
		s0[0] = 0;
		s2[0] = INT_MIN;
		for (int i = 1; i < prices.size(); i++) {
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
			s2[i] = s1[i - 1] + prices[i];
		}
		return max(s0[prices.size() - 1], s2[prices.size() - 1]);
    }

};


class trapRainWater{
    public:
    int getTrappedWater(vector<int> &A);
};

int trapRainWater::getTrappedWater(vector<int> &height){
    int n = height.size();
    int left = 0, right = n-1;
        
    int left_max = INT_MIN, right_max = INT_MIN;
        
    int ans  = 0;
        
    while (left < right){
        if (height[left] < height[right]){
               
            left++;
            }else{

        right--;
            }
        }
        return ans;
        
}