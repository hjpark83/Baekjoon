#include <iostream>
using namespace std;

void printStar(int i, int j, int num){
    if((i/num)%3==1 && (j/num)%3==1){
        cout<<" ";
    }else{
        if(num/3==0)
            cout<<"*";
        else
            printStar(i,j,num/3);
    }
}
int main(void){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            printStar(i,j,num);
        }
        cout<<"\n";
    }
    return 0;
}