/*Problem Description
Given an integer array A of size N.
You have to find the product of the three largest integers in array A from range 1 to i, where i goes from 1 to N.Return an array B where B[i] is the product of the largest 3 integers in range 1 to i in array A. If i < 3, then the integer at index i in B should be -1.

Problem Constraints
1 <= N <= 105
0 <= A[i] <= 103

Input Format
First and only argument is an integer array A.

Output Format
Return an integer array B. B[i] denotes the product of the largest 3 integers in range 1 to i in array A.

Example Input
Input 1: A = [1, 2, 3, 4, 5]
Input 2: A = [10, 2, 13, 4]

Example Output
Output 1:[-1, -1, 6, 24, 60]
Output 2:[-1, -1, 260, 520]
*/

vector<int> Solution::solve(vector<int> &a) {
    priority_queue< int > heap;
    vector< int > ans;
    for( int i=0;i<a.size();i++){
        heap.push(a[i]);
        if(i<2) ans.push_back(-1);
        else{
            int a=heap.top();   heap.pop();
            int b=heap.top();   heap.pop();
            int c=heap.top();   heap.pop();
            ans.push_back(a*b*c);
            heap.push(a);   heap.push(b);   heap.push(c);
        }
    }return ans;
}

/* Time Complexity: O(Nlog(N))
Space Complexity: O(N)
*/
    
