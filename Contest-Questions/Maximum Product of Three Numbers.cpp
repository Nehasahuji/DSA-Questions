1. Using sorting
Time Complexity:O(nlogn)
SpaceComplexity:O(n)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return max((nums[0]*nums[1]*nums[n-1]),(nums[n-1]*nums[n-2]*nums[n-3]));
    }
};


2.Using heaps
Time Complexity: O(n)
Space Complexity:O(n)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       priority_queue<int> maxHeap;
       priority_queue<int,vector<int>,greater<int>> minHeap;

       for(int i=0;i<nums.size();i++){
           maxHeap.push(nums[i]);
           minHeap.push(nums[i]);
       }

       int max1=maxHeap.top();
       maxHeap.pop();

       int max2=maxHeap.top();
       maxHeap.pop();

       int max3 = maxHeap.top();
       maxHeap.pop();

       int min1 = minHeap.top();
       minHeap.pop();

       int min2 = minHeap.top();
       minHeap.pop();

       return max(max1*max2*max3,max1*min1*min2);
    }
};

Approch 3:
Time Complexity:O(n)
Space Complexity:O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1, min2, max1, max2, max3;
        min1 = min2 = INT_MAX;
        max1 = max2 = max3 = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(max1 < nums[i]){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }else if(max2 < nums[i]){
                max3 = max2;
                max2 = nums[i];
            }else if(max3 < nums[i]){
                max3 = nums[i];
            }
            

            if(min1 > nums[i]){
                min2 = min1;
                min1 = nums[i];
            }else if(min2 > nums[i]){
                min2 = nums[i];
            }
            
        }
        
        return max(max1 * max2 * max3 , min1 * min2 * max1);
    }
};