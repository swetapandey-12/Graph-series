class Solution {
       
  public:
     void dfs(int i , int s,vector<vector<int>> &adj, vector<int>& vis, bool & a ,int & node){
        vis[i]=1;
        node++;
        if(s!=adj[i].size()){
            a=false;
        }
        for(auto x: adj[i])
        {
          if(vis[x])dfs(x,s,adj,vis,a,node);
        }
    }
       
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        int ans=0;
        vector<int>vis(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!vis[i]){
                int node=0;
                bool a=true;
                dfs(i, adj[i].size(),adj,vis,a,node);
                if(a and node-1==adj[i].size())ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
