#include <stdio.h>

int d[15][15], p[10][10]= {0};
path(int u, int v) {
  if(p[u][v] == u)
    printf("%d->" u);
  else {
    path(u, p[u][v]);
    path(p[u][v], v);
  }
}

void floyd(int n) {
  int i, j, k;
  for(k = 1; k <=n; k++) {
    for(i = 1; i <=n; i++) {
      for(j = 1; j <=n; j++) {
        if(d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
          p[i][j] = k;
        }
       }
    }
  }
  printf("THE MATRIX IS \n");
  for(i = 1; i<= n; i++) {
    for(j = 1; j <= n; j++) {
      printf("%d\t", d[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n, e;
  printf("ENTER NO OF VERTICES AND EDGES\n");
  scanf("%d%d", &n, &e);
  for(i = 1; i<= n; i++) {
    for(j = 1; j <= n; j++) {
      if(i == j)
        d[i][j] = 0;
      else
        d[i][j] = 999;
    }
  }
  for(i = 1; i<= e; i++)  {
  scanf(u, v, w);
  d[u][v] = w;
  p[u][v] = u;
  }
  floyd(n);
  printf("ENTER SOURCE & DESTINATION\n");
  scanf(i, j);
  path(i, j);
  printf(j);
}
