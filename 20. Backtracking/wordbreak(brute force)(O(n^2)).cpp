class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end())
            return true;
    
        for(int i=1;i<s.size();i++){
            string left = s.substr(0,i);
            if(find(wordDict.begin(),wordDict.end(),left)!=wordDict.end() && wordBreak(s.substr(i),wordDict)){
                return true;
            }
        }
        return false;
    }
};