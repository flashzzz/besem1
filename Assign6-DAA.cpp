// 8 queen
#include<bits/stdc++.h>
using namespace std;
int board[8][8]={0};
bool ispossible(int r,int c){
    for(int j=0;j<8;j++){
        if(board[r][j]==1){
            return false;
        }
    }
    for(int j=0;j<8;j++){
        if(board[j][c]==1){
            return false;
        }
    }
    for(int i=r,j=c;j>=0 && i>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=r,j=c;j<8 && i<8;i++,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=r,j=c;j>=0 && i<8;i++,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=r,j=c;j<8 && i>=0;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
void print(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void fx(int r){
    if(r==8){
        print();
        cout<<"\n";
        return ;
    }
    for(int i=0;i<8;i++){
        if(board[r][i]==1){
            fx(r+1);
        }
        else if(ispossible(r,i)==true){
            board[r][i]=1;
            fx(r+1);
            board[r][i]=0;
        }
    }
    return ;
}
int main(){
    print();
    int r=0;
    int c=0;
    cout<<"\n"<<"Give Row and Column with space: ";
    cin>>r>>c;
    board[r][c]=1;
    fx(0);
}