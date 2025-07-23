#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void maxHeap(int arr[],int n, int p){
    int left,right,largest;
    left=2*p+1;
    right=left+1;
    largest=p;
    if(left<n && arr[left]>arr[largest]) largest=left;
    if(right<n && arr[right]>arr[largest]) largest=right;
    if(largest!=p){
        swap(arr[largest],arr[p]);
        maxHeap(arr,n,largest);
    }
}
/*
void minHeap(int arr[],int n, int p){
    int left,right,smallest;
    left=2*p+1;
    right=left+1;
    smallest=p;
    if(left<n && arr[left]<arr[smallest]) smallest=left;
    if(right<n && arr[right]<arr[smallest]) smallest=right;
    if(smallest!=p){
        swap(arr[smallest],arr[p]);
        minHeap(arr,n,smallest);
    }
}
*/
int main() {
    int arr[]={10,5,3,15,23,14,26,18,1,4,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    for(int parent=(n/2) -1;parent>=0;parent--){
        maxHeap(arr,n,parent);
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
