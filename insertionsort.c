#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person_t{
char name[100];
unsigned score;
}student[10];

int cmpnum(struct person_t *array);
int cmpstr(struct person_t *array);
void insertionsort(struct person_t *array,size_t __nel, size_t __width,int (*__compar)(struct person_t *));

void main()
{
 FILE *fin;
 fin=fopen("score.txt","rt");

 for (int i = 0; i < 10; i++)
 {
     fscanf(fin,"%s%d",student[i].name,&student[i].score);
 }

 insertionsort(student,10,sizeof(struct person_t),cmpnum);
 printf("score(from low to high)\n");
 for (int i = 0; i < 10; i++)
 {
    printf("%s %d\n",student[i].name,student[i].score);
 }

 insertionsort(student,10,sizeof(struct person_t),cmpstr);
 printf("name(in dictionary order)\n");
 for (int i = 0; i < 10; i++)
 {
    printf("%s %d\n",student[i].name,student[i].score);
 }
 
 fclose(fin);
}

int cmpnum(struct person_t *array)
{
  int n=10, c, d, flag = 0;
  struct person_t t;
  for (c = 1 ; c <= n - 1; c++) {
    strcpy(t.name,student[c].name);
    t.score=student[c].score;

    for (d = c - 1 ; d >= 0; d--) {
      if (student[d].score > t.score) {
        strcpy(student[d+1].name,student[d].name);
        student[d+1].score=student[d].score;
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      strcpy(student[d+1].name,t.name);
      student[d+1].score=t.score;
  }
  return 0;
}

int cmpstr(struct person_t *array)
{
  int n=10, c, d, flag = 0;
  struct person_t t;
  for (c = 1 ; c <= n - 1; c++) {
    strcpy(t.name,student[c].name);
    t.score=student[c].score;

    for (d = c - 1 ; d >= 0; d--) {
      if (strcmp(student[d].name,t.name)>0) {
        strcpy(student[d+1].name,student[d].name);
        student[d+1].score=student[d].score;
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      strcpy(student[d+1].name,t.name);
      student[d+1].score=t.score;
  }
  return 0;
}

void insertionsort(struct person_t *array,size_t __nel, size_t __width,int (*__compar)(struct person_t *))
{
   __compar(array);
}










    