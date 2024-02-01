#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        // code here
        unordered_map<int, vector<int>> mp;
    
        for (auto it : edges) {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        set<pair<int, int>> st;
        vector<int> dis(n, 1e9);

        st.insert({0, src});
        dis[src] = 0;

        while (!st.empty()) {
            auto x = *(st.begin());
            int dist = x.first;
            int node = x.second;
            st.erase(st.begin());

            for (auto it : mp[node]) {
                if (dist + 1 < dis[it]) {
                    if (dis[it] != 1e9) {
                        st.erase({dis[it], it});
                    }
                    dis[it] = dist + 1;
                    st.insert({dis[it], it});
                }
            }
        }
        for(int i=0; i<n;i++){
            if(dis[i]==1e9) dis[i]=-1;
        }
        return dis;
    }
};