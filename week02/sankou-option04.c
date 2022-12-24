#include <stdio.h>
#include <ctype.h>

int main()
{
  // int c, chars = 0, spaces = 0;
  int i = 0;
  int j = 0;
  int c;




 c = getchar();
 while (c != EOF) {
   putchar(c);
   if (c != '\n')
     j++;
   /*
   if(!isspace(c))
     chars++;
   else if(c == ' ')
     spaces++;
   c = getchar();
 }
 chars += spaces;
   */
   if (c == 't') {
     c = '+';
     i++;
   }
   c = getchar();
 }





   printf("文字数: %d\n", j/*chars*/);
   printf("aの数: %d\n", i/*spaces*/);
return 0;
}
