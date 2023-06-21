/*Time Complexity:O(lon(n)) Heapify a single node takes O(log N) time
  Space Complexity:O(n) // stack spac
*/
#include <bits/stdc++.h>
using namespace std;


void downHeapify(vector<int> &arr,int index,int n){
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
         downHeapify(arr,smallest,n);
    }
}

void deleteRoot(vector<int> &arr){
    // step1: calculate size of array
    int n=arr.size();
    
    //Step 2: root of array with the last element as deletion became easy
    swap(arr[0],arr[n-1]);
    
    //Step 3: downHeapify the remaining heap
    downHeapify(arr,0,n-1);
    
}

void printHeap(vector<int> &arr,int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    // Write C++ code here
   vector<int> arr = {1, 4 ,3, 5, 10 };
   
   cout << "print array befor deleting root " << endl;
   printHeap(arr,arr.size());
   deleteRoot(arr);
   cout << "print array after deleating root of heap " << endl;
   printHeap(arr,arr.size()-1);

    return 0;
}
