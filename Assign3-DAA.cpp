// fractional knapsack
#include<bits/stdc++.h>
using namespace std;
struct cnt{
    int val;
    int wei;
};
bool cmp(cnt l,cnt r){
    double lf=l.val/l.wei;
    double rf=r.val/r.wei;
    return lf>rf;
}
void fx(int n, vector<cnt>arr){
    sort(arr.begin(),arr.end(),cmp);
    double mxv=0;
    cout<<"Max value is: ";
    cin>>mxv;
    double fval=0;
    for (int i=0;i<n;i++){
        if(mxv>=arr[i].wei){
            mxv=mxv-arr[i].wei;
            fval=fval+arr[i].val;
        }
        else{
            double fw=mxv/arr[i].wei;
            fval=fval+(fw*(arr[i].val));
            break;
        }
    }
    cout<<"max value is: "<<fval;
}
int main(){
    int n=0;
    cout<<"Enter number of values: ";
    cin>>n;
    vector<cnt>arr(n);
    for(int i=0;i<n;i++){
        cnt temp;
        cin>>temp.val>>temp.wei;
        arr[i]=temp;
    }
    fx(n,arr);
}