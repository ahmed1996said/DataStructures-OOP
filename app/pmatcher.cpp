//
// Created by Ahmed Al Mahrooqi on 2019-02-04.
//

#include <cstdio>
#include <cstring>
#include <ParenMatcher.h>

int main(){


    char input[100];
    int quit;
    ParenMatcher p;

    printf("- Enter string to check: \n- 'q' to exit\n- Limit to 100 characters\n");

 do{

      memset(input,'\0', sizeof(input));    //clear input buffer
      gets(input);

      quit = strcmp(input,"q");
      if(quit==0)
          break;

      p.check(input) ? printf("Balanced.\n") : printf("Non-balanced.\n");



 }
while(1);


    return 0;
}