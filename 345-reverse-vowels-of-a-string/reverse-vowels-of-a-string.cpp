class Solution {
public:
   bool isvowel(char &ss){
    
        if(ss=='a'||ss=='e'||ss=='i'||ss=='o'||ss=='u'||ss=='A'||
        ss=='I'||ss=='E'||ss=='O'||ss=='U')

          return true;
          return false;
   }
   


    string reverseVowels(string s) {
        int n=s.length();
        int i=0; int j=n-1;
        while(i<j){
            if(!isvowel(s[i])){
                i++;
            }else if(!isvowel(s[j])){
                j--;
            }else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};