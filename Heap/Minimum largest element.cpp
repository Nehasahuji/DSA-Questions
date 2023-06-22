/*Problem Description
Given an array A of N numbers, you have to perform B operations. In each operation, you have to pick any one of the N elements and add the original value(value stored at the index before we did any operations) to its current value. You can choose any of the N elements in each operation.Perform B operations in such a way that the largest element of the modified array(after B operations) is minimized.Find the minimum possible largest element after B operations.

Problem Constraints
1 <= N <= 106
0 <= B <= 105
-105 <= A[i] <= 105

Input Format
The first argument is an integer array A.The second argument is an integer B.

Output Format
Return an integer denoting the minimum possible largest element after B operations.

Example Input
Input 1: A = [1, 2, 3, 4] B = 3
Input 2: A = [5, 1, 4, 2]  B = 5

Example Output
Output 1:4
Output 2: 5
*/

int Solution::solve(vector<int> &A, int B) {
    //create a vector for new state as we want to maintain both current state and next state
    vector<int> new_state = A;

    //create a min heap priority queue 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    //insert element in the queue with next state
    for(int i=0;i<A.size();i++){
        pq.push(make_pair(2*A[i],i));
    }

    //check for B operation 
    while(B--){
        //find the minimum element
        pair<int,int> t = pq.top();
        //update the state in new state vector
        new_state[t.second] = t.first;
        //remove the current min 
        pq.pop();
        //add elements with new state 
        pq.push(make_pair(A[t.second] + t.first,t.second));
    }

    //find the maximum after performing B operations
    int max_minimum = new_state[0];
    for(int i=0;i<new_state.size();i++){
        max_minimum = max(max_minimum,new_state[i]);
    }


    return max_minimum;

}

/*
Time Complexity: O(n)  + O(Blog(n)) + O(n) -> O(n)
Space Complexity: O(n) we are storing all the elements in  heap
*/