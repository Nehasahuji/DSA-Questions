/*
  Time Complexity:O(lon(n)) downHeapify a single node takes O(log N)
                  time.
  Space Complexity:O(n) // stack space
*/
#include <bits/stdc++.h>
using namespace std;

void downHeapify(vector<int> &arr,int index,int n){
    //find parent using zero based indexing
    int parent = (index-1)/2; 
    
    if(arr[parent]>0){
        if(arr[index]<arr[parent]){
            swap(arr[index],arr[parent]);
            
            upHeapify(arr,parent,n);
        }
    }
}

void heapify(vector<int> &arr,int index,int n){
    //initialize as root
    int smallest = index;
    
    //find left and right child using zero based indexing
    int leftIndex = (2 * index)+1, 
        rightIndex = (2 * index)+2;
        
    //if left child is greater than root;
    if(leftIndex<n && arr[leftIndex]<arr[smallest]){
        smallest=leftIndex;
    }
    
    //if right child is greater than  root
    if(rightIndex<n && arr[rightIndex]<arr[smallest]){
        smallest=rightIndex;
    }
    
    //if largest is not equal to i not at its right position
    if(smallest!=index){
        swap(arr[smallest],arr[index]);
         //recursively call for then affected sub tree
         heapify(arr,smallest,n);
    }
}

void createHeap(vector<int> &arr){
    //size of heap
    int n=arr.size();
    
    //find index of last non heapify node
    int startIndex = n/2-1;
    for(int i=startIndex;i>=0;i--){
        heapify(arr,i,n);
    }

}

void insertNode(vector<int> &arr,int value){
    //step 1: insert node at the last index
    arr.push_back(value);
    
    //step 2: rearrange the heap deheapify 
    upHeapify(arr,arr.size()-1,arr.size());
}

void printHeap(vector<int> &arr,int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    // Write C++ code here
   vector<int> arr = {4, 10, 3, 5, 1};
   
   //print array
   cout << "print array before creating heap " << endl;
   printHeap(arr,arr.size());
   createHeap(arr);
   cout << "print array after creating heap " << endl;
   printHeap(arr,arr.size());
   
   insertNode(arr,0);
   printHeap(arr,arr.size());
    return 0;
}
