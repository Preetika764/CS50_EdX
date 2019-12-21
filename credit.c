#include<stdio.h>
int main()
{  printf("Number:");
   long long int num ,x;
   int i,j,sum=0,checksum;
   scanf("%llu", &num);
   int arr[100];
   for(x=num, i=0; x> 0; x/=10, i++)
         arr[i] = x%10;
   int imax = i; //no. of digits in the number
   
   
    for(i=1;i<imax;i+=2)
    { if(arr[i]*2 < 10)
          sum+= arr[i]*2;
      else sum = sum + ((arr[i]*2)%10)+ ((arr[i]*2)/10);
     }
     
     for(i=0;i<imax;i= i+2)
    { 
          sum+= arr[i];
      
     }
    

   if((sum%10)==0)
       checksum = 1; //valid
   else checksum =0; //invalid
 
 //American Express
 if((checksum ==1) && (imax==15)&& (arr[14]==3)&& ((arr[13]==4)||(arr[13]==7)))
     printf("AMEX\n");
 //Mastercard
 else if((checksum==1)&& (imax==16)&&(arr[15]==5)&&((arr[14]==1)||(arr[14]==2)||(arr[14]==3)||(arr[14]==4)||(arr[14]==5)))
     printf("MASTERCARD\n");
 //Visa
 else if((checksum==1)&&((imax==16)||(imax==13))&& (arr[imax-1]==4))
     printf("VISA\n");
 else printf("INVALID\n");
                             
 
   return 0;   
}

