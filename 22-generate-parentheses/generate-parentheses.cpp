class Solution {
public:
    void solver(int n,string str, vector<string> &ans,int open,int close){
        if(open==n && close==n){
            ans.push_back(str);
            cout<<str<<endl;
            return;
        }
        if(open<n){
            solver(n,str+"(",ans,open+1,close);
        }
        if(close<open){
            solver(n,str+")",ans,open,close+1);
        }
        cout<<str<<endl;
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        solver(n,s,ans,0,0);
        return ans;
    }
};