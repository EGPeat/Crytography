#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
todo:
Clean up code
Make it so it runs with differently sized inputs
*/

int main() {
int again=1;
int cipherarray[26][26];
char keyarray[11];
char textarray[11];
int outputarray;
char outputletter;
for(int i=0;i<=25;i++){
    for(int j=0;j<=25;j++){
        cipherarray[i][j]=(i+j)%26;
    }
}

printf("Please type the 10 letter key\n");
scanf("%10s",&keyarray);
for(int i=0;i<=9;i++){
    keyarray[i]=(tolower(keyarray[i]))-97;
}

do{
printf("Please type the text 10 letters at a time(do not have spaces)\n");
scanf("%10s",&textarray);

for(int i=0;i<=9;i++){
    textarray[i]=(tolower(textarray[i]))-97;
}

for(int i=0;i<=strlen(textarray)-1;i++){
    outputarray=cipherarray[textarray[i]][keyarray[i]];
    outputletter=outputarray+65;
    if(i==9){
        printf("%c\n",outputletter);
    }
    else{
    printf("%c",outputletter);
    }
}

printf("print 1 if you want to continue, 0 if you want to end here\n");
scanf("%2d",&again);

}while(again==1);
return 0;
}