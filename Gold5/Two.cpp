#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2000000000
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    
    vector<int> A(N);
    vector<int> solution(2);
    
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    sort(A.begin(),A.end());

    int start=0, end=N-1, min=INF;
    while(start<end){
        int sum=A[start]+A[end];
        if(min>abs(sum)){
            min=abs(sum);
            solution[0]=A[start];
            solution[1]=A[end];

            if(sum==0){
                break;
            }
        }
        if(sum<0){
            start++;
        }else{
            end--;
        }
    }
    for(int i=0;i<2;i++){
        cout<<solution[i]<<" ";
    }    
    return 0;
}