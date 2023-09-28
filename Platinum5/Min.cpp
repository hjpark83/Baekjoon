#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

struct SLW{
    int pos;
    int data;
};
struct cmp{
    bool operator()(const SLW& a, const SLW&b){
        return a.data>b.data;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,L;
    cin>>N>>L;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    priority_queue<SLW,vector<SLW>,cmp> pq;
    for(int i=0;i<N;i++){
        pq.push({A[i],i});
        int pos=pq.top().pos;
        while(pos<i-L+1){
            pq.pop();
            pos=pq.top().pos;
        }
        cout<<pq.top().data<<" ";
    }
    return 0;
}