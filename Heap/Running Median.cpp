/*
Problem Description
Given an array of integers, A denoting a stream of integers. New arrays of integer B and C are formed.Each time an integer is encountered in a stream, append it at the end of B and append the median of array B at the C.Find and return the array C.

NOTE:If the number of elements is N in B and N is odd, then consider the median as B[N/2] ( B must be in sorted order).
If the number of elements is N in B and N is even, then consider the median as B[N/2-1]. ( B must be in sorted order).

Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 109

Input Format
The only argument given is the integer array A.

Output Format
Return an integer array C, C[i] denotes the median of the first i elements.

Example Input
Input 1:A = [1, 2, 5, 4, 3]
Input 2:A = [5, 17, 100, 11]

Example Output
Output 1: [1, 1, 2, 2, 3]
Output 2:[5, 5, 17, 11]

*/
vector<int> Solution::solve(vector<int> &A) {
    //Step 1: calculate size of array
    int n=A.size();

    //Step 2: crate a result vector
    vector<int> res;

    //Step 3: create a max heap 
    priority_queue<int> max_pq;

    //Step 4:create a min  heap
    priority_queue<int,vector<int>,greater<int>> min_pq;
    
    //Step 5: insert first element into max heap
    max_pq.push(A[0]);
    //push it to the result
    res.push_back(A[0]);

    //Step 6: get remaining elements
    for(int i=1;i<n;i++){
        //Step 7: if current element is smaller then the max element in max heap then insert it into max heap
        if(A[i] < max_pq.top()){
            max_pq.push(A[i]);
        }else{
            //Step 8: if current element is greater then the min element in min heap then insert it into min heap
            min_pq.push(A[i]);
        }

        //Step 9: calculate size of max heap and min heap
        int max_heap_size = max_pq.size();
        int min_heap_size = min_pq.size();

        //Step 10: if size of max heap is greater then min heap then transfer max element from max heap to min heap
        if(max_heap_size-min_heap_size>1){
            min_pq.push(max_pq.top());
            max_pq.pop();
        }

        //Step 11: if size of min heap is greater then max heap then transfer mun element from min heap to max heap
        if(max_heap_size-min_heap_size<0){
            max_pq.push(min_pq.top());
            min_pq.pop();
        }


        //step 12: median is always a max element of max heap
        res.push_back(max_pq.top());
    
    }

    return res;
}
// Time Complexity: O(nlongn)
// Space Complexity: O(n)