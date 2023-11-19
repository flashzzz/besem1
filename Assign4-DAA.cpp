// 
#include<bits/stdc++.h>
using namespace std;
struct cnt{
    int wi;
    int va;
};
void fxn(int n, vector<cnt>arr, int mw){
    vector<int> dp(mw+1,0);
    for(int i=0;i<n;i++){
        for(int j=mw;j>=0;j--){
            if(j>=arr[i].wi){
                dp[j]=max(dp[j],dp[j-arr[i].wi]+arr[i].va);
            }
        }
    }
    cout<<dp[mw];
}
int main(){
    int n=0;
    cin>>n;
    vector<cnt>arr(n);
    for(int i=0;i<n;i++){
        cnt temp;
        cin>>temp.va>>temp.wi;
        arr[i]=temp;
    }
    int mw=0;
    cin>>mw;
    fxn(n,arr,mw);
}