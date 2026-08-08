class Solution {
public:
   
   unordered_map<string,int> mp;

   int getinvalid(string &s){
   stack<char> st;

   for(char &ch:s){
    if(ch=='('){
        st.push('(');
    }else if(ch==')' &&  st.size()>0 && st.top()=='('){
        st.pop();
    }else if(ch==')'){
        st.push(')');
    }
   }
    return st.size();
   }
   void solve(string s, int mininv, vector<string> &res){
    if(mp[s] !=0)
    return ;
    else
    mp[s]++;

    if(mininv<0){
        return ;
    }
    if(mininv == 0){
        if(!getinvalid(s))
        res.push_back(s);
        return ;
    }
    for( int i=0; i<s.size();i++){
        string  left =s.substr(0,i);
        string  right=s.substr(i+1);
        solve(left+right,mininv-1,res);
    }
    return ;
   }



    vector<string> removeInvalidParentheses(string s) {
     vector<string> res;
        solve(s,getinvalid(s),res);
        return res;
    }
};