/*
Problem Description
Misha loves eating candies. She has been given N boxes of Candies.

She decides that every time she will choose a box having the minimum number of candies, eat half of the candies and put the remaining candies in the other box that has the minimum number of candies.
Misha does not like a box if it has the number of candies greater than B so she won't eat from that box. Can you find how many candies she will eat?

NOTE 1: If a box has an odd number of candies then Misha will eat the floor(odd / 2).
NOTE 2: The same box will not be chosen again.

Problem Constraints
1 <= N <= 10^5
1 <= A[i] <= 10^5
1 <= B <= 10^6

Input Format
The first argument is A an Array of Integers, where A[i] is the number of candies in the ith box.
The second argument is B, the maximum number of candies Misha like in a box.

Output Format
Return an integer denoting the number of candies Misha will eat.

Example Input
Input 1:
 A = [3, 2, 3]
 B = 4

Input 2:
 A = [1, 2, 1]
 B = 2

Example Output
Output 1: 2
Output 2: 1
*/
int Solution::solve(vector<int> &A, int B) {
    //Step1 : create a priority queue replication min heap
    priority_queue<int,vector<int>,greater<int>> pq;

    //Step2: calculate size of the array
    int n=A.size();

    //Step3: add all the candies into the queue
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    
    //Step 4: create a variable to get total no of candies
    int total_candies = 0;

    //Step 5: iterate till time he will not eat all the candies 
    while(!pq.empty()){
        //take out smallest no
        int current_candies = pq.top();
        pq.pop();

        //if no of candies is smaller than the candies she wants to eat
        if(current_candies<=B){
            //candies she can eat
            int candies_eat = floor(current_candies/2);
            total_candies=total_candies+candies_eat;
            //update the remaining candies if we have candies with us
            if(!pq.empty()){
                int new_candy_box = pq.top();
                //updated the samllest no of candies
                pq.push(new_candy_box+current_candies-candies_eat); 
                pq.pop();
            }
        }else{
            //minimum no of candies in box greater than the candies she wants to eat
            return total_candies;
        }

    }
    
    //return total candies
    return total_candies;
}

/*
- Time complexity: O(N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(N)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
*/