//  problem link ->https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    typedef long long ll;
    
    ll marge(ll a[],ll begin,ll mid,ll last){
        vector<ll> t1,t2;
        ll i,j,k,ans=0;
        for(i=begin;i<=mid;i++)
            t1.push_back(a[i]);
        for(i=mid+1;i<=last;i++)
            t2.push_back(a[i]);
        i=j=0;
        k = begin;
        while(i<t1.size()&&j<t2.size()){
            if(t1[i]>t2[j]){
                a[k]=t2[j];
                j++;
                k++;
                ans+=t1.size()-i;
            }
            else{
                a[k]=t1[i];
                i++;
                k++;
            }
        }
        while(i<t1.size()){
            a[k]=t1[i];
            i++;
            k++;
        }
        while(j<t2.size()){
            a[k]=t2[j];
            j++;
            k++;
        }
        return ans;
    }
    ll margeSort(ll a[],ll begin,ll last){
        if(begin<last){
            ll mid = (begin+last)/2;
            ll ans = margeSort(a,begin,mid);
            ans += margeSort(a,mid+1,last);
            ans += marge(a,begin,mid,last);
            return ans;
        }
        return 0;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return margeSort(arr,0,N-1);
    }

};



int main() {
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}