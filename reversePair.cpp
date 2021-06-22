// problem link :- https://leetcode.com/problems/reverse-pairs/


class Solution {
public:
    vector<int> v;
    long long marge(int begin,int mid,int end,vector<int>& nums){
        long long n=mid-begin+1,m=end-mid,i,j,k,ans=0;
        long long a[n],b[m];
        j = begin;
        for(i=0;i<n;i++) a[i]=nums[j++];
        for(i=0;i<m;i++) b[i]=nums[j++];
        i=j=0;
        while(i<n){
           while(j<m&&a[i]>2*b[j]){
                j++;
           }
            ans+=j;
            i++;
        }
        i=j=0;
        k = begin;
        while(i<n&&j<m){
            if(a[i]>b[j]){
                nums[k++]=b[j++];
            }
            else nums[k++]=a[i++];
        }
        while(i<n){
           nums[k++]=a[i++];
        }
         while(j<m){
            nums[k++]=b[j++];
        }
        return ans;
    }
    
    int margeSort(int begin,int end,vector<int>& nums){
        int ans=0;
        if(begin<end){
            int mid = (begin + end)/2;
            ans = margeSort(begin,mid,nums);
            ans+=margeSort(mid+1,end,nums);
            ans+=marge(begin,mid,end,nums);
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return margeSort(0,nums.size()-1,nums);
    }
};


// time O(n)
// space O(n)