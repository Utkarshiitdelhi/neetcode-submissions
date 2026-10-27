class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        vector<int> pre(n), suff(n);
        for(int i =0; i < n; i++){
            if(i == 0) {
                pre[i] =1;
                suff[n-i-1] =1;
            }
            else {
                pre[i] = pre[i-1] * nums[i-1];
                suff[n-i-1] = suff[n-i] * nums[n-i];
            }
        }
        for(int i =0; i < n; i++){
            output[i] = pre[i]*suff[i];
        }
        return output;
    }
};
