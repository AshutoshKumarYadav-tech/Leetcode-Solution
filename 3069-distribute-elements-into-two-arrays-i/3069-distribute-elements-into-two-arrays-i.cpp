class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
    vector<int>arr1;
    vector<int>arr2;
    vector<int>ans;
    
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);
    for(int k=2;k<nums.size();k++) {
    if(arr1.back()>arr2.back()){
        arr1.push_back(nums[k]);
    }
    else{
        arr2.push_back(nums[k]);
    }
    }
    ans.insert(ans.end(),arr1.begin(),arr1.end());
    ans.insert(ans.end(),arr2.begin(),arr2.end());

    return ans;  
    }
};