class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
        unordered_map<int,int> mp;
        for(int i =0; i < nums.size(); i++){
            if(mp[nums[i]]) return {mp[nums[i]] -1, i};
            mp[target - nums[i]] = i + 1;
        }
        return {-1};
    }
};
