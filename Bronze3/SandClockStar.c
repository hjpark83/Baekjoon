#include <stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        for(int j=0;j<i;j++){
            printf(" ");
        }
        for(int k=i+1;k<2*num-i;k++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=num-1;i>0;i--){
        for(int j=i-1;j>0;j--){
            printf(" ");
        }
        for(int k=2*num-i+1;k>i;k--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}