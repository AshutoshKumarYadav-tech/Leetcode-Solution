class Solution {
public:
    string reverseWords(string s) {
    stringstream ss(s);
    /*vector<string> words;
    string word;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    int n = words.size();
    string ans = "";
    
    for (int i =n - 1; i >= 0; i--) {
        ans += words[i] + ' ';
    }
    ans.pop_back();
    
    return ans;*/
  
   string word;
   stack<string>st;
    while(ss>>word){
        st.push(word);
    }
   string ans="";
   while(!st.empty()){
    ans+=st.top();
    st.pop();

    if(!st.empty()){
        ans+=" ";
    }
   }
  return ans;
    }
};