#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r){
   int n1=mid-l+1; //You have to consider size here not the index.
   int n2=r-mid;

   int a[n1];
   int b[n2];

   for(int i=0;i<n1;i++){
      a[i]=arr[l+i];
   }
   for(int i=0;i<n2;i++){
      b[i]=arr[mid+1+i];
   }

   int i=0;
   int j=0;
   int k=l;

   while(i<n1 && j<n2){
      if(a[i]<b[j]){
         arr[k]=a[i];
         k++;i++;
      }
      else{
         arr[k]=b[j];
         k++;j++;
      }
   }

   while(i<n1){
      arr[k]=a[i];
      k++;i++;
   }
   while(j<n2){
      arr[k]=b[j];
      k++;j++;
   }
}

void mergeSort(int arr[],int l,int r){
   if(l<r){
      int mid=(l+r)/2;
      mergeSort(arr,l,mid);
      mergeSort(arr,mid+1,r);
      merge(arr,l,mid,r);
   }
}

void display(int arr[],int size){
   for(int i=0;i<size;i++){
      cout<<arr[i]<<" ";
   }
}

int main(){
   int arr[]={2,6,8,7,6,3,99,9,863,8,5,4,55,78,85};
   int size=sizeof(arr)/sizeof(arr[0]);
   mergeSort(arr,0,size-1);
   display(arr,size);
   return 0;
}


