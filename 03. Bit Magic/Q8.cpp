class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    int f=0;
        for(int i=0; i<N;i++)
        {
          for(int j=0;j<M;j++)
          {
            if(mat[i][j]==X)//searches the element in the matrix
            {
                f=1;
                break;
            }
          }
        }
        return f;
	}
};
