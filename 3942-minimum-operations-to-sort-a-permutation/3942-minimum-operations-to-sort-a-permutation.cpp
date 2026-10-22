
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int pos = 0;
        while (nums[pos] != 0) pos++;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = min(pos, n - pos + 2);
        }
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());

        pos = 0;
        while (rev[pos] != 0) pos++;

        ok = true;
        for (int i = 0; i < n; i++) {
            if (rev[(pos + i) % n] != i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, min(pos + 1, n - pos + 1));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
