#include <stdio.h>
struct student
{
char name[30];
int roll_number;
int age;
float height;
};
void main(){
int x,i;
struct student students[i];
printf("Enter Student Detail\n");
for(i=0; i<10; i++)
{
x=65;
printf("Enter %c\n",x)
printf("Name:");
scanf("%[^\n]",students[i].name);
printf("Roll Number:");
scanf("%d",students[i].roll_number);
printf("Age:");
scanf("%d",students[i].age);
printf("Height:");
scanf("%f",students[i].height);
x++;
printf("\n");
}
}

