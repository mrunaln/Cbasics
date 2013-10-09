#include<stdio.h>

/*Program to find if the str2 is substring in given string */

/*In-built library function strstr 
[ 
  A] if substring is null returns mainstring,
  B] if no substring found returns null, 
  C] else gives ptr to the first occurance of the substring 
]
  1. Brute force method complexity is O(n*m) 
  2. Microsoft - Try to get code with O(n) complexity 
  
*/
char * bruteForcestrstr(char *mainStr , char *subStr);
int main(){

	char *mainStr = "hhellhelloworld\0";
	char *subStr = "hello\0";
	subStr = bruteForcestrstr(mainStr, subStr);
	printf("%s , %s ", mainStr, subStr);

}

char * bruteForcestrstr(char *mainStr , char *subStr){

	if(!*subStr) return mainStr;	// case A 
	char *p1 = (char *) mainStr;
	while(*p1){
		char *p1Begin = (char *) p1;
		char *p2 = (char *) subStr;
		while(*p1 && *p2 && *p1 == *p2 ){
			printf("++\n");
			p1++;
			p2++;
		}
		if(!*p2){
			printf(" Found - returning  \n");
			return p1Begin;
		}
		p1 = p1Begin + 1;
		printf("next letter in mainstr\n");
	}
	printf("No substring - returning null \n");
	return NULL;
}




