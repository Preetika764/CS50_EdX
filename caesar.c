#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int encrypt(char c, int key)
{ int x=c;
  key%=26;
  if(x<=90 && x>=65)
      { if(x+key<90)
          x+=key;
        else x = 64 + ((x+key)%90);}
        if(x<=122 && x>=97)
          { if(x+key<=122)
             x+=key;
             else x = 96 + ((x+key)%122);}
             
           return x;
}

 int main(int argc, char * argv[])
 { int i,j,imax,key;
 char plaintext[100],c;
 if(argc ==2 && (atoi(argv[1])!=0))
       {
      int key = atoi(argv[1]);
       printf("plaintext:  ");
       for(i=0;(c= getchar())!='\n';i++)
            plaintext[i] = c;
         imax = i;
         plaintext[imax] = '\0';

        int ciphertext[imax];
        for(i=0;i<imax;i++)
           { ciphertext[i] = encrypt(plaintext[i],key); }
        ciphertext[imax]='\0';
        printf("ciphertext: ");
        for(i=0;i<imax;i++)
          putchar(ciphertext[i]);
        putchar('\n');

}
else printf("Usage: ./caesar key");
return 0;
 }
