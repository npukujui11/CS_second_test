/* 
 * 对于任何int型变量x和y，(x>y) == (-x<-y)
 * 不一定成立
 * 当x = -2147483648时，-x = -2147483648
 * 汇编中NEG操作是NOT(reg)+1
 * NOT操作是取反
 */

#include <stdio.h>
int main()
{
    int x = -2147483648;
    int y =3;
    int res;
    res = -x;
    if((x > y)&&(-x < -y))
    {
        printf("1");
        printf("\n");
    }
    else{
        printf("0");
        printf("\n");
    }

    printf("x的值是%d", x);
    printf("\n");
    printf("-x的值是%d", res);
    printf("\n");
    printf("y的值是%d", y);

    return 0;
}