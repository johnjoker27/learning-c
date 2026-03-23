#include <stdio.h>
#include <stdlib.h>

/*void swap(int *n,int *b);

int main()
{
    //pointers are variables that store the address of other variables.
    int a = 25;
    int *m;
    m = &a;
    //pointer assigning rules states that: the data type should be the same as that of the variable whose address it holds.
    int e = 57;
    void*z=&e;
    //deferencing is accessing the value of the function whose pointer was made.
    int x = 32;
    int *r=&x;
    //passing by referece(passing pointers to functions)
    printf("before swapping:\n");
    printf("a=%d\n",a);
    printf("e=%d\n",e);

    swap(&a,&e);//passing pointers to functions

    printf("after swapping:\n");
    printf("m=%d\n",a);
    printf("a=%d",e);

    return 0;
}

void swap(int *n,int *b)
{
    int temp;
    temp = *n;
    *n=*b;
    *b=temp;
}
*/

void func1(int u,int v);
void func2(int*pu,int*pv);

int main()
{
    int u = 1;
    int v = 2;

    printf("\nBefore calling func1:u=%d,v=%d\n",u,v);
    func1(u,v);
    printf("\nAfter calling func1:u=%d,v=%d\n",u,v);

    printf("\nBefore calling func2:u=%d,v=%d\n",u,v);
    func2(&u,&v);
    printf("\nAfter calling func2:u=%d,v=%d\n",u,v);

    return 0;
}

void func1(int u,int v)
{
    u=0;
    v=0;
    printf("\nWithin func1u=%d,v=%d",u,v);

}

void func2(int *pu,int *pv)
{
    *pu=0;
    *pv=0;
    printf("Within func2:*pu=%d,*pv=%d",*pu,*pv);

}
