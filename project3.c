#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


int main(int argc, char ** argv)
{
  int inputnum;
  int number;
  int nodeID;
  int userid;
  int age;
  int gender;
  int marital;
  int race;
  int birth;
  int language;
  int occupation;
  int income;
  int i;
  float delta1;
  float delta2;
  float alpha;
  //Generate mode
  if (argc != 2)
  {
    printf("\nNot valid option\n");
    return EXIT_FAILURE;
  }
  

  
  if (argc == 2)
  {
    printf("Openning Source File: %s\n\n",argv[1]);
    FILE * fptr = fopen(argv[1],"r");
    if (fptr == NULL)
      return EXIT_FAILURE;
    inputnum = fscanf(fptr ,"%d, %f, %f, %d, %f", &number, &delta1, &delta2, &nodeID, &alpha);
    printf("results: %d, %f, %f, %d, %f\n", number, delta1, delta2, nodeID, alpha);
    inputnum = 10;
    for(i = 0; i < number; i++){
      inputnum = fscanf(fptr,"%d, %d, %d, %d, %d, %d, %d, %d, %d", &userid, &age, &gender, &marital, &race, &birth, &language, &occupation, &income);
      printf("input: %d, %d, %d, %d, %d, %d, %d, %d, %d\n", userid, age, gender, marital, race, birth, language, occupation, income);
  }

  }
  return 0 ;
}
