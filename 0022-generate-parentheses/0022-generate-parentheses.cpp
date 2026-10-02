class Solution {
public:
  
  vector<string>ans;
  void solve(int n,int open,int close,string temp){
    if(temp.size()==2*n){
        ans.push_back(temp);
        return;
    }
    if(open<n){
        solve(n,open+1,close,temp+'(');
    }
    if(close < open){
        solve(n,open,close+1,temp+')');
    }
  }


    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
        return ans;
        
    }
};