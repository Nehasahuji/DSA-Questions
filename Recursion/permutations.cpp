//https://leetcode.com/problems/permutations/description/
/*Approach: Recursive solution Using frequency array
Complexity
Time complexity:O(N!)
Space complexity:O(N)
*/
class Solution {
public:

    void recurPermutes(vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds,vector<bool>& freq)  
    {
        int n=nums.size();
        //if the size of data structure is equal to input array if means we get a permutation
        if(ds.size()==n){
            //insert that value into the ans and return
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<n;i++){
            //if that element is not included
            if(!freq[i]){
                //update the frequence array
                freq[i]=true;
                //insert that element into ans 
                ds.push_back(nums[i]);
                //recursively call for upcomming index
                recurPermutes(nums,ans,ds,freq);
                //remove that element for next permutations
                ds.pop_back(); //pop back is used to remove last element 
                //mark frequency for that array also false
                freq[i]=false; 
            }
        }


    }


    vector<vector<int>> permute(vector<int>& nums) {
        //Create a 2d vector to store ans
        vector<vector<int>> ans;
        //create a array to store elements
        vector<int> ds;

        //create a boolean array for frequency
        vector<bool> freq(nums.size(),false);

        //cal recursive funtion to get permutaions
        recurPermutes(nums,ans,ds,freq);
        return ans;
    }
};

/*
Approach: Recursive solution without freqency array
Complexity
Time complexity:O(N! * N )
Space complexity:O(N) //stack space
*/

class Solution {
public:

    void recurPermutes(vector<int>& nums,vector<vector<int>>& ans,int index)  
    {
        int n=nums.size();
        //if the size of data structure is equal to input array if means we get a permutation
        if(index==n-1){
            //insert that value into the ans and return
            vector<int> ds;
            for(int i=0;i<nums.size();i++){
                ds.push_back(nums[i]);
            }
            ans.push_back(ds);
            return;
        }

        for(int i=index;i<n;i++){
            swap(nums[i],nums[index]);
            recurPermutes(nums,ans,index+1);
            //re swap to get back to orignal value
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        //Create a 2d vector to store ans
        vector<vector<int>> ans;
        
        //cal recursive funtion to get permutaions
        recurPermutes(nums,ans,0);
        return ans;
    }
};