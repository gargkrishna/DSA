// Sort the array which only contains 0, 1 and 2.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;  // take three pointers low, mid, high 
        while(mid<=high){
            if(nums[mid]==0)
                swap(nums[mid],nums[low]), low++, mid++;
            else  if(nums[mid]==2)
                swap(nums[mid],nums[high]), high--;
            else
                mid++;
        }
    }
};


// time complexity = O(n)
// space = O(1)