class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.length();
        vector<int> rightclosetL(n);
        vector<int> leftclosetR(n);

        for(int i=0;i<n;i++){
            if(dominoes[i]=='R')
            {
                leftclosetR[i]=i;
            }
            else if(dominoes[i]=='.'){
                leftclosetR[i]=i>0?leftclosetR[i-1]:-1;
            }else{
                leftclosetR[i]=-1;
            }
        }
       for(int i=n-1;i>=0;i--){
        if(dominoes[i]=='L'){
            rightclosetL[i]=i;
        }
        else if(dominoes[i]=='.'){
            rightclosetL[i]=i<n-1?rightclosetL[i+1]:-1;
        }else{
            rightclosetL[i]=-1;
        }
       }
      string result(n,' ');
      for(int i=0;i<n;i++){
        int distrightL=abs(i-rightclosetL[i]);
        int distleftR=abs(i-leftclosetR[i]);

        if(rightclosetL[i]==leftclosetR[i]){
            result[i]='.';
        }else if(rightclosetL[i]==-1){
            result[i]='R';
        }else if(leftclosetR[i]==-1){
            result[i]='L';
        }else if(distrightL==distleftR){
            result[i]='.';
        }else {
            result[i]=distrightL<distleftR?'L':'R';
        }
      }
       return result;
    }
};