/*
Given two arrays, A and B of size N. A[i] represents the time by which you can buy the ith car without paying any money.

B[i] represents the profit you can earn by buying the ith car. It takes 1 minute to buy a car, so you can only buy the ith car when the current time <= A[i] - 1.

Your task is to find the maximum profit one can earn by buying cars considering that you can only buy one car at a time.

NOTE:

You can start buying from time = 0.
Return your answer modulo 109 + 7.


Problem Constraints
1 <= N <= 105
1 <= A[i] <= 109
0 <= B[i] <= 109



Input Format
The first argument is an integer array A represents the deadline for buying the cars.
The second argument is an integer array B represents the profit obtained after buying the cars.



Output Format
Return an integer denoting the maximum profit you can earn.



Example Input
Input 1:

 A = [1, 3, 2, 3, 3]
 B = [5, 6, 1, 3, 9]
Input 2:

 A = [3, 8, 7, 5]
 B = [3, 1, 7, 19]


Example Output
Output 1:

 20
Output 2:

 30

*/

bool comp(pair<int,int> A,pair<int,int> B){
    return A.first < B.first;
}


int Solution::solve(vector<int> &A, vector<int> &B) {

    //Step 1: create a pair of vector to simply sort the array B with reference to Array A'
    vector<pair<int,int>> m_pair;

    for(int i=0;i<A.size();i++){
        m_pair.push_back({A[i],B[i]});
    }  

    //Step 2: Sort the pair array in increasing order of time
    sort(m_pair.begin(),m_pair.end(),comp);

    //Step 3: create a min heap
    priority_queue<int,vector<int>,greater<int>> pq;

    //intilaize time as 0
    int t=0;


    for(int i=0;i<m_pair.size();i++){
        //check if the car can be bought at this time - if yes buy it
        if(t<m_pair[i].first){
            pq.push(m_pair[i].second);
            t++;
        }
        // if the profit is more then don't buy the car you bought initially and instead buy this one
        else{
            if(m_pair[i].second > pq.top()){
                pq.pop();
                pq.push(m_pair[i].second);
            }
        }
        
    }

    long int sum = 0;
    long int mod = pow(10,9)+ 7;

    // get sum of elements by taking out the elements from min heap
    while(!pq.empty()){
    sum += pq.top();
    sum %= mod;
    pq.pop();
    }

    return sum%mod;
}

/* Time complexity: O(nlogn)
Space Complexity: O(n)
*/