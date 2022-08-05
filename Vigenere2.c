#include <stdio.h>
#include <string.h>
#include <ctype.h>

void changearray(int array[26][26]){
    for(int i=0;i<=25;i++){
        for(int j=0;j<=25;j++){
            array[i][j]=(i+j)%26;
        }
    }
}

void tolownum(char arraytolow[11]){
for(int i=0;i<=9;i++){
    arraytolow[i]=(tolower(arraytolow[i]))-97;
}
}

int main() {
int again=1;
int cipherarray[26][26];
char keyarray[11];
char textarray[11];
char outputletter;

changearray(cipherarray);
printf("Please type the 10 letter key\n");
scanf("%10s",&keyarray);
tolownum(keyarray);
do{
printf("Please type the text 10 letters at a time(do not have spaces)\n");
scanf("%10s",&textarray);

tolownum(textarray);

for(int i=0;i<=strlen(textarray)-1;i++){
    outputletter=(cipherarray[textarray[i]][keyarray[i]])+65;
    printf("%c",outputletter);
    if(i==9){
        printf("\n");
    }    
}
printf("print 1 if you want to continue, 0 if you want to end here\n");
scanf("%2d",&again);
}while(again==1);
return 0;
}