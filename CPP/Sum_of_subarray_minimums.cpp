class Solution {
public:
    int p = 1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        stack<int> s;
        int ans= 0;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                dp[i] = (arr[i]*(n-i))%p;
            }else{
                while(!s.empty() && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    dp[i] = (arr[i]*(n-i))%p;
                }else{
                    dp[i] = ((arr[i]*(s.top() - i))%p + (dp[s.top()])%p)%p;
                }
            }
            ans = (ans + dp[i])%p;
            s.push(i);
        }
        return ans;
    }
};
