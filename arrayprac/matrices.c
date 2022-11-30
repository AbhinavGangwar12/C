#include <stdio.h>
int main() {
    int a[3][3],b[3][3],c[3][3];
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            printf("Enter the value for 1st matrice %d row and %d column : ", i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    for(int t = 0;t<3;t++){
        for(int q = 0;q<3;q++){
            printf("Enter the value for 2nd matrice %d row and %d column : ", t+1,q+1);
            scanf("%d",&b[t][q]);
        }
    }
    for(int u = 0;u<3;u++){
        for(int w = 0;w<3;w++){
            c[u][w] = a[u][w]+b[u][w];
        }
        for(int e = 0;e<3;e++){
            printf("%d ", a[u][e]);
        }
        printf("\t");
        for(int r = 0;r<3;r++){
            printf("%d ", b[u][r]);
        }
        printf("\t");
        // printf("\t");
        for(int y = 0;y<3;y++){
            printf("%d ", c[u][y]);
        }
        printf("\n");
    }
    return 0;
}
