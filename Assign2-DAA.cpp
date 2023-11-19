// JOB SEQ WITH DEADLINE
#include<bits/stdc++.h>
using namespace std;
struct job{
    string name;
    int dead;
    int pro;
};
bool cmp(job l, job r){
    return l.pro>r.pro;
}
void jsq(int n,vector<job>arr){
    sort(arr.begin(),arr.end(),cmp);
    vector<job> r(n);
    vector<bool> vist(n,false);
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].dead)-1;j>=0;j--){
            if(vist[j]==false){
                r[j] = arr[i];
                vist[j]=true;
                break;
            }
        }
    }
    int prof=0;
    cout<<"Sequ : ";
    for(int i=0;i<n;i++){
        if(vist[i]==true){
            cout<<r[i].name<<"-->";
        }
        prof=prof+r[i].pro;
    }
    cout<<endl;
    cout<<"Profit is: "<<prof;
}
int main(){
    int n=0;
    cout<<"Number of Jobs: ";
    cin>>n;
    vector<job>arr(n);
    for(int i=0;i<n;i++){
        job temp;
        cin>>temp.name>>temp.dead>>temp.pro;
        arr[i] = temp;
    }
    jsq(n,arr);
}