class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>duplicate;
        for(int x:nums){
            if(duplicate.count(x)){
                return x;
            }
            duplicate.insert(x);
        }
        return -1;
    }
};