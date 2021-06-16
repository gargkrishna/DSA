#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << ": " << x << "\n"
#define deb2(x, y) cout << #x << ": " << x << "\t" << #y << ": " << y << "\n"
#define deb3(x, y, z) cout << #x << ": " << x << "\t" << #y << ": " << y << "\t" << #z << ": " << z << "\n"
#define debv(x, n)                 \
	cout << #x << ": ";            \
	for (int zz = 0; zz < n; zz++) \
		cout << x[zz] << " ";      \
	cout << "\n"
#define debs(x)            \
	cout << #x << ": ";    \
	for (auto zz : x)      \
		cout << zz << " "; \
	cout << "\n"

void margesort(vector<int>&a,vector<int>&b,int n,int m){
    int i,j,k,l;
    vector<int> c(n+m);
    i=j=k=0;
    while(i<n&&j<m){
        if(a[i]>b[j]) c[k++]=b[j++];
        else c[k++]=a[i++];
    }
    while(i<n){
        c[k++]=a[i++];
    }
    while(j<m){
        c[k++]=b[j++];
    }
    i=j=0;
    while(i<n){
       a[i++] = c[j++];
    }
    i=0;
    while(i<m){
        b[i++] = c[j++];
    }
}

void gapMathod(vector<int>&a,vector<int>&b,int n,int m){
     
    int gap = n+m;
    gap = gap/2 + gap%2;
    int i,j;
    while(gap>1){
        for(i=0;i+gap<n;i++)
            if(a[i]>a[gap+i]) swap(a[i],a[gap+i]);

        for(j=0;i<n;i++)
            if(a[i]>b[(gap+i)%n]) swap(a[i],b[(gap+i)%n]);

        for(i=0;i+gap<m;i++)
          if(b[i]>b[gap+i]) swap(b[i],b[gap+i]);

        gap = gap/2 + gap%2;
    }

     for(int i=0;i+gap<n;i++)
            if(a[i]>a[gap+i]) swap(a[i],a[gap+i]);

    for(int j=0;i<n;i++)
            if(a[i]>b[(gap+i)%n]) swap(a[i],b[(gap+i)%n]);

    for(int i=0;i+gap<m;i++)
          if(b[i]>b[gap+i]) swap(b[i],b[gap+i]);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
        gapMathod(a,b,n,m);
    // margesort(a,b,n,m);
    debv(a,n);
    debv(b,m);
}