#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> tree;
void setTree(int i);
void changeVal(int index, long val);
long getSum(int s, int e);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;
    cin>>N>>M>>K;

    int treeHeight=0;
    int Length=N;

    while(Length!=0){
        Length/=2;
        treeHeight++;
    }

    int treeSize=int(pow(2,treeHeight+1));
    int leftNodeStartIndex=treeSize/2-1;

    tree.resize(treeSize+1);

    for(int i=leftNodeStartIndex+1;i<=leftNodeStartIndex+N;i++){
        cin>>tree[i];
    }

    setTree(treeSize-1);

    for(int i=0;i<(M+K);i++){
        long a,s,e;
        cin>>a>>s>>e;
        if(a==1){
            changeVal(leftNodeStartIndex+s,e);
        }else if(a==2){
            s+=leftNodeStartIndex;
            e+=leftNodeStartIndex;
            cout<<getSum(s,e)<<'\n';
        }
    }
    return 0;
}

void setTree(int i){
    while(i!=1){ // 루트노드 갈 때까지 반복
        tree[i/2]+=tree[i];
        i--;
    }
}

void changeVal(int index, long val){
    long diff=val-tree[index];
    while(index>0){
        tree[index]=tree[index]+diff;
        index/=2;
    }
}

long getSum(int s, int e){
    long partSum=0;

    while(s<=e){
        if(s%2==1){
            partSum=partSum+tree[s];
            s++;
        }
        if(e%2==0){
            partSum=partSum+tree[e];
            e--;
        }
        s=(s+1)/2;
        e=(e-1)/2;
    }
    return partSum;
}