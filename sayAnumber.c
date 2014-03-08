/*
write a function that takes in an int and returns a string that would be how one would say that number 
(example : 123 -> one hundred twenty three; 50019 -> five thousand nineteen)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

char outputstr[10][10];
int getplacevalueinwords(int digits,int tens , int index);
int getname(int digit,int index);
int main(){

  int num = 1234, len, i=0,strlen;
  char buffer[10];
  double digit ; 

  int index;
  int value = 234452;
  index = 0;
  sprintf(buffer,"%d", value);
  printf("%s\n",buffer);

  len = 0;
  printf("length = %d\n", len);
  while (buffer[i]){
        len += 1;
            i++;
  }
  strlen = len;
  len--;
  for(i=0 ; i < strlen ; i++){
        
        digit = value/pow(10,len);
        if (len != 1)
        {
          index=getname(digit,index);
          printf("%s\t", outputstr[index]);
        }
        index=getplacevalueinwords(digit, pow(10,len),index);
        if (i != (strlen-1))
          printf("%s\t", outputstr[index]);

        value = value - ((int)digit * pow(10,len));
        len--;

  }

  printf("\n Said it loud !\n");  
  return 0;
}
int getplacevalueinwords(int digit, int tens , int index){
  switch(tens){
    case 1 : break;
    case 10: 

            switch(digit){
              case 2: 
              
              strcpy(outputstr[index],"twenty");
              break; 
              case 3: 
              
              strcpy(outputstr[index],"thirty");
              break; 
              case 4: 
              
              strcpy(outputstr[index],"forty");
              break; 
              case 5: 
              
              strcpy(outputstr[index],"fifty");
              break; 
              case 6: 
              
              strcpy(outputstr[index],"sixty");
              break; 
              case 7: 
              
              strcpy(outputstr[index],"seventy");
              break; 
              case 8: 
              
              strcpy(outputstr[index],"eighty");
              break; 
              case 9: 
              
              strcpy(outputstr[index],"ninty");
              break; 
            }
            break;
    case 100: strcpy(outputstr[index], "hundred");
            break;
    case 1000: strcpy(outputstr[index], "thousand");
            break;
    case 10000: strcpy(outputstr[index], "tenthousand");
            break;
    case 100000: strcpy(outputstr[index], "million");
            break;

      return index++;
  }

}
int getname(int digit, int index){

  switch(digit)
  {
    case 1: strcpy(outputstr[index], "One");
            break;
    case 2: strcpy(outputstr[index] , "two");
            break;
    case 3: strcpy(outputstr[index],"three");
            break;
    case 4: strcpy(outputstr[index] , "four");
            break;
    case 5: strcpy(outputstr[index],"five");
            break;
    case 6: strcpy(outputstr[index], "six");
            break;
    case 7: strcpy(outputstr[index], "seven");
            break;
    case 8: strcpy(outputstr[index] ,"eight");
            break;
    case 9: strcpy(outputstr[index], "nine");
            break;
  }
    
    return index++;
}
