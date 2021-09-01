

#include <stdio.h>
void input(float *ptr)
{
    scanf("%f",ptr);
}
void print(float **ptr)
{
    printf("%3.3f",**ptr);
}
void cal(float *ptrT , float *ptrKE , float *ptrU ,float *ptrTax , float *ptrU2)
{
    if (*ptrU > 300)
    {
        *ptrU2 = *ptrU - 300;
        *ptrKE = ((200*8.11)+(100*10.20)+(*ptrU2*13.40));
        *ptrTax = *ptrKE * 0.13;
        *ptrT = *ptrKE + *ptrTax;

        printf("KE Charges:  "); print(&ptrKE);
        printf("\n Sales tax "); print(&ptrTax);
        printf("\n Electric Charges to pay "); print(&ptrT);
    }
    else
    {
        if (*ptrU > 200 && *ptrU < 301)
        {
            *ptrU2= *ptrU - 200;
            *ptrKE = ((200*8.11)+(*ptrU2*10.20));
            *ptrTax = *ptrKE * 0.13;
            *ptrT = *ptrKE + *ptrTax;

            // printf("KE Charges: %.f", KE);
            // printf("\n Sales tax %.2f", tax);
            // printf("\n Electric Charges to pay %.2f", total);
        }
        else
        {
            
            *ptrKE = (*ptrU*8.11);
            *ptrTax = *ptrKE * 0.13;
            *ptrT = *ptrKE + *ptrTax;

        //     printf(" KE Charges: %.f", KE);
        //     printf("\n Sales tax %.2f", tax);
        //     printf("\n Electric Charges to pay %.2f", total);
        // 
        }
        
    }
}
int main()
{
   
float total,KE;
float unit;
float tax;
float unit2;
printf ("Enter the total nunmber of consumed units: ");
input(&unit);
cal(&total ,&KE , &unit , &tax , &unit2);
//print(&unit);
    return 0;
}
