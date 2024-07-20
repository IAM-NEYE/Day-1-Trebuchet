#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main(){
  int sum=0;
  FILE* trebuchet;
  trebuchet = fopen("calibration_document.txt","r");
  if(trebuchet==NULL){
    printf("failed to open the file.");
  }else{
    printf("the file is opened.\n");
  }
  char str[]="";
  char a, b; // Declare a and b outside the loops
  while(fgets(str,100,trebuchet)!=NULL)
    {
      for(int i=0;str[i]!='\0';i++){
        if(isdigit(str[i])){
          a = str[i];
        }
      }
      for(int i=strlen(str)-1; i>=0; i--){ // Corrected loop to go backwards 
        if(isdigit(str[i])){
          b=str[i];
        }
      }
      int value = atoi(strcat(a,b));
      printf("First digit: %c, Second digit: %c, Value: %d\n", a, b, value); // Print a, b, and value for debugging
    }
  printf("sum of all of the calibration values is %d",sum);
}