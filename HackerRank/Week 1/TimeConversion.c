#include <stdio.h>;
#include <string.h>;
#include <stdlib.h>;

int main(){
    char s[10];
    gets(s);
    
    if(s[8]=='A'){      //AM format
     if(s[0]=='1' && s[1]=='2')
     s[0]=s[1]='0';
        
    }
    else {
    if (s[1]=='8') {    //PM Format
    s[0]='2';
    s[1]='0';
    }
    else if (s[1]=='9') {
    s[0]='2';
    s[1]='1';
    }
    else if (!(s[0]=='1'&& s[1]=='2')) {
    s[0]+=1;
    s[1]+=2;
    } 
    }
    s[8]='\0';
    puts(s);
    return 0;
    
}