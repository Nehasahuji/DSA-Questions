//https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool sortByEndTime(pair<int,int> pair1,pair<int,int> pair2){
        if(pair1.second==pair2.second){
            return pair1.first < pair2.first;
        }
        
        return pair1.second<pair2.second;
    }
    
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        //create a pair and insert int into a vector
        vector<pair<int,int>> work_time;
        
        for(int i=0;i<n;i++){
            work_time.push_back({start[i],end[i]});
        }
        
        sort(work_time.begin(),work_time.end(),sortByEndTime);
       // sort(work_time.begin(),work_time.end(),sortByEndTime);
        
        
        int total_time=1;
        int end_time = work_time[0].second;
        
        for(int i=1;i<n;i++){
            if(work_time[i].first>end_time){
                total_time++;
                end_time=work_time[i].second;
            }
        }
        
        return total_time;
    }
}

/*
Time Complexity:O(nlongn) + O(n) - >O(nlogn)
Space Complexity :O(n) 
*/

