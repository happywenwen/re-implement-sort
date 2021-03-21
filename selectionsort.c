#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person_t{
char name[100];
unsigned score;
}student[10];

int cmpnum(struct person_t *array);
int cmpstr(struct person_t *array);
void selectionsort(struct person_t *array,size_t __nel, size_t __width,int (*__compar)(struct person_t *));

void main()
{
 FILE *fin;
 fin=fopen("score.txt","rt");

 for (int i = 0; i < 10; i++)
 {
     fscanf(fin,"%s%d",student[i].name,&student[i].score);
 }

 selectionsort(student,10,sizeof(struct person_t),cmpnum);
 printf("score(from low to high)\n");
 for (int i = 0; i < 10; i++)
 {
    printf("%s %d\n",student[i].name,student[i].score);
 }

 selectionsort(student,10,sizeof(struct person_t),cmpstr);
 printf("name(in dictionary order)\n");
 for (int i = 0; i < 10; i++)
 {
    printf("%s %d\n",student[i].name,student[i].score);
 }
 
 fclose(fin);
}

int cmpnum(struct person_t *array)
{
  int n, c, d, position;
  struct person_t t;
  n=10;
  for (c = 0; c < (n - 1); c++) // finding minimum element (n-1) times
  {
    position = c;

    for (d = c + 1; d < n; d++)
    {
      if (student[position].score > student[d].score)
        position = d;
    }
    if (position != c)
    {
      strcpy(t.name,student[c].name);
      t.score=student[c].score;
      strcpy(student[c].name,student[position].name);
      student[c].score=student[position].score;
      strcpy(student[position].name,t.name);
      student[position].score=t.score;
    }
  }
   return 0;
}

int cmpstr(struct person_t *array)
{
  int n, c, d, position;
  struct person_t t;
  n=10;
  for (c = 0; c < (n - 1); c++) // finding minimum element (n-1) times
  {
    position = c;

    for (d = c + 1; d < n; d++)
    {
      if (strcmp(student[position].name,student[d].name)>0)
        position = d;
    }
    if (position != c)
    {
      strcpy(t.name,student[c].name);
      t.score=student[c].score;
      strcpy(student[c].name,student[position].name);
      student[c].score=student[position].score;
      strcpy(student[position].name,t.name);
      student[position].score=t.score;
    }
  }
}

void selectionsort(struct person_t *array,size_t __nel, size_t __width,int (*__compar)(struct person_t *))
{
   __compar(array);
}