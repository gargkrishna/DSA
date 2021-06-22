// problem link:= https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int dp[105][105];
    int foo(int m,int n){
        if(m==1||n==1) return 1;
        if(dp[m][n]==-1) dp[m][n]=foo(m-1,n)+foo(m,n-1);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        // memset(dp,-1,sizeof(dp));
        // return foo(m,n);
        long long i,k=m+n-2;
        double j=1;
        for(i=m-1;i>0;i--){
            j= j * k--;
            j = j / i;
        }
        return round(j);
    }
};

// time: O(n)
// space: O(1)