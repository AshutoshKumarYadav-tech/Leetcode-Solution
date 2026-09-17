class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
            int n = arr.size();
        int INF = 1e9;

        vector<int> dp(n + 1, INF);
        int ans = INF;

        int left = 0, sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int len = right - left + 1;

                // Previous non-overlapping subarray
                if (dp[left] != INF) {
                    ans = min(ans, len + dp[left]);
                }

                // Best single subarray till right
                dp[right + 1] = min(dp[right], len);
            } 
            else {
                dp[right + 1] = dp[right];
            }
        }

        return ans == INF ? -1 : ans;   
        
    }
};