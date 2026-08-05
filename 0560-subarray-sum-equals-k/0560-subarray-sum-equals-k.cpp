class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    /*int n=nums.size();
    long long sum=0;
    int max=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++) {
        sum+=nums[i];
        if(sum==k) {
            max=i+1;
        }
        if(m.find(sum-k)!=m.end()) {
            int len = i - m[sum-k];
            if(len>max) {
                max=len;
            }
        }
        if(m.find(sum)==m.end()) {
            m[sum]=i;
        }
    }
     return max;*/
unordered_map<int,int> mp;

mp[0] = 1;

int prefix = 0;
int count = 0;

for(int x : nums)
{
    prefix += x;

    if(mp.find(prefix - k) != mp.end())
    {
        count += mp[prefix - k];
    }

    mp[prefix]++;
}

return count;
    }  
};