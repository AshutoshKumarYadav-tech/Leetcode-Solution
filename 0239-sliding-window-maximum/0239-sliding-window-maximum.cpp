class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     /*vector<int>ans;
     int low=0;
     int high=k-1;
   
    while(high<nums.size()){
         int maxi=INT_MIN;
     for(int i=low;i<=high;i++){
        
        if(nums[i]>maxi){
            maxi=nums[i];
        }
     }
      ans.push_back(maxi); 
     low++;
     high++;
     }
     return ans;  */

      vector<int> ans;
      deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {

            // Window ke bahar ke elements remove
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Chhote elements remove
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Window complete hone ke baad answer
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }

};