//Ref:https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/
/*
Problem Description
Given two integers arrays, A and B, of size N each.Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in arrays A and B.

Problem Constraints
1 <= N <= 2 * 105
-1000 <= A[i], B[i] <= 1000

Input Format
The first argument is an integer array A.
The second argument is an integer array B.

Output Format
Return an integer array denoting the N maximum element in descending order.

Example Input
Input 1:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]

Input 2:
 A = [2, 4, 1, 1]
 B = [-2, -3, 2, 4]

Example Output
Output 1:[10, 9, 9, 8]
Output 2:[8, 6, 6, 5]

Example Explanation
Explanation 1: 4 maximum elements are 10(6+4), 9(6+3), 9(5+4), 8(6+2).
Explanation 2: 4 maximum elements are 8(4+4), 6(4+2), 6(4+2), 5(4+1).
*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    //sort both the arrays
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int n=A.size();
    int m=B.size();

    //create a priority queue to get max
    priority_queue<pair<int,pair<int,int>>> pq;

    //create a vector to return res
    vector<int> res;

    //create a set to advoid duplicate values to insert
    set<pair<int,int>> st;
    
    //create two pointer ptr1 and ptr2 to iterate over A and B array
    int ptr1=n-1,ptr2=m-1;

    //insert max sum into queue and the result
    pq.push({A[ptr1]+B[ptr2],{ptr1,ptr2}});

    //insert into set to avoid duplicate index
    st.insert({ptr1,ptr2});

    //find n max sum elements
    for(int i=0;i<A.size();i++){
        //create a temp pair to get the top of the que value
        pair<int,pair<int,int>> temp = pq.top();
        //remove max element
        pq.pop();
        
        //first max sum into the res
        res.push_back(temp.first);

        //update the pointers
        ptr1=temp.second.first;
        ptr2=temp.second.second;

        //calculate sum
        int sum = A[ptr1-1] + B[ptr2];
        
        // insert (A[i - 1] + B[j], (i - 1, j))
        // create a new pair
        pair<int,int> next_pair = make_pair(ptr1-1,ptr2);

        // insert only if the pair (i - 1, j) is
        // not already present inside the map i.e.
        // no repeating pair should be present inside
        // the heap.
        if(st.find(next_pair)==st.end()){
            pq.push({sum,next_pair});
            st.insert(next_pair);
        }

        sum = A[ptr1] + B[ptr2-1];

        // insert (A[i] + B[j-1], (i, j-1))
        // create a new pair
        next_pair = make_pair(ptr1,ptr2-1);

        // insert only if the pair (i, j - 1)
        // is not present inside the heap.
        if(st.find(next_pair)==st.end()){
            pq.push({sum,next_pair});
            st.insert(next_pair);
        }
    }

    return res;
    
}

/*
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/
