#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

int plus(char *num1, char *num2, char *ans);

int main()
{
    char num1[MAXLEN + 1], num2[MAXLEN + 1], ans[MAXLEN + 2];
    scanf("%s", num1);
    scanf("%s", num2);
    plus(num1, num2, ans);
    printf("%s", ans);
    return 0;
}

int plus(char *num1, char *num2, char *ans)
{
    int num1len = strlen(num1), num2len = strlen(num2), max, i;
    //printf("num1len = %d, num2len = %d ", num1len, num2len);
    if (num1len > num2len)

        max = num1len;

    else if (num1len < num2len)

        max = num2len;

    else

        max = num1len;

    char *tempans = (char *)malloc(sizeof(char) * max + 2);
    //*(tempans + max + 1) = '\0';
    //printf("max = %d\n", max);
    int carry = 0;
    for (i = max - 1; i >= 0; i--)
    {
        char temp;

        if (num1len - 1 < 0)
        {
            //printf("num2[num2len-1] = %d\n", num2[num2len]);
            temp = num2[num2len - 1];
            num2len--;
        }
        else if (num2len - 1 < 0)
        {
            //printf("num1[num1len-1] = %d\n", num1[num1len]);
            temp = num1[num1len - 1];
            num1len--;
        }
        else
        {
            //printf("num1[num1len-1] = %d, num2[num2len-1] = %d\n", num1[num1len - 1], num2[num2len - 1]);
            temp = num1[num1len - 1] + num2[num2len - 1] - '0';
            num1len--;
            num2len--;
        }
        //printf("tempbefore = %d ", temp);
        if (carry > 0)
        {
            temp += carry;
            carry--;
        }
        if (temp > '9')
        {
            temp -= 10;
            carry += 1;
        }
        //printf("tempafter = %d tempchar = %c\n", temp,temp);
        *(tempans + max) = temp;
        max--;
    }
    if (carry > 0)
    {
        tempans[0] = '1';
        strcpy(ans, tempans);
        return 1;
    }
    else
    {
        strcpy(ans, tempans + 1);
    }
}
