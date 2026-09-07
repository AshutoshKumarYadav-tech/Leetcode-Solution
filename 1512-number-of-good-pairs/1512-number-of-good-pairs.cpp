class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
    int n=nums.size() ;
    int i=0;
    int j=i+i;
    int count=0;
    while(i<n){
     for(int j=i+1;j<n;j++){
        if(nums[i]==nums[j]){
            count++;
        }
     }
     i++;
        
    }
return count;
    }
};