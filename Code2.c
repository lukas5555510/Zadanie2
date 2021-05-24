/*Code2.c*/
#include "area.h"
#include "capacity.h"
#include<stdio.h>

void options(int *a)
{
    printf("1. Prostokat\n");
    printf("2. Prostopadloscian\n");
    printf("3. wyjscie z programu\n");
    scanf("%d",&*a);
}

void setdata(float *a,float *b);
void setdata_cuboid(float *a,float *b,float *h);

void printdata(float area);
void printdata_cuboid(float area_cuboid, float capacity);

int main()
{

    int choose;
    float a,b,h;
    options(&choose);
    while(choose != 3)
    {
        switch(choose)
        {
         case 1:
            setdata(&a,&b);
            printdata(area(a,b));
            
         break;
         case 2:
            setdata_cuboid(&a,&b,&h);
            printdata_cuboid(cuboid_area(a,b,h),capacity(a,b,h));
         break;
         default: break;
        }
        options(&choose);
    }
    return 0;
}

void setdata(float *a,float *b)
{
    printf("Wprowadz dlugosci bokow:\n");
    scanf("%f%f",&*a,&*b);
}

void setdata_cuboid(float *a,float *b,float *h)
{
    printf("Wprowadz dlugosci bokow oraz wysokosc:\n");
    scanf("%f%f%f",&*a,&*b,&*h);
}

void printdata(float area)
{
    printf("Pole prostkata: %f\n",area);
}

void printdata_cuboid(float cuboid_area, float capacity)
{
    printf("Pole prostopadloscianu: %f\nObjetosc: %f\n",cuboid_area,capacity);
}
