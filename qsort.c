#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpnum(const void *pa,const void *pb);
int cmpstr(const void *pa,const void *pb);

struct person_t{
char name[100];
unsigned score;
}student[10];

void main()
{
 FILE *fin;
 fin=fopen("score.txt","rt");

 for (int i = 0; i < 10; i++)
 {
     fscanf(fin,"%s%d",student[i].name,&student[i].score);
 }

 qsort(student,10,sizeof(struct person_t),cmpnum);
 printf("score(from low to high)\n");
 for (int i = 0; i < 10; i++)
 {
    printf("%s %d\n",student[i].name,student[i].score);
 }
 
 qsort(student,10,sizeof(struct person_t),cmpstr);
 printf("name(in dictionary order)\n");
 for (int i = 0; i < 10; i++)
 {
    printf("%s %d\n",student[i].name,student[i].score);
 }

 fclose(fin);
}

int cmpnum(const void *pa,const void *pb){
int la,lb,result;
struct person_t *a=(struct person_t *)pa;
struct person_t *b=(struct person_t *)pb;
la=a->score;
lb=b->score;
if(la < lb ){return -1;}
else{return 1;}
}

int cmpstr ( const void *pa , const void *pb )
{
    char la[100],lb[100],result;
    struct person_t *a=(struct person_t *)pa;
    struct person_t *b=(struct person_t *)pb;
    strcpy(la,a->name);
    strcpy(lb,b->name);
    return(strcmp(la,lb));
}



