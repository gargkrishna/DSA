
// problem link -> https://leetcode.com/problems/find-the-duplicate-number/solution/
// By sorting
// By mapping
// By Floyd's Tortoise and Hare (Cycle Detection)
// By sum all the numbers and minus by n(n+1)/2;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare=nums[0],tortoise=nums[0];  // set the value of hare and tortoise to array first value.
        tortoise = nums[tortoise];
        hare  = nums[nums[hare]];
        while(hare!=tortoise){     
            tortoise = nums[tortoise];   // tortoise takes 1 step
            hare  = nums[nums[hare]];  // hare takes 2 step
        }
        tortoise = nums[0];   // set tortoise to starting position
        while(hare!=tortoise){
            tortoise = nums[tortoise];   // now both takes 1 step ahead
            hare  = nums[hare];
        }
        return hare;
    }
};

// time complexity = O(n)
// space complexity = O(n)