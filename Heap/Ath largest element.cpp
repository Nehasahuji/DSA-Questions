*/
Problem Description
Given an integer array B of size N.You need to find the Ath largest element in the subarray [1 to i], where i varies from 1 to N. In other words, find the Ath largest element in the sub-arrays [1 : 1], [1 : 2], [1 : 3], ...., [1 : N].

NOTE: If any subarray [1 : i] has less than A elements, then the output should be -1 at the ith index.

Problem Constraints
1 <= N <= 100000
1 <= A <= N
1 <= B[i] <= INT_MAX

Input Format
The first argument is an integer A.
The second argument is an integer array B of size N.

Output Format
Return an integer array C, where C[i] (1 <= i <= N) will have the Ath largest element in the subarray [1 : i].

Example Input
Input 1:
 A = 4  
 B = [1 2 3 4 5 6] 

Input 2:
 A = 2
 B = [15, 20, 99, 1]
 
Example Output
Output 1: [-1, -1, -1, 1, 2, 3]
Output 2: [-1, 15, 20, 20]
*/
vector<int> Solution::solve(int A, vector<int> &B) {
    //Step 1: create a min heap
    priority_queue<int,vector<int>,greater<int>> pq;
    
    //Step 2: Create a vector for res
    vector<int> res;
    
	//Step 3: Insert A-1 elements as -1
    for(int i=0;i<A-1;i++){
        pq.push(B[i]);
        res.push_back(-1);
    }
     
	//Step 4: Insert first max element
    pq.push(B[A-1]);
    res.push_back(pq.top());
     
	//get the max for the remaining elements
    for(int i=A;i<B.size();i++){
        if(B[i]>pq.top()){
            pq.pop();
            pq.push(B[i]);
        }

        res.push_back(pq.top());
    }

    return res;

}

/*
   Time Complexity: O(nlogk)
   Space Complexity: O(k)
*/
