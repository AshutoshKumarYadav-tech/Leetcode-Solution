class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

    int low=0;
    int current_sum=0;
    int window_size=INT_MAX;
    for(int high=0;high<nums.size();high++ ){
    
     current_sum += nums[high];
    while(current_sum >= target){
         window_size =min(window_size,high-low+1);
        current_sum-=nums[low];
        low++;
    }
    
    }
     
    return (window_size ==INT_MAX)?0:window_size;
    }
};