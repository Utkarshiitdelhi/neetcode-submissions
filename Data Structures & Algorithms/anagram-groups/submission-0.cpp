class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            vector<int> count(26,0);
            for(auto s: strs[i]){
                count[s - 'a'] +=1;
            }
            mp[count].push_back(strs[i]);
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
