// https://leetcode.com/problems/maximum-units-on-a-truck/description/
class Solution {
public:
    static bool comparebyNumberOfUnitsPerBox(vector<int> A,vector<int> B){
        if(A[1]==B[1]){
            return A[0]>B[0];
        }

        return A[1]>B[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comparebyNumberOfUnitsPerBox);
        int total_no_of_boxes=0;
       

        for(int i=0;i<boxTypes.size();i++){
            int current_truck_size=boxTypes[i][0],
                current_no_of_units_per_box=boxTypes[i][1];

            if(current_truck_size<truckSize){
               total_no_of_boxes = total_no_of_boxes +  (current_truck_size * current_no_of_units_per_box);
               truckSize=truckSize-current_truck_size;
            }else{
                total_no_of_boxes = total_no_of_boxes + (truckSize*current_no_of_units_per_box);
                return total_no_of_boxes;
            }
        }

      return total_no_of_boxes;
    }
};

/*
Time Complexity:O(nlogn)
Space Complexity: O(O(logn))
*/