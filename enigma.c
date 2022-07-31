#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void printarray(int arraytoprint[26][2]){
for(int i=0; i<26; i++) {
      for(int j=0;j<2;j++) {
         printf("%d ", arraytoprint[i][j]);
         if(j==1){
            printf("\n");
         }
      }
   }
}

int main() {

//settings

char inputlettertemp;
int inputletter;
//char temporarychararray[4];
//char inputplugboard[23];
//char temporarychararrayrotorchoice[4];
int plugboardarray[26][2];

int wheel0[26][2];
int wheel1[26][2];
int wheel2[26][2];



char wheelofchoices[5][27]={"EKMFLGDQVZNTOWYHXUSPAIBRCJ","AJDKSIRUXBLHWTMCQGZNPYFVOE",
"BDFHJLCPRTXVZNYEIWGAKMUSQO","ESOVPZJAYQUIRHXLNFTGKDCMWB","VZBRGITYUPSDNHLXAWMJQOFECK"};



for(int i=0;i<=25;i++){
    plugboardarray[i][0]=i;
    plugboardarray[i][1]=i;
}

printf("Please type the three rotors you want. A corresponds to rotor #1, up to E equaling rotor #5. Please do it in reverse order\n");
//reverse order is necessary because the rotors are counted out from the reflector, not in from the plugboard
//scanf("%4s",&temporarychararrayrotorchoice);
 char temporarychararrayrotorchoice[]="ABC";
int rotorchoice[3];
 rotorchoice[0]=(tolower(temporarychararrayrotorchoice[0]))-97;
 rotorchoice[1]=(tolower(temporarychararrayrotorchoice[1]))-97;
 rotorchoice[2]=(tolower(temporarychararrayrotorchoice[2]))-97;
printf("rotorsettings are %c %c %c\n in numbers it is %d %d %d\n\n",temporarychararrayrotorchoice[0],temporarychararrayrotorchoice[1],
temporarychararrayrotorchoice[2],rotorchoice[0],rotorchoice[1],rotorchoice[2]);

printf("Please type the three rotor settings (as letters) (i.e. ABC)\n");
//scanf("%4s",&temporarychararray);
//could use ISALPHA to check stuff lol
//set this back up when i actually want to use things lmao. as well as the declaration of the variable earlier
 char temporarychararray[]="ABC";

int rotor1rotation=(tolower(temporarychararray[0]))-97;
int rotor2rotation=(tolower(temporarychararray[1]))-97;
int rotor3rotation=(tolower(temporarychararray[2]))-97;
printf("rotorsettings are %c %c %c\n\n",temporarychararray[0],temporarychararray[1],temporarychararray[2]);


printf("Please type 11 plugboard settings (i.e. if you want A to switch with B and Z to switch with Y, type ABZY.");
printf(" If you use duplicates, it will NOT work\n");
//  ABCDEFGHIJKLMNOPQRSTUV
//scanf("%23s",&inputplugboard);
//set this back up when i actually want to use things lmao. as well as the declaration of the variable earlier
char inputplugboard[]="ABCDEFGHIJKLMNOPQRSTUV";
printf("The character array is... %s\n\n",inputplugboard);

printf("Please type the input letter\n");
//scanf("%1c",&inputlettertemp);
inputlettertemp='A';
printf("The input letter is %c\n\n",inputlettertemp);
inputletter=0;
//inputletter=(tolower(inputlettertemp))-97;




//plugboard setup
for(int i=0;i<=10;i++){
    int firstletter=(tolower(inputplugboard[(i*2)]))-97;
    int secondletter=(tolower(inputplugboard[((i*2)+1)]))-97;
    plugboardarray[firstletter][1]=secondletter;
    plugboardarray[secondletter][1]=firstletter;
}
//plugboard setup ends
int outputletter=plugboardarray[inputletter][1];


for(int j=0;j<=4;j++){
    if(rotorchoice[0]==j){
        for(int i=0;i<=25;i++){
            wheel0[i][0]=i;
            wheel0[i][1]=(tolower(wheelofchoices[j][i]))-97;
        }
    }
}

for(int j=0;j<=4;j++){
    if(rotorchoice[1]==j){
        for(int i=0;i<=25;i++){
            wheel1[i][0]=i;
            wheel1[i][1]=(tolower(wheelofchoices[j][i]))-97;
        }
    }
}
for(int j=0;j<=4;j++){
    if(rotorchoice[2]==j){
        for(int i=0;i<=25;i++){
            wheel2[i][0]=i;
            wheel2[i][1]=(tolower(wheelofchoices[j][i]))-97;
        }
    }
}


outputletter=wheel0[outputletter][1];


outputletter=wheel1[outputletter][1];




outputletter=wheel2[outputletter][1];


int reflector[26][2];
char reflectorletters[]="YRUHQSLDPXNGOKMIEBFZCWVJAT";
for(int i=0;i<=25;i++){
        reflector[i][0]=i;
        reflector[i][1]=(tolower(reflectorletters[i]))-97;
    }

outputletter=reflector[outputletter][1];





for(int i=0;i<=25;i++){ 
    if(wheel2[i][1]==outputletter){
       outputletter=i;
       break;    
    }
}

for(int i=0;i<=25;i++){
    if(wheel1[i][1]==outputletter){
       outputletter=i;
       break;  
    }
}


for(int i=0;i<=25;i++){
    if(wheel0[i][1]==outputletter){
       outputletter=i; 
       break; 
    }
}
printf("outputletter before plugboard is %d\n",outputletter);
outputletter=plugboardarray[outputletter][1];
printf("outputletter after plugboard is %d\n",outputletter);
printarray(plugboardarray);
outputletter+=65;
char endletter=outputletter;
printf("the output letter is... %c",endletter);







//set it up so it will run again/take new letters and move the enigma mechanism forward 1 step
/*Each wheel has a single notch on its circumference. Whenever the wheel reaches the position of the notch, a pawl is engaged.
 This pawl then causes the next wheel (i.e. the wheel to the left of the current wheel) to make a single step.
  This movement is called Enigma stepping. The position of the notch is different on each wheel (see the wiring table below).
One of the disadvantages of having just one notch on each cipher wheel, is that wheel stepping will be very regular and 
can therefore more easily be predicted. Other machines, such as the Enigma G and the Tirpitz (Enigma T), featured multiple notches 
and had therefore an irregular (less predictable) wheel motion. Such machines lacked the additional Steckerbrett however.
*/


return 0;
}