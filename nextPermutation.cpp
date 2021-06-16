// problem link -> https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void reverse(vector<int>& a,int i,int j){
        while(i<j) swap(a[i++],a[j--]);
    }
    void nextPermutation(vector<int>& nums) {
        int i,j,k,n=nums.size(),ind1=0;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind1 = i;
                break;
            }
        }
         for(i=n-1;i>=0;i--){
            if(nums[i]>nums[ind1]){
                swap(nums[i],nums[ind1]);
                break;
            }
        }
        if(i==-1) ind1=-1;
        reverse(nums, ind1+1,n-1);
    }
    
};

// time -> O(n)
// space -> O(1)