#include <stdio.h>

int main()
{
    int i,j,k,l,m,num,a,num1,num2;
    int c, d;
    a = 17;
    num1 = 10;
    scanf("%d", &c);
    d = c*2-1;
    
  
    num1 = c + 1;
    

    for(i=0;i<=c-1;i++)
    {
        num = c;

        for(j=i;j>0;j--)
        {
            printf("%d  ", num);
            num--;

        }
        for(k=d;k>0;k--)
        {
            printf("%d  ", num);
        }

        d -= 2;
        num2 = num1;
        for(m=i;m>0;m--)
        {

            printf("%d  ", num2);
            num2++;
        }
        num1--;

        printf("\n");
    }
    a = 1;
    l = 2;
    num1 = 2;
    for(i=c-1;i>0;i--)
    {
        num = c;
        for(j=i;j>0;j--)
        {
            printf("%d  ", num);
            num--;
        }

        for(k=a;k>0;k--)
        {
            printf("%d  ", l);

        }
        num2 = num1;
        for(m=i;m>0;m--)
        {
            printf("%d  ", num2);
            num2++; 
        }
        num1++;
        a += 2;
        l++;



        printf("\n");
    }

}
