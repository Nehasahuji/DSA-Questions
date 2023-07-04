//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
void createletterCombinations(unordered_map<int,string>& telephone_no_mapping,
                                vector<string>& ans,
                                string & curr_string,
                                int index,string& A){
   
    //calculate size of input string
    int n=A.size();
   
    //base case
    if(index==n){
        ans.push_back(curr_string);
        return;
    }
   
    //find value of index
    int no = A[index]-‘0’;

    //get string from the index
    string str = telephone_no_mapping[no];

    for(int i=0;i<str.size();i++){
        curr_string.push_back(str[i]);
        createletterCombinations(telephone_no_mapping,ans,curr_string,index+1,A);
        //backtrack to the previous string
        curr_string.pop_back();
    }
}


vector<string> Solution::letterCombinations(string A) {
   
    //Step 1: Create a map to map numbers with the values in phone
    unordered_map<int,string> telephone_no_mapping;
   
    telephone_no_mapping.insert({0,“0”});
    telephone_no_mapping.insert({1,“1”});
    telephone_no_mapping.insert({2,“abc”});
    telephone_no_mapping.insert({3,“def”});
    telephone_no_mapping.insert({4,“ghi”});
    telephone_no_mapping.insert({5,“jkl”});
    telephone_no_mapping.insert({6,“mno”});
    telephone_no_mapping.insert({7,“pqrs”});
    telephone_no_mapping.insert({8,“tuv”});
    telephone_no_mapping.insert({9,“wxyz”});
   
    //crate a vector of string to store ans
    vector<string> ans;
   
    //current value of string
    string curr_string = “”;

    //recursively call function to create a string

    createletterCombinations(telephone_no_mapping,ans,curr_string,0,A);

    return ans;
}
/*
Time Complexity: (4^n * n) => at max we have 4 possibility for a place
Space Complexity: O(n) => stack space 
*/