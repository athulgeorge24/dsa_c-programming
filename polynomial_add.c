#include <stdio.h>

int main()
{
struct poly
{
    int coef;
    int expo;
}p1[10],p2[10],r[20];

int i=0,j=0,k=0,n,m;
printf("Enter the no of terms in first and second polynomial:");
scanf("%d%d",&m,&n);

printf("Enter the first polynomial : \n");
for(i=0;i<m;i++)
{
  printf("Enter the coefficient and exponent of term %d : ",i+1);
  scanf("%d%d",&p1[i].coef,&p1[i].expo);
}
printf("Enter the second polynomial : \n");
for(i=0;i<n;i++)
{
  printf("Enter the coefficient and exponent of term %d : ",i+1);
  scanf("%d%d",&p2[i].coef,&p2[i].expo);
}

i = 0; j = 0;

while(i<m&&j<n)
{
  if(p1[i].expo==p2[j].expo)
    {
      r[k].coef=p1[i].coef+p2[j].coef;
      r[k].expo=p1[i].expo;
      i++;k++;j++;
    }
  else if(p1[i].expo>p2[j].expo)
    {
      r[k].coef=p1[i].coef;
      r[k].expo=p1[i].expo;
      i++;k++;
    }
  else
    {
      r[k].coef=p2[j].coef;
      r[k].expo=p2[j].expo;
      j++;k++;
    }
}
while (i<m)
  {
    r[k].coef=p1[i].coef;
    r[k].expo=p1[i].expo;
    i++;k++;
  }
while (j<n)
  {
    r[k].coef=p2[j].coef;
    r[k].expo=p2[j].expo;
    k++;j++;
  }
  
for(i=0;i<k-1;i++)
{
  printf("%d""x^""%d",r[i].coef,r[i].expo);
  printf("+");
}
  printf("%d""x^""%d""\n",r[k-1].coef,r[k-1].expo);

return 0;
}
