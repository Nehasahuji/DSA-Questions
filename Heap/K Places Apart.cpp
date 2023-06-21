/*
Problem Description
N people having different priorities are standing in a queue.The queue follows the property that each person is standing at most B places away from its position in the sorted queue.Your task is to sort the queue in the increasing order of priorities.

NOTE:No two persons can have the same priority.
Use the property of the queue to sort the queue with complexity O(NlogB).

Problem Constraints
1 <= N <= 100000
0 <= B <= N

Input Format
The first argument is an integer array A representing the priorities and initial order of N persons.
The second argument is an integer B.

Output Format
Return an integer array representing the sorted queue.

Example Input
Input 1:
 A = [1, 40, 2, 3]
 B = 2

Input 2:
 A = [2, 1, 17, 10, 21, 95]
 B = 1
 
Example Output
Output 1:[1, 2, 3, 40]
Output 2:[1, 2, 10, 17, 21, 95]

*/
vector<int> Solution::solve(vector<int> &A, int B) {
    //Step 1: create a queue 
    priority_queue<int,vector<int>,greater<int>> pq;

    vector<int> res;

    //Step 2: corner cases
     if(B==0) return A;

    //Step 3: Insert B+1 elements in queue 
    for(int i=0;i<B;i++){
        pq.push(A[i]);
    }

    //Step 4: get top element and insert into vector
    for(int i=B;i<A.size();i++){
        if(!pq.empty()){
          pq.push(A[i]);
          res.push_back(pq.top());
          pq.pop();
        }
    }

    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }

    return res;

}

/* Time Complexity: O(nlogk)
   Space Complexity: O(k)
*/