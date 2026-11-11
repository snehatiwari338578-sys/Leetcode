class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long a = (long long)need1 * cost1 + (long long)need2 * cost2;

        long long b = (long long)costBoth * max(need1, need2);

        int mn = min(need1, need2);

        long long c = (long long)mn * costBoth
                    + (long long)(need1 - mn) * cost1
                    + (long long)(need2 - mn) * cost2;

        return min(a, min(b, c));
    }
};
