class Solution {
public:
       struct Node {
        long long score;
        vector<int> ids;
    };
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
       int n = intervals.size();

        // {left, right, weight, original_index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by left endpoint
        sort(a.begin(), a.end());

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: Don't take current interval
                Node skip = dp[i + 1][k];

                // Option 2: Take current interval
                int right = a[i][1];

                // First interval whose left > right
                int lo = i + 1;
                int hi = n;

                while (lo < hi) {
                    int mid = lo + (hi - lo) / 2;

                    if (a[mid][0] > right)
                        hi = mid;
                    else
                        lo = mid + 1;
                }

                int next = lo;

                Node take = dp[next][k - 1];

                take.score += a[i][2];
                take.ids.push_back(a[i][3]);

                // Keep indices sorted for lexicographical comparison
                sort(take.ids.begin(), take.ids.end());

                if (take.score > skip.score ||
                    (take.score == skip.score && take.ids < skip.ids)) {
                    dp[i][k] = take;
                }
                else {
                    dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].ids;   
    }
};