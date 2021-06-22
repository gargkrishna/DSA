// problem link -> https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long a,b,i,j,k,n=nums.size();
        j=k=0;
        a=b=LONG_LONG_MIN;
        for(i=0;i<n;i++){
            if(a==nums[i]) j++;
            else if(b==nums[i]) k++;
            else if(j==0) a = nums[i],j++;
            else if(k==0) b= nums[i],k++;
            else j--,k--;
        }
        vector<int> v;
        j=k=0;
        for(i=0;i<n;i++){
           if(nums[i]==a) j++;
            if(nums[i]==b) k++;
        }
        if(j>n/3) v.push_back(a);
        if(k>n/3)v.push_back(b);
        return v;
    }
};

// time: O(n)
// space: O(1)