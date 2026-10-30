class DSU{
    public:
    vector<int> Parent, Size;

    DSU (int n): Parent(n + 1), Size(n+1, 1){
        for(int i = 0; i <= n; ++i) Parent[i] = i;
    }
    int find(int node){
        if(Parent[node] != node){
            Parent[node]= find(Parent[node]);
        }
        return Parent[node];
    }
    bool findunion(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        if(Size[pu] > Size[pv]) {
            Parent[pv] = pu;
            Size[pv]+= Size[pu];
        }else{
            Parent[pv]= pu;
            Size[pu] += Size[pv];
        }
        return true;
    }

};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<array<int,3>> edges;
        int n = points.size();
        int sum = 0;
        DSU dsu(n);
        for(int i =0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int dist = abs(points[i][0] - points[j][0])+ abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        for(auto& [dist, a, b]: edges){
            if(dsu.findunion(a,b)){
                sum+=dist;
            }
        }
        return sum;
    }
};
