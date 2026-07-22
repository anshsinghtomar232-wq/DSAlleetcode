class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result="";
        int open=0;
        for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            result.push_back(s[i]);
        } else if(s[i]=='('){
            result.push_back(s[i]);
            open++;
        }else if(open>0){
            open--;
            result.push_back(s[i]);
        }

        }

        string fr="";
        int close=0;
        for(int i=result.length()-1;i>=0;i--){
            if(result[i]>='a' && result[i]<='z'){
                fr.push_back(result[i]);
            }else if(result[i]==')'){
                close++;
                fr.push_back(result[i]);
            }else if(close>0){
                close--;
                fr.push_back(result[i]);
            }
        }
        reverse(fr.begin(),fr.end());
        return fr;
        
    }
};