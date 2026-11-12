class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int zeroes=0;
        int maxlen=0;
        int n=nums.size();
        for(int r=0;r<n;r++){
            if(nums[r]==0){
                zeroes++;
            }
            if(zeroes>k){
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            if(zeroes<=k){
                int len=r-l+1;
                maxlen=max(maxlen,len);
            }
        }
        return maxlen;
    }
};