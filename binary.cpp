#include<bits/stdc++.h>
using namespace std;


int binarySearchiter (int arr[], int n,int k){
 sort(arr,arr+n);
  int start=0;
  int end = n-1;

  while(start<=end)
  {
    int mid = start+((end - start)/2);

    if(arr[mid] == k)return mid;

    else if(arr[mid] > k)
    {
        end=mid-1;
    }

    else{
        start=mid+1;
    }
  }
  return -1;
}

int binarySearchrec (int arr[], int k,int start,int end)
{
    int mid = start+((end - start)/2);
   if(arr[mid] == k)return mid;
    else if(arr[mid] > k)
    {
        binarySearchrec (arr,k,start,mid-1);
    }

    else{
        binarySearchrec (arr,k,mid+1,end);
    }

}

int main()
{
    int n=0;
    cout<<"enter the size of your array"<<endl;
    cin >> n;
    int arr[n];
   cout<<"enter the elements";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
     int k=0;
     cout<<"enter the element you want to find"<<endl;
     cin>>k;
    int ans=binarySearchiter(arr,n,k);
    sort(arr,arr+n);
    int start =0;
    int end = n-1;
    int ans2=binarySearchrec(arr,k,start,end);
    if(ans!=-1){
    cout<<"the element is fount in the index:"<<"for iterative:"<<ans<<"for recursive:"<<ans2;}
    else{
        cout<<"element is not found";
    }
}