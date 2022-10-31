class Solution {
public:
    bool cycledetect(vector<bool> &visited,int curval,vector<int> adj[],vector<bool> &curvis)
    {
        visited[curval]=true;
        curvis[curval]=true;
        for(auto x : adj[curval])
        {
            if(!visited[x])
            {
                if(cycledetect(visited,x,adj,curvis)) return true;
            }
            else if(visited[x]&&curvis[x]) return true;
        }
        curvis[curval]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> visited(n,false);
        vector<bool> curvis(n,false);
        vector<int> adj[n];
        for(auto x : prerequisites)
        {
            adj[x[0]].push_back(x[1]);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                if(cycledetect(visited,i,adj,curvis)) return false;            
        }
        return true;        
    }
};
