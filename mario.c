#include <cs50.h>
#include <stdio.h>

void spaces(int i, int n)
{ for(int x=0;x<n-i;x++)
      printf(" ");
}
void hashes(int i,int n)
{ for(int x=0;x<i;x++)
      printf("#");
}
int main(void)
{ int n;
  while(1)
{
 printf("Height:");
 scanf("%d",&n);
 if(n<1 || n>8) 
      continue;
for(int i=1;i<=n;i++)
     { spaces(i,n);
       hashes(i,n);
       printf("  ");
       hashes(i,n);
       printf("\n");
      }
      break;
}
 return 0;
}

    
