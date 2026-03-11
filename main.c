#include <stdio.h>
#include <stdlib.h>

//float calcArea(float rad);

/*int main()
{

    float x,y;

    y = calcArea(x);

    printf("the area of a circle of radius %g is %g\n",x,y);

    return 0;
}

float calcArea(float rad)
{
    float a;
    a = 3.142*rad*rad;
    return (a);
}*/


/*void avg(int a, int b, int c);

int main()
{

    int x = 3, y = 4, z = 5;
    avg(x,y,z);
    printf("Done\n");
    return 0;
}

void avg(int a,int b, int c)
{
    int w = (a+b+c)/3;

    printf("The average of %d, %d and %d is %d\n",a,b,c,w);
}*/

/*void funct1();
int x = 50;

int main()
{
    int y = 30;
    printf("%d\n",y);
    printf("%d\n",x);
    funct1();
    printf("End\n");

}

void funct1()
{
    int z = 20;
    printf("%d\n",z);
    printf("%d\n",x);

}*/


int funct1(int k);
int main()
{
    int a,b = 0;
    for(a = 0; a < 5 ; a++)
    {
        b = funct1(a);
        printf("%d\t",b);
    }
    return 0;
}

int funct1(int k)
{
    int j = 0;
    j += k;
    return (j);
}


