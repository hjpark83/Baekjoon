#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool isPalin(const string& str){
    int len=str.length();
    for(int i=0;i<len/2;i++){
        if(str[i]!=str[len-i-1])
            return false;
    }
    return true;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    cin>>num;

    int len=num.length();
    long long target = stoll(num) + 1;

    if(num==string(len,'9')){
        cout<<target+1<<'\n';
    }else if(len==1){
        cout<<target<<'\n';
    }else{
        while(true){
            if(isPalin(to_string(target))){
                cout<<target<<'\n';
                break;
            }
            target++;
        }
    }
    return 0;
}