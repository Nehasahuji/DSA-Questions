//https://leetcode.com/problems/subsets/description/
void getAllSubsets(vector<int> &A,vector<int> list,vector<vector<int> > &ans,int index){
    //when index is size of array
    if(index==A.size()){
        //push array of no to ans and return 
        ans.push_back(list);
        return;
    }

    //call whene element at current index in not present
    getAllSubsets(A,list,ans,index+1);
    //add element to list 
    list.push_back(A[index]);
    ////call whene element at current index in  present
    getAllSubsets(A,list,ans,index+1);
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    //sort array to get required output
    sort(A.begin(),A.end());
    //create  a list array for temprarory record
    vector<int> list;
    //create ans varible to keep track of ans 
    vector<vector<int>> ans;
    //call function to get all subsets
    getAllSubsets(A,list,ans,0);
    //sort array to get lexiographically sorted output
    sort(ans.begin(),ans.end());
    return ans;

}
/*Time complexity: O(2^n) => we have two choices for all elements
Space complexity: O(n) => stack space
*/
