class Solution {
public:
    int sumDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({sumDigits(nums[i]), nums[i]});
        }
        sort(arr.begin(), arr.end());
        vector<int> target;
        for (auto p : arr) {
            target.push_back(p.second);
        }
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                swaps++;
                int j = pos[target[i]];
                pos[nums[i]] = j;
                pos[nums[j]] = i;
                swap(nums[i], nums[j]);
            }
        }
        return swaps;
    }
};