#include<stdio.h>
#include<string.h>
struct student
{
    int height;
    int age;
    char Name[];
   
}stu1;

int main()
{
    struct student stu1={19,2};
    stu1.Name = "Tejas";
    // stu1.arry[] = {1,3,5,67,8,9,0};
    // stu1.height=1.72;

    printf("Student name is %s \n",stu1.Name);
    printf("Student height is %d \n",stu1.height);
    
    return 0;
}