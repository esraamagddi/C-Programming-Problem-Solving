#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    char z;
    printf("calculate two numbers: ");
    scanf("%d",&x);
    scanf(" %c",&z);
    scanf("%d",&y);

//printf("%d %d %c",x,y,z);

    switch(z)
    {
    case '+': printf("%d",x+y);
    break;
    case'-': printf("%d",x-y);
    break;
    case '*': printf("%d",x*y);
    break;
    case '/':
        if (y==0)
            printf("error");
        else
         printf("%f",(float)x/y);
    break;
    default:
        break;

    }


    return 0;
}
