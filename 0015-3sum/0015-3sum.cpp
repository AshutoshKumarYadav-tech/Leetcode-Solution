class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            if (j != i + 1 && nums[j] == nums[j - 1]) {
                j++;
                continue;
            }
            int sum = nums[j] + nums[k];
            if (sum == -nums[i]) {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
            } else if (sum < -nums[i]) {
                j++;
            } else {
                k--;
            }
        
        }
    }
    return ans;    
    }
};