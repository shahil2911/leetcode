//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solver(int i,int j, vector<vector<int>> &maze,int n,vector<string>& ans,string path,vector<vector<int>>&temp,int di[],int dj[] ){
        if(i==n-1&&j==n-1){
            ans.push_back(path);
            return;
        }
        string direction="DLRU";
        for(int k=0;k<4;k++){
            int nexti=i+di[k];
            int nextj=j+dj[k];
            if(nexti>=0 && nexti<n && nextj>=0 && nextj<n && !temp[nexti][nextj] && maze[nexti][nextj]==1){
                temp[i][j]=1;
                solver(nexti,nextj,maze,n,ans,path+direction[k],temp,di,dj);
                temp[i][j]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string>ans;
        vector<vector<int>>temp(n,vector<int>(n,0));
        int di[]={+1,0,0,-1};
        int dj[]={0,-1,+1,0};
        if(maze[0][0]==1)   solver(0,0,maze,n,ans,"",temp,di,dj);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends