#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N];
int t[4*N];
int t1[4*N];
int t2[4*N];
int t3[4*N];
int t4[4*N];
int even[4*N];
int prime[N];
int sz;
void sieve()
{
    for(int i=0;i<=N;i++)prime[i]=1;
    prime[0]=prime[1]=0;
    for(int i=4;i<=N;i=i+2)prime[i]=0;
    for(int i=3;i*i<=N;i=i+2)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<=N;j=j+2*i)prime[j]=0;
        }
    }
}
int buildTree(int ss,int se,int ti)//SUM er jonno build tree
{
    if(ss==se){t[ti]=a[ss];return t[ti];}
    int mid=(ss+se)/2;
    return t[ti]=buildTree(ss,mid,2*ti+1)+buildTree(mid+1,se,2*ti+2);
}
int buildMaxTree(int ss,int se,int ti)//MAX er jonno build tree
{
    if(ss==se){
        t1[ti]=a[ss];
        return t1[ti];
        }
    int mid=(ss+se)/2;
    buildMaxTree(ss,mid,2*ti+1);
    buildMaxTree(mid+1,se,2*ti+2);
    return t1[ti]=max(t1[2*ti+1],t1[2*ti+2]);
}
int buildMinTree(int ss,int se,int ti)//MIN er jonno build tree
{
    if(ss==se){t2[ti]=a[ss];return t2[ti];}
    int mid=(ss+se)/2;
    buildMinTree(ss,mid,2*ti+1);
    buildMinTree(mid+1,se,2*ti+2);
    return t2[ti]=min(t2[2*ti+1],t2[2*ti+2]);
}
void buildEvenTree(int ss,int se,int ti)//EVEN er jonno build tree
{
    if(ss==se){
        if(a[ss]%2==0){
          even[sz++]=a[ss];
          t3[ti]=1;
        }
        else{
            t3[ti]=0;
        }
        return;
    }
    int mid=(ss+se)/2;
    buildEvenTree(ss,mid,2*ti+1);
    buildEvenTree(mid+1,se,2*ti+2);
    t3[ti]=t3[2*ti+1]+t3[2*ti+2];
}
void buildPrimeTree(int ss,int se,int ti)//PRIME er jonno build tree
{
    if(ss==se){
        if(prime[a[ss]]==1){
          t4[ti]=1;
        }
        else{
            t4[ti]=0;
        }
        return;
    }
    int mid=(ss+se)/2;
    buildPrimeTree(ss,mid,2*ti+1);
    buildPrimeTree(mid+1,se,2*ti+2);
    t4[ti]=t4[2*ti+1]+t4[2*ti+2];
}
int getPrimeSum(int ss,int se,int qs,int qe,int ti)
{
    if(qs<=ss && qe>=se)return t4[ti];
    if(qe<ss || se<qs)return 0;
    int mid = (ss+se)/2;
    return getPrimeSum(ss,mid,qs,qe,2*ti+1)+getPrimeSum(mid+1,se,qs,qe,2*ti+2);
}
int getEvenSum(int ss,int se,int qs,int qe,int ti)
{
    if(qs<=ss && qe>=se)return t3[ti];
    if(qe<ss || se<qs)return 0;
    int mid = (ss+se)/2;
    return getEvenSum(ss,mid,qs,qe,2*ti+1)+getEvenSum(mid+1,se,qs,qe,2*ti+2);
}
int getSum(int ss,int se,int qs,int qe,int ti)
{
    if(qs<=ss && qe>=se)return t[ti];
    if(qe<ss || se<qs)return 0;
    int mid = (ss+se)/2;
    return getSum(ss,mid,qs,qe,2*ti+1)+getSum(mid+1,se,qs,qe,2*ti+2);
}
int getMax(int ss,int se,int qs,int qe,int ti)
{
    if(qs<=ss && qe>=se)return t1[ti];
    if(qe<ss || se<qs)return INT_MIN;
    int mid = (ss+se)/2;
    int left_max=getMax(ss,mid,qs,qe,2*ti+1);
    int right_max=getMax(mid+1,se,qs,qe,2*ti+2);
    return max(left_max,right_max);
}
int getMin(int ss,int se,int qs,int qe,int ti)
{
    if(qs<=ss && qe>=se)return t2[ti];
    if(qe<ss || se<qs)return INT_MAX;
    int mid = (ss+se)/2;
    int left_min=getMin(ss,mid,qs,qe,2*ti+1);
    int right_min=getMin(mid+1,se,qs,qe,2*ti+2);
    return min(left_min,right_min);
}
void update(int ss,int se,int ti,int index)
{
    if(ss==se){
        t[ti]=a[index];
        return;
    }
    int mid=(ss+se)/2;
    if(index<=mid)update(ss,mid,2*ti+1,index);
    else update(mid+1,se,2*ti+2,index);
    t[ti]=t[2*ti+1]+t[2*ti+2];
}
int main()
{
    cout<<"Enter the number of array elements: "<<endl;
    int n;cin>>n;
    cout<<"Enter the array elements: "<<endl;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<"Enter query indices: "<<endl;
    int qs,qe;
    cin>>qs>>qe;
    sieve();
    buildTree(0,n-1,0);
    buildMaxTree(0,n-1,0);
    buildMinTree(0,n-1,0);
    buildEvenTree(0,n-1,0);
    buildPrimeTree(0,n-1,0);
    cout<<"Sum: "<<getSum(0,n-1,qs,qe,0)<<endl;
    cout<<"Max value between the range ("<<qs<<" - "<<qe<<"): "<<getMax(0,n-1,qs,qe,0)<<endl;
    cout<<"Min value between the range ("<<qs<<" - "<<qe<<"): "<<getMin(0,n-1,qs,qe,0)<<endl;
    cout<<"Prime numbers between the range ("<<qs<<" - "<<qe<<"): "<<getPrimeSum(0,n-1,qs,qe,0)<<endl;
    cout<<"Even: "<<getEvenSum(0,n-1,qs,qe,0)<<endl;
    cout<<"Even numbers: "<<endl;
    //sort(even,even+sz);
    for(int i=0;i<sz;i++)
    {
        //if(even[i]>=a[qs] && even[i]<=a[qe])
        cout<<even[i]<<" ";
    }

    cout<<endl;
    cout<<"Enter the index to update: "<<endl;
    int index;cin>>index;
    cout<<"Enter the updated value: "<<endl;
    int v;cin>>v;
    a[index]=v;
    update(0,n-1,0,index);
    cout<<"The updated sum: "<<getSum(0,n-1,qs,qe,0)<<endl;

}
