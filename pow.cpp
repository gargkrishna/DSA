// problem link -> https://leetcode.com/problems/powx-n/

class Solution {
public:
    double power(double x, int n){
            if(n==0) return 1;
            if(n==1) return x;
            double x1 = myPow(x,n/2);
            if(n%2) return x*x1*x1;
            else return x1*x1;
    }
    double myPow(double x, int n) {
       double x1 = power(x,abs(n));
        if(n>0) return x1;
        else return 1/x1;
    }
};

// time -> O(logn)
// space -> O(1)