/*class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
    int n=nums.size();
    int player1;
    int player2;
    int player1_sum=0;
    int player2_sum=0;
    for(int i=0;i<n;i++){
        if(player1 && nums[i]){
            player1_sum+=nums[i];
            nums.erase(nums.begin() + i);
        }
        else{
         player1_sum+=nums[n-i];
        nums.erase(nums.begin() + (n-i));   
        }
        else if(palyer2 && nums[i]){
           if(player2 && nums[i]){
            player2_sum+=nums[i];
            nums.erase(nums.begin() + i);
           }
           else{
           player2_sum+=nums[n-i];
           nums.erase(nums.begin() + (n-i));   
           }  
        }
    }
    if(player1_sum>=player2_sum){
        return true;
    }
    else{
        return false;
    }   
    }
};*/
class Solution {
public:
    int solve(vector<int>& nums, int i, int j) {
        if (i == j)
            return nums[i];

        int left = nums[i] - solve(nums, i + 1, j);
        int right = nums[j] - solve(nums, i, j - 1);

        return max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};