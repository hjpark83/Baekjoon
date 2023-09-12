#include <stdio.h>

int n,m;
int num[101]={0,};
int a,b;

void swap(int x, int y){
  int tmp=num[x];
  num[x]=num[y];
  num[y]=tmp;
}

int main() {
  scanf("%d %d",&n,&m);

  for(int i=1;i<=n;i++) {
    num[i]=i;
  }

  for(int i=0;i<m;i++) {
    scanf("%d %d",&a,&b);
    swap(a,b);
  }

  for(int i=1;i<=n;i++) {
    printf("%d ",num[i]);
  }
  return 0;
}