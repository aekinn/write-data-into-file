#include <stdio.h>
#include <errno.h>
#include <string.h>
int main(){

char name[20], surname[20];
double grades[3];
int count, i,j;

FILE *note;
note = fopen("grade.txt","w");

if(!note){
    fprintf ( stderr, "Error opening file: %s\n", strerror(errno) );
    exit(1);
}else{
printf("How many students do you want to list: ");
scanf("%d",&count);

i=1;
while(1){
    printf("\n%d)\nName of the student?: ",i);
    scanf("%s",&name);

    printf("Surname of the student?: ",i);
    scanf("%s",&surname);

    for(j=0; j<=2; j++){
    printf("%d. Grade: ",j+1);
    scanf("%lf",&grades[j]);
    }

    fprintf(note,"%d %s %s %.1lf %.1lf %.1lf\n", i, name, surname, grades[0], grades[1], grades[2]);
    if(count==i){
        break;
    }
    i++;
}
}
fclose(note);
return 0;
}
