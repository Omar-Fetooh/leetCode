class Solution {
public:
    string reverseWords(string s) {
      vector<string>words;
      string tempo="";
      for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            tempo+=s[i];
        }
        else if(!tempo.empty()){
            words.push_back(tempo);
            tempo="";
        }
      }  
      if(!tempo.empty()){
        words.push_back(tempo);
      }
      string ans;
      for(int i=words.size()-1;i>=0;i--){
        ans+=words[i];
        if(i!=0) ans+=" ";
      }
      return ans;
    
    }
};