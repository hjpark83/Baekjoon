#include <iostream>
#include <vector>
#include <cmath>

#define MAX_NUM 100000
using namespace std;

bool isOddPrime(int n) {
    if (n<=1||n%2==0) {
        return false;
    }
    for (int i=3;i*i<=n;i+=2) {
        if (n%i==0){
            return false;
        }
    }
    return true;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> A(MAX_NUM+1,1);
    A[0]=A[1]=0;

    for(int i=2;i<=sqrt(MAX_NUM);i++){
        for(int j=i*i;j<=MAX_NUM;j+=i){
            A[j]=0;
        }
    }
    vector<int> B;
    for(int i=3;i<=100;i++){
        if(A[i]==1){
            B.push_back(i);
        }
    }
    
    while(1){
        int num;
        cin>>num;
        if(num==0){
            break;
        }
        
        bool found=false;
        int i=0,j=B.size()-1;
        int resultA=0, resultB=0;

        while(i<=j){
            int sum=B[i]+B[j];
            if(sum==num){
                if(B[j]-B[i]>resultB-resultA && isOddPrime(B[j]) && isOddPrime(B[i])){
                    resultA=B[i];
                    resultB=B[j];
                }
                found=true;
                i++;
                j--;
            }else if(sum>num){
                j--;
            }else if(sum<num){
                i++;
            }
        }
        if(found){
            if(resultA!=0&&resultB!=0){
                cout<<num<<" = "<<resultA<<" + "<<resultB<<'\n';
            }else{
                cout<<"Goldbach's conjecture is wrong.\n";
            }
        }else{
            cout<<"Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}