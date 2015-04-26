#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

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
  //printf(" nodes %d ,%d = %f\n", a.id, b.id, result);
  return result;
}

void query1 (int ** matrix, int id, int number, int delta)
{
  int min  =2000;
  int i;
     //nodeid -1 = index
     for(i =  0; i < number; i++)
       {
	 if (min > matrix[id-1][i] && matrix[id-1][i] > delta){
	   min  = matrix[id-1][i];
	 }
       }
     printf("\n0.%d",min);
     for(i =  0; i < number; i++)
       {
	 if (min == matrix[id-1][i]){
	   printf(",%d", i+1);
	 }
       }
          printf("\n");
}
void query2 (int ** matrix, int id, int number, int delta, int alpha, int * nodes)
{
  int row;
  if (alpha < delta){return;}
  for (row = 0; row < number; row++)
    {
      if(matrix[id - 1][row] > delta && matrix[id-1][row] < alpha && nodes[row] != -21 && row != id-1){
	nodes[row] = 1;
	query2(matrix, row+1, number, delta, alpha - matrix[id-1][row], nodes);
      }

    }
  

}
void print_nodes (int * nodes, int number)
{
  int counter = 0;
  int i;
  for(i = 0; i<number; i++)
    {
      if (nodes[i] == 1)
	counter++;
    }
  printf("%d\n",counter);
}
void query3 (int ** matrix, int id, int number, int delta)
{
  int g = 0;
  int i;
  int things[number-1];
     for(i =  0; i < number; i++)
       {
	 if (matrix[id-1][i] > delta){
	   things[g] = i + 1;
	   g++;
	 }
       }
     printf("%d",g);
     for(i = 0; i < g; i++)
       {
	 printf(",%d",things[i]);
       }
     printf("\n");
}

void query4  (int ** matrix, int id, int number, int delta)
{
  bool nodes[number];
  int i;
  int j;
  int g = 0;

  for(i =  0; i < number; i++)
    {
      nodes[i] = 0;
    }
   for(i =  0; i < number; i++)
       {
	 if (matrix[id-1][i] > delta){
	   for (j= 0; j < number; j++)
	     {
	       if(j != id-1){
		 if (matrix[i][j]>delta){
		   if (nodes[j]!=1)
		   g++;
		   nodes[j] = 1;
		 }
	       }
	     }
	 }
       }
   printf("%d",g);
 
   for(i = 0; i < number; i++)
     {
       if(nodes[i] == 1 && i != id+1)
	 printf(",%d",i+1);
     }
   printf("\n");
}
void query5  (int ** matrix, int number, int delta){
  int column;
  int row;
  double count;
  for(row = 0; row < number; row++){
    for(column = 0; column < number; column++){
       if (matrix[row][column] > delta){
	 count++;
       }
    }
  }
  count = count / number;
  row =  (int)(count * 100);
  count = row / 100;
  printf("%.2f\n",count);
  
}
void query6  (int ** matrix, int number, int delta){
  bool nodes[number];
  int i;
  int j;
  double g = 0;
  int row;
  for(i =  0; i < number; i++)
    {
      nodes[i] = 0;
    }
  for(row = 0; row < number; row++)
    {
      for(i =  0; i < number; i++)
	{
	  if (matrix[row][i] > delta){
	    for (j= 0; j < number; j++)
	      {
		if(j != row)
		  {
		    if (matrix[i][j]>delta)
		      {
			if (nodes[j]!=row)
			  g++;
			nodes[j] = row;
		      }
		  }
	      }
	  }
	}
    }
  g = g / number;
  row =  (int)(g * 100);
  g = row / 100;
  printf("%.2f\n",g);
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
	   matrix[j][j] = -25;
	 for(i = j+1 ; i < number; i++)
	   {
	   
	       matrix[i][j] =(int)((1-( getuab(arr[i], arr[j]) / max)) * 100);
	       matrix[j][i] =(int)((1-( getuab(arr[i], arr[j]) / max)) * 100);
	   
	     
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
     free(arr);
     // query 1 /////////////////////////////////////////////////////
     query1 (matrix, nodeID, number, (int)(delta1* 100));
     int * nodes = malloc(number * sizeof(int));
     for(race = 0; race < number; race++){
       nodes[race]=0;
     }
     nodes[nodeID-1] = -21;
     query2 (matrix, nodeID, number, (int)(delta1* 100),(int)(alpha* 100),  nodes);
     print_nodes(nodes, number);
     free(nodes);
     query3 (matrix, nodeID, number, (int)(delta1* 100));
     query4 (matrix, nodeID, number, (int)(delta1* 100));
     query5 (matrix, number, (int)(delta1* 100));
     query6 (matrix, number, (int)(delta1* 100));
 
      for(i = 0; i < number; i++){
	free(matrix[i]);
     }
      free (matrix);
  return 0 ;
}
