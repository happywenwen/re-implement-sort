#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void main()
{
 FILE *fin,*fout;
 fin=fopen("name.txt","rt");
 fout=fopen("score.txt","w+t");
 typedef struct {
    char name[100];
    unsigned score;} person_t;
 person_t student[10];

 srand(time(NULL));
 
 for (int i = 0; i < 10; i++)
 {
    fscanf(fin,"%s",student[i].name);
    student[i].score=(rand() % 100) +1;
 }
 for (int i = 0; i < 10; i++)
 {   
   fprintf(fout,"%s %d\n",student[i].name,student[i].score);
   printf("%s ",student[i].name);
   printf("%d\n",student[i].score);
 }
 
 fclose(fin);
 fclose(fout);
}