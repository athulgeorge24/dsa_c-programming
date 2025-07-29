#include <stdio.h>


void inputmatrix(int c,int r,int x[r][c])
{
      for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&x[i][j]);
        }
    }
}
void dismatrix(int c,int r,int x[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",x[i][j]);
        }
        printf(" \n");
    }
}
int sparse(int c,int r,int x[c][r],int sparse[100][3])
{
    int k=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(x[r][c]!=0)
                {
                    sparse[k][0]=i;
                    sparse[k][1]=j;
                    sparse[k][2]=x[i][j];
                    k++;
                }
        }
    }
    sparse[0][0]=r;
    sparse[0][1]=c;
    sparse[0][2]=k-1;
    return k;
}

int addsparse(int s1[100][3],int s2[100][3],int res[100][3])
{
    if(s1[0][0]!=s2[0][0] || s1[0][1]!=s2[0][1])
    {
        printf("Invalid matrix dimension");
        return 0;
    }
    int i=1,j=1,k=1;
    res[0][0]=s1[0][0];
    res[0][1]=s1[0][1];
    while(i<=s1[0][2] && j<=s2[0][2])
    {
        if(s1[i][0]==s2[j][0] &&s1[i][1]==s2[j][2])
        {
            res[k][0]=s1[i][0];
            res[k][1]=s2[i][1];
            res[k][2]=s2[i][2]+s2[j][2];
            i++,j++,k++;
        }
        else if(s1[i][0]<s2[j][0] ||(s1[i][0]==s2[j][0] &&s1[i][1]==s2[j][2]))
        {
            res[k][0]=s1[i][0];
            res[k][1]=s1[i][1];
            res[k][2]=s1[i][2];
            i++,k++;
        }
        else
        {
            res[k][0]=s2[j][0];
            res[k][1]=s2[j][1];
            res[k][2]=s2[j][2];
            j++,k++;
        }
    }
    while(i<=s1[0][2])
    {
        res[k][0]=s1[i][0];
        res[k][1]=s1[i][1];
        res[k][2]=s1[i][2];
        i++,k++;       
    }
        while(i<=s2[0][2])
    {
        res[k][0]=s2[j][0];
        res[k][1]=s2[j][1];
        res[k][2]=s2[j][2];
        j++,k++;       
    }
    return k;   

}

int transpose(int src[100][3], int dest[100][3]) 
{
    int rowTerms[100]={0},startPos[100] = {0};
    int rows=src[0][0];
    int cols=src[0][1];
    int numTerms = src[0][2];

    dest[0][0]=cols;
    dest[0][1]=rows;
    dest[0][2]=numTerms;

    for (int i=1;i<=numTerms;i++)
        rowTerms[src[i][1]]++;

    startPos[0]=1;
    for (int i=1;i<cols;i++)
        startPos[i]=startPos[i-1]+rowTerms[i-1];

    for (int i=1;i<=numTerms;i++)
    {
        int col=src[i][1];
        int pos=startPos[col];
        dest[pos][0]=src[i][1];
        dest[pos][1]=src[i][0];
        dest[pos][2]=src[i][2];
        startPos[col]++;
    }

    return numTerms + 1;
}

void printsparse(int sparse[100][3], int P)
{
    printf("Sparse matrix:\n");
    for(int i=0;i<P;i++)
    {
        printf("%d\t%d\t%d\n",sparse[i][0],sparse[i][1],sparse[i][2]);
    }
}


int main()
{
    int r1,r2,c1,c2,i,j,k;
    printf("Enter the rows and column of matrix 1 : \n");
    scanf("%d %d",&r1,&c1);
    int a[r1][c1];
    inputmatrix(r1,c1,a);
    dismatrix(r1,c1,a);
    int s1[100][3];
    int t1=sparse(r1,c1,a,s1);
    printsparse(s1,t1);
    printf("Enter the rows and column of matrix 2 : \n");
    scanf("%d %d",&r2,&c2);
    int b[r2][c2];
    inputmatrix(r2,c2,b);
    dismatrix(r2,c2,b);
    int s2[100][3];
    int t2=sparse(r2,c2,a,s2);
    printsparse(s2,t2);

    int res[100][3];
    int t3=addsparse(s1,s2,res);
    if(t3!=0)
    {
        printf("Sum of sparse matrix");
        printsparse(res,t3);
        int transp[100][3];
        int t4=transpose(res,transp);
        printf("Transposed square matrix");
        printsparse(transp,t4);

    }
    return 0;
}