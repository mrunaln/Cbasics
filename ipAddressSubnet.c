/*

Given two IP addresses and one subnet mask as input (All are string data type),
write a function to determine whether the two IP addresses are in the same subnet

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenize(char toTokenize[], char delimiter[2], char tokenized[10][10]);
int main (){


  char ip1[] = "10011000.11010101.00001011.00000010";
  char ip2[] = "10011000.11010101.00001011.00000011";
  char ip1tokens[10][10], ip2tokens[10][10], subnetmasktokens[10][10];
  char subnetmask[] = "11111111.11111111.11111000.00000000";
  char *partial_ip, *partialSubnet;
  int ip1Num, ip2Num , subnetNum;
  char singleIpPart[10];
  char singleIpPart2[10] = "\0";
  char subnetInPart[10] = "\0";
  char delim[2] = ".";
  int i;

  printf ("\nip address 1= %s \t ip address 2 = %s \t subnet mask given = %s\n\n",ip1 ,ip2 ,subnetmask);
  tokenize(ip1, delim, ip1tokens);
  tokenize(ip2, delim,ip2tokens);
  tokenize(subnetmask, delim, subnetmasktokens);
  
  
  for(i=0;i<4;i++)
  {

      strcpy(singleIpPart, ip1tokens[i]);
      ip1Num = atoi(singleIpPart);
      
      strcpy(singleIpPart2, ip2tokens[i]);
      ip2Num = atoi(singleIpPart2);
      
      strcpy(subnetInPart, subnetmasktokens[i]);
      subnetNum = atoi(subnetInPart);

      //printf("ip1 = %d and subnet = %d \t = %d \n" ,ip1Num,subnetNum, (ip1Num&subnetNum));
      //printf("ip2 = %d and subnet = %d \t = %d \n" ,ip2Num,subnetNum, (ip2Num&subnetNum));

      if((ip1Num&subnetNum) != (ip2Num&subnetNum))
      { 
        printf(" IP addresses are in different subnet masks "); 
        break;
      }

  }

  if(i==4)
    printf("IP addresses given are in the SAME SUBNET\n");
  
  return 0;
}


void tokenize(char toTokenize[], char delimiter[2], char tokenized[10][10]) {
  int idx = 0;
  char *ptr;
  ptr = strtok(toTokenize, delimiter);
  strcpy(tokenized[idx++], ptr);
  while( ( ptr= strtok(NULL, delimiter)) != NULL) {
    strcpy(tokenized[idx++], ptr); 
  }
}
