/*
B Closest Points to Origin

Problem Description
We have a list A of points (x, y) on the plane. Find the B closest points to the origin (0, 0).

Here, the distance between two points on a plane is the Euclidean distance.

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.)

NOTE: Euclidean distance between two points P1(x1, y1) and P2(x2, y2) is sqrt( (x1-x2)2 + (y1-y2)2 ).

Problem Constraints
1 <= B <= length of the list A <= 105
-105 <= A[i][0] <= 105
-105 <= A[i][1] <= 105

Input Format
The argument given is list A and an integer B.

Output Format
Return the B closest points to the origin (0, 0) in any order.

Example Input
Input 1:
A = [ 
       [1, 3],
       [-2, 2] 
     ]
 B = 1
Input 2:
 A = [
       [1, -1],
       [2, -1]
     ] 
 B = 1

Example Output
Output 1:[ [-2, 2] ]
Output 2:[ [1, -1] ]
*/
/*
- Time complexity: O(N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(N)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
*/

struct compare
{
    bool operator()(
    struct vector<int> &A, struct vector<int> &B)
    {
        return (A[0]*A[0] + A[1]*A[1]) > (B[0]*B[0] + B[1]*B[1]) ;
    }
};
vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    // Syntax of priority 
    // priority_queue<type, vector<type>, greater<type>> pq; ;
    priority_queue<vector<int>,vector<vector<int>>,compare> pq;

    //add elements to the queue
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    vector<vector<int>> res;
    for(int i=0;i<B;i++){
            if(!pq.empty()){
                res.push_back(pq.top());
                pq.pop();
            }
    }
    return res;
}