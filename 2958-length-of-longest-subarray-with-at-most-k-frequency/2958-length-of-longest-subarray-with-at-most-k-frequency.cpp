class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
    unordered_map<int,int>freq;
    int ans=0;
    int i=0;
    for(int j=i;j<nums.size();j++){
    freq[nums[j]]++;

    while(freq[nums[j]]>k){
    freq[nums[i]]--;
    i++;
    }
    ans=max(j-i+1,ans);
    } 
    return ans;
    }
};