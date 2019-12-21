#include<stdio.h>
int encrypt(char c, int key)
{ int x = c;
  key%=26;
  if(x<=90 && x>=65)
      { if(x+key <=90)
         x+=key;
         else x = 64 + ((x+key)%90);
      }
   if(x<=122 && x>=97)
     {if(x+key<=122)
      x+=key;
      else x = 96 + ((x+key)%122);
      }
     return x;

}

int obtainkey(char c)
{ int x = c;
  if(x>=65 && x<=90)
     x = x-65;
   else if (x>=97 && x<=122)
     x = x-97;
   return x;
  }
  
 int checkalphabet(char c)
 { int x = c;
   
   if(x<=90 && x>=65)
       return 1;
   else if(x<=122 && x>=97)
       return 1;
   else if (c = ' ')
      return 0;
   else return 0;
  
 }
  
 

int main()
{   char key[100],c, plaintext[100];
    int i,imax,kmax;
    for(i=0;(c = getchar())!='\n';i++)
       { key[i] = c;
       }
    kmax = i; //no. of characters in key
       for(i=0;i<kmax;i++)
          { if(checkalphabet(key[i])==0)
                   { printf("Usage: ./vigenere keyword"); return 1;}}
    int keyno[kmax];
     for(i=0;i<kmax;i++)
       keyno[i] =  obtainkey(key[i]);
 
          printf("Plaintext:");
     for(i=0;(c= getchar())!='\n';i++)
            plaintext[i] = c;
         imax = i;
         plaintext[imax] = '\0';
   char ciphertext[imax]; int j;
  for(i=0,j=0;i<imax;i++)
  {   if(plaintext[i]== ' ')
          ciphertext[i] = ' ';
          
     else { ciphertext[i] =  encrypt(plaintext[i], obtainkey(key[j]));
            j++;
      if(j== kmax)
           j=0;
  }}
  ciphertext[imax] = '\0';
 printf("\n ciphertext:");
  for(i=0;i<imax;i++)
      putchar(ciphertext[i]);
   
    

    return 0;
                            
}
