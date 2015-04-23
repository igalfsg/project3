#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


typedef struct pers {
  int id;
  int age;
  int gender;
  int marital;
  int race;
  int birth;
  int language;
  int occupation;
  int income;
}person;

double  getuab ( person a, person b)
{
  if (a.id ==  b.id)
    return -25;
  int age_dif = pow(a.age - b.age, 2);
  int gender_dif = pow(a.gender - b.gender, 2);
  int marital_dif = pow(a.marital - b.marital, 2);
  int race_dif = pow(a.race - b.race, 2);
  int birth_dif = pow(a.birth - b.birth, 2);
  int language_dif = pow(a.language - b.language, 2);
  int occupation_dif = pow(a.occupation - b.occupation, 2);
  int income_dif = pow(a.income - b.income , 2);
  double result = sqrt(age_dif + gender_dif + marital_dif + race_dif + birth_dif + language_dif + occupation_dif + income_dif);
  return result;
}




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
  int j;
  double max = 0;
  double temp;
  float delta1;
  float delta2;
  float alpha;
  person * arr;
  int ** matrix;
  //Generate mode
  if (argc != 2)
  {
    printf("\nNot valid option\n");
    return EXIT_FAILURE;
  }
  

  
  
    printf("Openning Source File: %s\n\n",argv[1]);
    FILE * fptr = fopen(argv[1],"r");
    if (fptr == NULL)
      return EXIT_FAILURE;
    inputnum = fscanf(fptr ,"%d,%f,%f,%d,%f", &number, &delta1, &delta2, &nodeID, &alpha);
    printf("results: %d, %f, %f, %d, %f\n", number, delta1, delta2, nodeID, alpha);
    arr = malloc(sizeof(person)*number);
    inputnum = 10;
    for(i = 0; i < number; i++){
      inputnum = fscanf(fptr,"%d,%d,%d,%d,%d,%d,%d,%d,%d", &userid, &age, &gender, &marital, &race, &birth, &language, &occupation, &income);
      arr[i].id = userid;
      arr[i].age = age;
      arr[i].gender = gender;
      arr[i].marital = marital;
      arr[i].race = race;
      arr[i].birth = birth;
      arr[i].language = language;
      arr[i].occupation = occupation;
      arr[i].income = income;
      printf("input: %d, %d, %d, %d, %d, %d, %d, %d, %d\n", userid, age, gender, marital, race, birth, language, occupation, income);
  }
    matrix = malloc(number * sizeof(int*));
     for(i = 0; i < number; i++){
       matrix[i] = malloc(number *sizeof(int));
     }
     for(j = 0; j < number; j++)
       {
	 for(i = 0 ; i < number; i++)
	   {
	     temp = getuab(arr[i], arr[j]);
	     if(temp > max){
	       max = temp;
	     }
	   }
       }
       for(j = 0; j < number; j++)
       {
	 for(i = 0 ; i < number; i++)
	   {
	     if (i != j)
	       matrix[j][i] =(int)((1-( getuab(arr[i], arr[j]) / max)) * 100);
	     else
	       matrix[j][i] = -25;
	   }
       }
     for(j = 0; j < number; j++)
       {
	 printf("\n row %d: ", j+1 );
	 for(i = 0 ; i < number; i++)
	   {
	     printf("%d, ", matrix[j][i]);
	   }
       }
     printf("\nfuck you mike!\n");
  return 0 ;
}
