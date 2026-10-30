class Solution {
public:

    int find(int k, vector<int> &parent){
        if(k != parent[k]) parent[k] = find(parent[k], parent);
        return parent[k];
    }
    bool unions(int n1, int n2, vector<int> &rank, vector<int> &parent){
        int p1 = find(n1, parent), p2 = find(n2, parent);
        if(p1 == p2) return false;

        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }else{
            parent[p1] = p2;
            rank[p2]+= rank[p1];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        for(int i =0; i < n + 1; i++) parent[i] = i ;
        vector<int> rank(n + 1 ,1);

        for(auto it: edges){
            if(!unions(it[0],it[1], rank, parent))return {it[0],it[1]};
        }
        return {};

    }
};
