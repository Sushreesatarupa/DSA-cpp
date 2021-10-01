

int matSearch (int N, int M, int matrix[][M], int x)
{
    if (x<matrix[0][0])return 0;
    for(int i=0;i<N;i++){
        if(x<matrix[i][0])return 0;
        if(x>=matrix[i][0] && i==N-1){
           for(int j=0;j<M;j++) {
               if(matrix[i][j]==x)return 1;
           }
        }
        if(x>=matrix[i][0] && x<matrix[i+1][0]){
            for(int j=0;j<M;j++) {
               if(matrix[i][j]==x)return 1;
           }
        }
    }return 0;
}

