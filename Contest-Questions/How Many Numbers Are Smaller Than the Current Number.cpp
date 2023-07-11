# Approach 1 : Using Array
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:O(n*n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    
     vector<int> result;
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
   
        for(int itr =0 ; itr<nums.size(); itr++){
            int count=0;
            for(int ptr=0 ; ptr < nums.size() ; ptr++){
                if(nums[itr]>nums[ptr]){
                    count++;
                }        
            }
            result.push_back(count);
        }
        return result;
    }
};
``
// ==================================================================
# Approach 2: Using hasmap and sorting
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:O(nlog(n)) + O(n) => O(nlong(n))
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //create a  map to  map value with it,'s piosition in sorted array
        map<int,int>mp;
        int n = nums.size();
        vector<int>snum = nums;
        
        sort(snum.begin(),snum.end());
        //to maintain the value of smallest index
        //map value of no with the sorted index
        for(int i=n-1;i>=0;i--)
        {
            mp[snum[i]]=i;
        }
        
       //get the no of smallest no from current
        for(int i=0;i<n;i++)
            nums[i] = mp[nums[i]];
        
        return nums;
    }
};
```

