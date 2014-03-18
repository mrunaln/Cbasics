#include <stdio.h>


int findifvowel (char thisChar);
int main(){
  int i=0,firstVowelIndex=-1,secondVowelIndex=-1;
  int isvowel= 0 ;
  char swapTemp;
  char str[50] = "helloworldicandothisa";
  printf("Given string is - %s", str);
  while (str[i] != '\0'){
    isvowel = findifvowel(str[i]);
    if(isvowel){
      printf(" \n\n vowel found = %c" , str[i]);
      if(firstVowelIndex == -1){
        printf("\n 1 vowel index in pair to swap = %d", i);
        firstVowelIndex = i;
      }else if (secondVowelIndex == -1 ){ /*means first vowel is found  but 2nd not found*/
          printf("\n 2 vowel index in pair to swap = %d", i );
          secondVowelIndex = i;
      } 
      if(firstVowelIndex != -1 && secondVowelIndex != -1 )
      { /*pair of vowels found */
        printf(" \n SWAP  %c =  on index = %d and %c = on index = %d ", str[firstVowelIndex], firstVowelIndex , str[secondVowelIndex], 
            secondVowelIndex );
        swapTemp = str[firstVowelIndex];
        str[firstVowelIndex] = str[secondVowelIndex];
        str[secondVowelIndex] = swapTemp ; 
        firstVowelIndex = -1;
        secondVowelIndex = -1;

      }
    }
    i++;
  }
  
  printf("\n \n VOWEL SWAPPED  STRING = %s \n\n", str);
  return 0;
}


int findifvowel (char thisChar){

  switch(thisChar) {
    case 'a' : return 1;
    case 'e' : return 1;
    case 'i' : return 1;
    case 'o' : return 1;
    case 'u' : return 1;
    default : return 0;
  
  
  }

  return 0;
}
