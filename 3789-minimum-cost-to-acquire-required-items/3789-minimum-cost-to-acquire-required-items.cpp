class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    long long ans=0;
    int mn=min(need1,need2);
    int mx=max(need1,need2);

    long long costA=1LL*cost1*need1+1LL*cost2*need2;
    long long costB=1LL*mn*costBoth+1LL*(need1-mn)*cost1+1LL*(need2-mn)*cost2;
    long long costC=1LL*mx*costBoth;
    return min({costA,costB,costC});
    }
};