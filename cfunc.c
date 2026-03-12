#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greet(){
    printf("Good morning\n");
}

void calsq(int numb)
{
    int sq = numb * numb;
    printf("The square of %d is %d\n",numb,sq);
}

void addNum(int num1, int num2)
{
    int sum = num1 + num2;
    printf("Sum of %d and %d is %d\n",num1,num2,sum);
}

void doubNum(double nu1,double nu2)
{
    double sub = nu1-nu2;
    printf("%d minus %d is %d\n",nu1,nu2,sub);
}


int multNum(int mult1, int mult2)
{
    int totMult = mult1 * mult2;
    printf("after\n");
    return totMult;


}

int adNum(int n1, int n2)
{
    int t = n1+n2;
    printf("%d",t);
}

int mult1(int m1, int m2)
{
    int tm = m1*m2;
    return tm;
}
int main(){

    greet();
    greet();
    greet();
    printf("After Function call\n");
    calsq(5);
    addNum(3,4);
    doubNum(6.544332,4.5555555);
    int result = multNum(5,6);
    printf("%d is the answer .\n",result);
    adNum(3,10);

    int res = sqrt(49);
    printf("\n%d\n",res);

    int r = mult1(67,76);
    printf("%d",r);


}
