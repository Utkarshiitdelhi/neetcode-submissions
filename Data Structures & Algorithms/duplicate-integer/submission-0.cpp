class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // vector<int> fre(nums.size()); 
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]]) return true;
            else mp[nums[i]]++;
        }
        return false;
    }
};