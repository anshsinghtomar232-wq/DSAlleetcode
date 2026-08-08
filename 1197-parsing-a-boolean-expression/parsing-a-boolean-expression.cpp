class Solution {
public:
     char solve(vector<char> values, char op){
      if(op=='!'){
        return values[0]=='t'?'f':'t';
      }

      if(op=='&'){
        return any_of(begin(values),end(values),[](char ch){return ch=='f';})?'f':'t';
      }
      if(op=='|'){
        return any_of(begin(values),end(values),[](char ch){ return ch=='t';})?'t':'f';
        
      }

         return 'f';
     }

    bool parseBoolExpr(string expression) {
       stack<char> st;
       for(char &ch: expression){
        if(ch==','){
            continue;
        }
        if(ch==')'){
            vector<char> values;

            while(st.top()!='('){
                values.push_back(st.top());
                st.pop();
            }
                 st.pop();
                 char op= st.top();
                 st.pop();

                 st.push(solve(values,op));

        }else{
            st.push(ch);
        }
       } 

       return st.top()=='t'?true:false;
    }
};