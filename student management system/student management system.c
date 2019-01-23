#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int x,int y);
void add_data();
void edit_data();
void delete_data();
void view_data();
void search_data();
void first_name_edit();
void last_name_edit();
void course_edit();
void section_edit();
void all_data_edit();

struct {
    char first_name[50];
    char last_name[50];
    char course[100];
    char section[10];
}student;
FILE *fp,*fp1,*fp2;
int main()
{
    printf("\n\n\t\tWELCOME TO STUDENT MANAGEMENT SYSTEM");

    while(1){
     int choice;
     printf("\n =================== ");
     printf("\n  Main Menu.");
     printf("\n ===================.\n");
     printf("[1] Add Student Record\n");
     printf("[2] Edit Student Record \n");
     printf("[3] Delete Student Record\n");
     printf("[4] View All Student Record\n");
     printf("[5] Search Student Record\n");
     printf("[6] Exit\n");
     printf("\n\n\n\t\tEnter your choice  :  ");
     scanf("%d",&choice);

     switch(choice)
     {
        case 1:
            add_data();
            break;
        case 2:
            edit_data();
            break;
        case  3:
            delete_data();
            break;
        case 4:
            view_data();
            break;
        case 5:
            search_data();
            break;
        case 6:
            exit(0);
            break;

        default:
            printf("\n\n\t\t\t\tWrong choice !\n\n");
            break;

        }
    }
}
void add_data()
{
        system("cls");
        char r[10];
        char number[10];
        gets(r);
        fp=fopen("Student data save.txt","a+");
        {
            printf("\n\n\n\t\t\t\tEnter The First Name : ");
            scanf("%s",student.first_name);
            printf("\n\t\t\t\tEnter The Last Name : ");
            scanf("%s",&student.last_name);
            printf("\n\t\t\t\tEnter The Course : ");
            scanf("%s",student.course);
            printf("\n\t\t\t\tEnter The Section : ");
            scanf("%s",student.section);
            fprintf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
            printf("\n\n\t\t\t\tRecord insert successful");

        }

       fclose(fp);

}
void view_data()
{
    system("cls");
    fp=fopen("Student data save.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    fp=fopen("Student data save.txt","r");
    {
        printf("\n\n\n\t\tFirst Name              Last Name            Course             Section\n");
        printf("========================================================================================");
        while(fscanf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
        {
            printf("\n\nYour Full Name is : %s %s",student.first_name,student.last_name);
            printf("\nCourse : %s",student.course);
            printf("\nSection : %s",student.section);
        }
        printf("\n\n=========================================================================================");
    }
   fclose(fp);


}
void search_data()
{
    system("cls");
    char name[30];
    fp = fopen("Student data save.txt","r");
    printf("\n\n\n\t\t\t\tEnter Your First Name  :  ");
    scanf("%s",&name);
    if(fp == NULL)
    {
            printf("file does not found !");
            exit(1);
    }
    else{
        fp=fopen("Student data save.txt","r");
        {
            while(fscanf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
            {
                if(strcmp(student.first_name,name)==0)
                {
                    printf("\n\n\n\t\tFirst Name              Last Name            Course             Section\n");
                    printf("========================================================================================");
                    printf("\n\nYour Full Name is : %s %s",student.first_name,student.last_name);
                    printf("\nCourse : %s",student.course);
                    printf("\nSection : %s",student.section);

                    printf("\n\n=========================================================================================");
                }
           }
        }
    }
    fclose(fp);


}
void delete_data()
{
    system("cls");
     fp = fopen("Student data save.txt","r");
     fp1 = fopen("temp.txt","a");
     char name[100];
     int f=0;
     printf("\n\n\n\t\t\t\tEnter Your First Name You Want To Delete :  ");
     scanf("%s",&name);

     while(fscanf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
     {
            if(strcmp(student.first_name,name)==0)
            {
                    f =1;
                    printf("\n\n\n\t\t\t\tDelete successfull\n\n");
            }
            else
            {
                fprintf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
            }

     }
     if(f==0)
     {
            printf("\n\n\t\t\tname not found");
     }
     fclose(fp);
     fclose(fp1);
     fp = fopen("Student data save.txt","w");
     fclose(fp);
     fp = fopen("Student data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void edit_data()
{
    system("cls");
    int choice;
    fp = fopen("Student data save.txt","r");
    fp1 = fopen("temp.txt","a");
    printf("\n\n\t\t\twhat would you like to edit?");
    printf("\n\n\t\t\t[1] First Name Edit ");
    printf("\n\t\t\t[2] Last Name Edit ");
    printf("\n\t\t\t[3] Course Edit");
    printf("\n\t\t\t[4] Section Edit");
    printf("\n\t\t\t[5] All Data Edit");
    printf("\n\n\t\t\t Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
         case 1:
             first_name_edit();
             break;
         case 2:
            last_name_edit();
            break;
         case 3:
            course_edit();
            break;
         case 4:
             section_edit();
             break;
         case 5:
            all_data_edit();
            break;
         default:
            printf("\n\n\t\t\t\tWrong choice !\n\n");
            break;

    }

}
void first_name_edit()
{
    system("cls");
    char name[20];
    char present_first_name[20];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter Your First Name :  ");
    scanf("%s",name);
    while(fscanf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        if(strcmp(student.first_name,name)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New First Name :");
            scanf("%s",present_first_name);
            fprintf(fp1,"%s %s %s %s\n",present_first_name,student.last_name,student.course,student.section);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
        }

    }
    if(f==0)
    {
            printf("\n\n\t\t\t First Name not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("Student data save.txt","w");
    fclose(fp);
    fp = fopen("Student data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void last_name_edit()
{
    system("cls");
    char name[20];
    char present_last_name[20];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter Your Last Name :  ");
    scanf("%s",name);
    while(fscanf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        if(strcmp(student.last_name,name)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New First Name :");
            scanf("%s",present_last_name);
            fprintf(fp1,"%s %s %s %s\n",student.first_name,present_last_name,student.course,student.section);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
        }

    }
    if(f==0)
    {
            printf("\n\n\t\t\t Last Name not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("Student data save.txt","w");
    fclose(fp);
    fp = fopen("Student data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);


}
void course_edit()
{
    system("cls");
    char name[20];
    char present_course_name[20];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter Your First Name :  ");
    scanf("%s",name);
    while(fscanf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        if(strcmp(student.first_name,name)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Course Name :");
            scanf("%s",present_course_name);
            fprintf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,present_course_name,student.section);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
        }

    }
    if(f==0)
    {
            printf("\n\n\t\t\t First Name not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("Student data save.txt","w");
    fclose(fp);
    fp = fopen("Student data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);


}
void section_edit()
{
    system("cls");
    char name[20];
    char present_section_name[20];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter Your First Name :  ");
    scanf("%s",name);
    while(fscanf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        if(strcmp(student.first_name,name)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Section Name :");
            scanf("%s",present_section_name);
            fprintf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,present_section_name);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
        }

    }
    if(f==0)
    {
            printf("\n\n\t\t\t First Name not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("Student data save.txt","w");
    fclose(fp);
    fp = fopen("Student data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);


}
void all_data_edit()
{
    system("cls");
    char name[20];
    char present_first_name[20];
    char present_last_name[20];
    char present_course_name[20];
    char present_section_name[20];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter Your First Name :  ");
    scanf("%s",name);
    while(fscanf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        if(strcmp(student.first_name,name)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New First Name :");
            scanf("%s",present_first_name);
            printf("\n\n\t\t\tEnter The New Last Name :");
            scanf("%s",present_last_name);
            printf("\n\n\t\t\tEnter The New course Name :");
            scanf("%s",present_course_name);
            printf("\n\n\t\t\tEnter The New section Name :");
            scanf("%s",present_section_name);
            fprintf(fp1,"%s %s %s %s\n",present_first_name,present_last_name,present_course_name,present_section_name);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
        }

    }
    if(f==0)
    {
            printf("\n\n\t\t\t First Name not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("Student data save.txt","w");
    fclose(fp);
    fp = fopen("Student data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",student.first_name,student.last_name,student.course,student.section);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);


}
COORD coord={0,0};

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
