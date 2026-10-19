class Solution {
public:
    int maxArea(vector<int>& height) {
    int n=height.size();
    int low=0;
    int high=n-1;
    int ans=0;
    while(low<high)
    {
        int min_num=min(height[low],height[high]);
        int area =min_num*(high-low);

        ans=max(ans,area);
        if(height[low]<height[high]){
            low++;
        }else{
            high--;
        }

    }
    return ans;
    }
};