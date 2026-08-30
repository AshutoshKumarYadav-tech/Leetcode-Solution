class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
    int n=nums.size();
    int min_index=0;
    int max_index=0;
    int mn=INT_MAX;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i]<mn){
         mn=nums[i];
         min_index=i;
        }
        if(nums[i]>mx){
         mx=nums[i];
         max_index=i;
        }
    }
    int front=max(min_index,max_index)+1;
    int back=n-min(min_index,max_index);
    
    int mixed=min(min_index+1+(n-max_index),max_index+1+(n-min_index));

    return min({front,back,mixed});
    }
};