#include<iostream>
#include<vector>

using namespace std;

vector<int> tree;
void build(int node,int l,int r,vector<int>&arr)
{
    if(l==r)
    { 
     tree[node]=arr[l];
     return;
    }
    int mid=(l+r)/2;
    
    build(2*node+1,l,mid,arr);
    build(2*node+2,mid+1,r,arr);
    
    tree[node]=tree[2*node+1]+tree[2*node+2];
}
int query(int node,int l,int r,int ql,int qr)
{
    if(l>qr || r<ql) return 0;
    if(l>= ql && r<=qr) return tree[node];
    int mid=(l+r)/2;
    int leftsum=query(2*node+1,l,mid,ql,qr);
    int rightsum=query(2*node+2,mid+1,r,ql,qr);
return leftsum+rightsum;
}
void update(int node,int l,int r,int index,int value )
{
     if(l==r)
     {
          tree[node]=value;
          return;
     }
     int mid=(l+r)/2;
     if(index<=mid)
     {
         update(2*node+1,l,mid,index,value);
     }
     else
     {
         update(2*node+2,mid+1,r,index,value);
     }
     tree[node]=tree[2*node+1]+tree[2*node+2];
     
}

int main()
{
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    tree.resize(4*n);
    
    build(0,0,n-1,arr);
  cout<<   query(0,0,n-1,0,1) << endl;
    update(0,0,n-1,0,10);
    cout<< query(0,0,n-1,0,1) << endl;
    return 0;
}