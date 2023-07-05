class Solution {
public:
    void getAllSubsets(vector<int> &A,vector<int> list,set<vector<int> > &ans,int index){
        //when index is size of array
        if(index==A.size()){
            //push array of no to ans and return 
            ans.insert(list);
            return;
        }

        //call whene element at current index in not present
        getAllSubsets(A,list,ans,index+1);
        //add element to list 
        list.push_back(A[index]);
        ////call whene element at current index in  present
        getAllSubsets(A,list,ans,index+1);
    }



    vector<vector<int>> subsetsWithDup(vector<int>& A) {
            //sort array to get required output
                sort(A.begin(),A.end());
                //create  a list array for temprarory record
                vector<int> list;
                //create ans varible to keep track of ans 
                set<vector<int>> ans;
                //call function to get all subsets
                getAllSubsets(A,list,ans,0);
            
                vector<vector<int> > res;
                

            for (auto itr : ans)
            {
                res.push_back(itr);
            } 

                //sort array to get lexiographically sorted output
                sort(res.begin(),res.end());

                return res;
        }
};