class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
    vector<int>ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++){
        int current=nums[i];
        while(current+1 < nums[i+1]){
            ans.push_back(current+1);
            current++;
        }
    } 
    return ans;   
    }
};