class Solution {
public:
    int Solve(string &word1,string &word2,int i,int j,int &s1,int &s2,vector<vector<int>>&dp){
        if(i==s1){
            return s2-j;
        }
        if(j==s2){
            return s1-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return Solve(word1,word2,i+1,j+1,s1,s2,dp);
        }
        else{
           int replace = 1 + Solve(word1,word2,i+1,j+1,s1,s2,dp);
           int del = 1 + Solve(word1,word2,i+1,j,s1,s2,dp);
           int insert = 1 + Solve(word1,word2,i,j+1,s1,s2,dp);
           dp[i][j]= min({replace,del,insert});
            return dp[i][j];
        }
    }
    int minDistance(string word1, string word2) {
        int s1 = word1.length();
        int s2 = word2.length();
        vector<vector<int>>dp(s1,vector<int>(s2,-1));
        return Solve(word1,word2,0,0,s1,s2,dp);
    }
};