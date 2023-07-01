#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ans;
    vector<int>count;
public:
    int distributeCookies(vector<int>& cookies, int k) {
        ans=INT_MAX;
        count.resize(k);
         backtrack(0,cookies,k);
        return ans;
    }

    void backtrack(int cookieNumber,vector<int>&cookies,int k)
    {
        if(cookieNumber==cookies.size()){
            int maxi=0;
            for(int i=0;i<k;i++){
                maxi=max(maxi, count[i]);
            }
            ans=min(ans,maxi);
            return ;
        }

        for(int i=0;i<k;i++)
        {
            count[i]+=cookies[cookieNumber];
            backtrack(cookieNumber+1,cookies,k);
            count[i]-=cookies[cookieNumber];
            if(count[i]==0) break;
        }
    }
};