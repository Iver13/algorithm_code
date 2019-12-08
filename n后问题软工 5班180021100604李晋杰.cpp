#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define n 5//n为5时的n后问题 
bool hash[n+1];
int p[n+1];
int count =0;
void Generatep(int index)
{
    if(index == n +1)
    {
        count++;
        for(int k = 1; k <= n; k++ )
        {
            printf("%d ",p[k]);
        }
        printf("\n");
        return ;
    }
    for(int x =1; x <=n; x++)
    {
        if(hash[x] == false)
        {
            bool flag = true;
            for(int pre =1; pre < index; pre++)
            {
                if(abs(index - pre) == abs(x - p[pre]))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                p[index] = x;
                hash[x] = true;
                Generatep(index+1);
                hash[x] = false;
            }
        }
    }
}

int main()
{
    for(int m =0; m <=8; m++)
    {
        hash[m] = false;
    }

    Generatep(1);
    printf("%d\n",count);
    return 0;
}

