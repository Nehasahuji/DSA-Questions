/*Time Complexity:O(nlon(n)) Heapify a single node takes O(log N) time
            	complexity where N is the total number of Nodes. Therefore, building the entire Heap will take N heapify operations and the total time complexity will be O(N*logN).

Space Complexity:O(n) // stack space
*/
#include <bits/stdc++.h>
using namespace std;


void heapify(vector<int> &arr,int index){
    //calculate size of array
    int n=arr.size();
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
         heapify(arr,smallest);
    }
}

void createHeap(vector<int> &arr){
    //size of heap
    int n=arr.size();
    
    //find index of last non heapify node
    int startIndex = n/2-1;
    for(int i=startIndex;i>=0;i--){
        heapify(arr,i);
    }

}

void printHeap(vector<int> &arr)
{
    cout << "Array representation of Heap is:\n";
 
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    // Write C++ code here
   vector<int> arr = {4, 10, 3, 5, 1};
   
   //print array
   cout << "print array before creating heap " << endl;
   printHeap(arr);
   createHeap(arr);
   cout << "print array after creating heap " << endl;
   printHeap(arr);
   

    return 0;
}