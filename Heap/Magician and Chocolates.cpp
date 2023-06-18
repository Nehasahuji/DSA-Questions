/*
Problem Description
Given N bags, each bag contains Bi chocolates. There is a kid and a magician.
In a unit of time, the kid can choose any bag i, and eat Bi chocolates from it, then the magician will fill the ith bag with floor(Bi/2) chocolates.

Find the maximum number of chocolates that the kid can eat in A units of time.

NOTE:

floor() function returns the largest integer less than or equal to a given number.
Return your answer modulo 109+7


Problem Constraints
1 <= N <= 100000
0 <= B[i] <= INT_MAX
0 <= A <= 105
*/

/*
- Time complexity: O(N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(N)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
*/

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> pq;
    long long sum=0;
    int mod = pow(10,9)+7;
    for(int i=0;i<B.size();i++){
        pq.push(B[i]);
    }

    while(A>0 && !pq.empty()){
        int temp = pq.top();
        sum=sum+(long long)temp;
        pq.pop();
        pq.push(temp/2);
        A--;
    }

    return sum%mod;
}
