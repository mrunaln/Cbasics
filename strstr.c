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
char * revisedBruteForcestr(char *mainStr , char *subStr);
int main(){

	char *mainStr = "hhellhelloworld\0";
	char *subStr = "hell\0";
	//subStr = bruteForcestrstr(mainStr, subStr);
	//printf("%s , %s ", mainStr, subStr);
	subStr = revisedBruteForcestr(mainStr, subStr);
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

/*
O(N-M+1) complexity
Will need one advancing ptr in mainStr which will point to \0 when the remaining chars in mainStr < len(subStr)
*/
char * revisedBruteForcestr(char * mainStr, char *subStr){


	if(!subStr) return mainStr;

	char *p1 = (char *) mainStr;
	char *p1Adv = (char *) mainStr;
	char *p2 = (char *) subStr;

	while(*p2){
		 p1Adv++;
		 p2++;
	}
	while(*p1Adv){
		char *p1Begin = (char *)p1;
	        p2 = (char *)subStr;
                while(*p1 && *p2 && *p1 == *p2){
			p1++;
			p2++;
		}
		if(!*p2) return p1Begin;
		p1 = p1Begin + 1;	
		p1Adv++;
	}
 	return NULL;	
}

