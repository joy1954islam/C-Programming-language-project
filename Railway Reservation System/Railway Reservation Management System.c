#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y);
void admin();
void add_data();
void edit_data();
void delete_data();
void view_data();
void customer();
void customer_menu();
void sing();
void registation();
void current_month();
void previous_month();
void payment();
void booking();
void history();
void search_data();
void train_number_edit();
void train_name_edit();
void train_from_edit();
void train_date_edit();
void train_to_edit();
void train_time_edit();
void train_class_edit();
void train_seat_edit();
void train_price_edit();
void train_all_edit();

struct {
    char name[50];
    char password[50];
    char id[100];
}student;

struct {
    char number[20];
    char from[50];
    char to[50];
    char date[15];
    char time[20];
    char tclass[30];
    char name[100];
    int seat;
    int price;
}t;
FILE *fp;
FILE *fp1;
FILE *fp2;
int main()
{
    system("color A");
    printf("\n\n\t\t\t\t*************************************************\n");
    printf("\t\t\t\tWELCOME TO TRAIN RESERVATION MANAGEMENT SYSTEM\n");
    printf("\t\t\t\t*************************************************");
    int choice;
    printf("\n\n\n\t\t\t\t\t 1 Admin.");
    printf("\n\t\t\t\t\t 2 Customer.");
    printf("\n\t\t\t\t\t 3 Exit.");
    printf("\n\n");
    printf("\n\t\t\t\t\t Enter Your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            admin();
            break;
        case 2:
            customer();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\n\n\t\t\t\tWrong choice !\n\n");
            break;
       }
      return 0;
}
void admin()
{
    system("cls");
    int c;
    char str[5]="1234";
    char str1[5];
    int choice;
    char pas[30];
    char chr;
    printf("\n\n\n\t\t\t\tenter your password: ");
    scanf("%s",str1);
    c=strcmp(str1,str);
    while(1){
    if(c==0){
        printf("\n\t\t\t\t\t ===================.");
        printf("\n\t\t\t\t\t  Admin Menu.");
        printf("\n\t\t\t\t\t ===================.\n");
        printf("\t\t\t\t\t\t[1] Add Train Record\n");
        printf("\t\t\t\t\t\t[2] Edit Train Record \n");
        printf("\t\t\t\t\t\t[3] Delete Train Record\n");
        printf("\t\t\t\t\t\t[4] View All Train Record\n");
        printf("\t\t\t\t\t\t[5] Search Train Record\n");
        printf("\t\t\t\t\t\t[6] Exit\n");
        printf("\t\t\t\t\t\t[7] Go to back Main Menu\n");
        printf("\n\n\n\t\t\t\t\t\tEnter your choice  :  ");
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
            case 7:
                main();
            default:
                printf("\n\n\t\t\t\tWrong choice !\n\n");
                break;
        }
    }
  }
}
void add_data()
{
    system("cls");
    char number[10];
    char r[10];
    gets(r);
    fp=fopen("train.txt","a+");
    {
        gotoxy(41,12);
        printf("Train  Number: ");
        gets(t.number);
        gotoxy(41,13);
        printf("Train Name : ");
        scanf("%s",t.name);
        gotoxy(41,14);
        printf("Train Station From : ");
        scanf("%s",&t.from);
        gotoxy(41,15);
        printf("Journey Date : ");
        scanf("%s",t.date);
        gotoxy(41,16);
        printf("Train Station To: ");
        scanf("%s",&t.to);
        gotoxy(41,17);
        printf("Departure Time: ");
        scanf("%s",t.time);
        gotoxy(41,18);
        printf("Seat class : ");
        scanf("%s",t.tclass);
        gotoxy(41,19);
        printf("Seat available : ");
        scanf("%d",&t.seat);
        gotoxy(41,20);
        printf("Seat price : ");
        scanf("%d",&t.price);
        gotoxy(41,21);
        fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        gotoxy(41,22);
        printf("Record insert successful");
    }
    fclose(fp);
}

void delete_data()
{
     system("cls");
     fp = fopen("train.txt","r");
     fp1 = fopen("temp.txt","a");
     char number[100];
     char date[20];
     int f=0;
     printf("\n\n\n\t\t\t\tenter your train number you want to Delete :  ");
     scanf("%s",&number);
     while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
     {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\n\n\t\t\t\tDelete successfull\n\n");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }
     }
     if(f==0)
     {
            printf("\n\n\t\t\tMeter number not found");
     }
     fclose(fp);
     fclose(fp1);
     fp = fopen("train.txt","w");
     fclose(fp);
     fp = fopen("train.txt","a");
     fp1 = fopen("temp.txt","r");
     while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
     {
        fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
     }
     fclose(fp);
     fclose(fp1);
     fp = fopen("temp.txt","w");
     fclose(fp);
}
void view_data()
{
    system("cls");
    fp=fopen("train.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    fp=fopen("train.txt","r");
    {
        printf("\n\n\n\t\ttrain number   Train Name     From         Date             To            Time         Class       Seat      Price\n");
        while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
        {
            printf("\n\t\t%s               %s         %s        %s         %s      %s         %s          %d       %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }
    }
    fclose(fp);
}
void search_data()
{
    system("cls");
    char number[100];
    fp = fopen("train.txt","r");
    printf("\n\n\n\t\t\t\tenter your Train number  :  ");
    scanf("%s",number);
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    {
    fp=fopen("train.txt","r");
    {
        while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
        {
           if(strcmp(t.number,number)==0)
           {
               printf("\n\n\n\t\ttrain number   Train Name     From         Date             To            Time         Class       Seat      Price\n");
               printf("\n\t\t%s               %s         %s        %s         %s      %s         %s          %d       %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
           }
        }
    }
    }
    fclose(fp);
}
void edit_data()
{
    system("cls");
    int choice;
    fp = fopen("train.txt","r");
    fp1 = fopen("temp.txt","a");
    printf("\n\n\t\t\twhat would you like to edit?");
    printf("\n\n\t\t\t[1] Train Number ");
    printf("\n\t\t\t[2] Train Name ");
    printf("\n\t\t\t[3] Train From");
    printf("\n\t\t\t[4] Train Date");
    printf("\n\t\t\t[5] Train To");
    printf("\n\t\t\t[6] Train Time");
    printf("\n\t\t\t[7] Train Class Type");
    printf("\n\t\t\t[8] Train Seat");
    printf("\n\t\t\t[9] Train Seat Price");
    printf("\n\t\t\t[10] Train All Data Edit");
    printf("\n\n\t\t\t Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            train_number_edit();
            break;
        case 2:
            train_name_edit();
            break;
        case 3:
            train_from_edit();
            break;
        case 4:
            train_date_edit();
            break;
        case 5:
            train_to_edit();
            break;
        case 6:
            train_time_edit();
            break;
        case 7:
            train_class_edit();
            break;
        case 8:
            train_seat_edit();
            break;
        case 9:
            train_price_edit();
            break;
        case 10:
            train_all_edit();
            break;
        default:
            printf("\t\t\t\n\nwrong choice!please try again");
    }

}
void train_number_edit()
{
    char number[50];
    char present[15];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Train number :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Train Number :");
            scanf("%s",present);
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",present,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }

    }
    if(f==0)
    {
        printf("\n\n\t\t\tTrain number not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("train.txt","w");
    fclose(fp);
    fp = fopen("train.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void train_name_edit()
{
    char number[50];
    char present[15];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Train number :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Train Name :");
            scanf("%s",present);
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,present,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }

    }
    if(f==0)
    {
        printf("\n\n\t\t\tTrain number not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("train.txt","w");
    fclose(fp);
    fp = fopen("train.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void train_from_edit()
{
    char number[50];
    char present_from[15];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Train number :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Train From :");
            scanf("%s",present_from);
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,present_from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }
    }
    if(f==0)
    {
        printf("\n\n\t\t\tTrain number not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("train.txt","w");
    fclose(fp);
    fp = fopen("train.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
         fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void train_date_edit()
{
    char number[50];
    char present[15];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Train number :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Train Date :");
            scanf("%s",present);
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,present,t.to,t.time,t.tclass,t.seat,t.price);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }
    }
    if(f==0)
    {
        printf("\n\n\t\t\tTrain number not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("train.txt","w");
    fclose(fp);
    fp = fopen("train.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
         fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void train_to_edit()
{
    char number[50];
    char present_to[15];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Train number :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Train TO :");
            scanf("%s",present_to);
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,present_to,t.time,t.tclass,t.seat,t.price);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }
    }
    if(f==0)
    {
        printf("\n\n\t\t\tTrain number not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("train.txt","w");
    fclose(fp);
    fp = fopen("train.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
         fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void train_time_edit()
{
    char number[50];
    char present_time[15];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Train number :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Train Time :");
            scanf("%s",present_time);
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,present_time,t.tclass,t.seat,t.price);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }
    }
    if(f==0)
    {
        printf("\n\n\t\t\tTrain number not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("train.txt","w");
    fclose(fp);
    fp = fopen("train.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
         fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void train_class_edit()
{
    char number[50];
    char present_class[15];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Train number :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Train Class :");
            scanf("%s",present_class);
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,present_class,t.seat,t.price);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }
    }
    if(f==0)
    {
        printf("\n\n\t\t\tTrain number not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("train.txt","w");
    fclose(fp);
    fp = fopen("train.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
         fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void train_seat_edit()
{
    char number[50];
    int present_seat;
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Train number :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Train Seat :");
            scanf("%d",&present_seat);
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,present_seat,t.price);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }
    }
    if(f==0)
    {
        printf("\n\n\t\t\tTrain number not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("train.txt","w");
    fclose(fp);
    fp = fopen("train.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
         fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void train_price_edit()
{
    char number[50];
    int present_price;
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Train number :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Train Price :");
            scanf("%d",&present_price);
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,present_price);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }
    }
    if(f==0)
    {
        printf("\n\n\t\t\tTrain number not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("train.txt","w");
    fclose(fp);
    fp = fopen("train.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
         fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void train_all_edit()
{
    char number[50];
    char present_number[15];
    char present_name[15];
    char present_from[15];
    char present_date[15];
    char present_to[15];
    char present_time[15];
    char present_class[15];
    int present_seat;
    int present_price;
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Train number :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
        if(strcmp(t.number,number)==0)
        {
            f =1;
            printf("\n\t\t\t\tEnter The New Train  Number: ");
            scanf("%s",present_number);
            printf("\n\t\t\t\tEnter The New Train Name : ");
            scanf("%s",present_name);
            printf("\n\t\t\t\tEnter The New Train Station From : ");
            scanf("%s",&present_from);
            printf("\n\t\t\t\tEnter The New Journey Date : ");
            scanf("%s",present_date);
            printf("\n\t\t\t\tEnter The New Train Station To: ");
            scanf("%s",&present_to);
            printf("\n\t\t\t\tEnter The New Departure Time: ");
            scanf("%s",present_time);
            printf("\n\t\t\t\tEnter The New Seat class : ");
            scanf("%s",present_class);
            printf("\n\t\t\t\tEnter The New Seat available : ");
            scanf("%d",&present_seat);
            printf("\n\t\t\t\tEnter The New Seat price : ");
            scanf("%d",&present_price);
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",present_number,present_name,present_from,present_date,present_to,present_time,present_class,present_seat,present_price);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
        }
    }
    if(f==0)
    {
        printf("\n\n\t\t\tTrain number not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("train.txt","w");
    fclose(fp);
    fp = fopen("train.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
    {
         fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);


}
void customer()
{
    int choice;
    system("cls");
    while(1)
    {
        printf("\n\t\t\t =============================================");
        printf("\n\t\t\t\tWELCOME TO TRAIN RESERVATION MANAGEMENT SYSTEM");
        printf("\n\t\t\t =============================================");
        printf("\n\n\t\t\t\t\t1. Log in");
        printf("\n\t\t\t\t\t2. Registration");
        printf("\n\t\t\t\t\t3. Exit");
        printf("\n\t\t\t\t\t4. Go to back Main menu");
        printf("\n\n\n\t\t\t\t\tEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                sing();
                break;
            case 2:
                registation();
            case 3:
                exit(0);
                break;
            case 4:
                main();
            default:
                printf("\n\n\t\t\t\tWrong choice !\n\n");
                break;
        }
    }

}
void customer_menu()
{
    system("cls");
    int choice;
    while(1)
    {
        printf("\n\t\t\t =============================================");
        printf("\n\t\t\t  WELCOME TO TRAIN TICKET MANAGEMENT SYSTEM");
        printf("\n\t\t\t =============================================");
        printf("\n\t\t\t\t\t ===================.");
        printf("\n\t\t\t\t\t  Customer Menu.");
        printf("\n\t\t\t\t\t ===================.\n");
        printf("\n\n\t\t\t\t\t1. View Train List");
        printf("\n\t\t\t\t\t2. Searching Train ");
        printf("\n\t\t\t\t\t3. Booking Train Ticket");
        printf("\n\t\t\t\t\t4. Exit");
        printf("\n\t\t\t\t\t5. Go to back Main menu");
        printf("\n\n\n\t\t\t\t\tEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                view_data();
                break;
            case 2:
                search_data();
                break;
            case 3:
                booking();
                break;
            case 4:
                exit(0);
                break;
            case 5:
                main();
                break;
            default:
                printf("\n\n\t\t\t\tWrong choice !\n\n");
                break;
        }
    }
}
void booking()
{
    system("cls");
    char number[100];
    char name[20];
    fp = fopen("train.txt","r");
    fp1 = fopen("temp.txt","a");
    printf("\n\n\n\t\t\t\tenter your Train number  :  ");
    scanf("%s",number);
    int f=0;
    if(fp == NULL)
    {
            printf("file does not found !");
            exit(1);
    }
    else{
        fp=fopen("train.txt","r");
        {

            while(fscanf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
            {
                if(strcmp(t.number,number)==0)
                {
                   f=1;
                   printf("\n\n\n\t\ttrain number   Train Name     From         Date             To            Time         Class       Seat      Price\n");
                   printf("\n\t\t%s               %s         %s        %s         %s      %s         %s          %d       %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
                   int token,age,sum;
                   printf("\n\n\t\t\t\t You Have only 4 ticket and Enter your seat : ");
                   scanf("%d",&token);
                   if(token<=4)
                   {
                        sum = t.price * token;
                        printf("\n\t\t\t\tYour total price is : %d ",sum);
                        printf("\n\t\t\t\tEnter your name : ");
                        scanf("%s",name);
                        printf("\t\t\t\tEnter Your Age : ");
                        scanf("%d",&age);
                        t.seat = t.seat - token;
                        printf("\n\t\t\t\tTotal seat available is : %d",t.seat);
                        fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
                        printf("\n\t\t\t\t******************************\n");
                        printf("\n\t\t\t\t\tNOW YOUR TICKET IS");
                        printf("\n\t\t\t\t******************************\n\n");
                        printf("\n\t\t\t\tname : %s",name);
                        printf("\n\t\t\t\tAge : %d",age);
                        printf("\n\t\t\t\tFrom : %s",t.from);
                        printf("\n\t\t\t\tDate : %s",t.date);
                        printf("\n\t\t\t\tTo : %s",t.to);
                        printf("\n\t\t\t\tTime : %s",t.time);
                        printf("\n\t\t\t\tClass : %s",t.tclass);
                        printf("\n\t\t\t\tTicket price is : %d ",sum);
                        printf("\n\t\t\t\tTotal seat is : %d",token);
                        printf("\n\n\t\t\t\t\t\tTHANK YOU\n\n");
                        printf("\t\t\t\t******************************\n\n");


                   }
                    else{
                        printf("\n\n\t\t\t\tYou Have input not limited seat");
                    }
                }
                else{
                    fprintf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
                }
                 if(f==0)
                {
                    printf("\n\n\t\t\t Train number not found");
                }

                fclose(fp);
                fclose(fp1);
                fp = fopen("train.txt","w");
                fclose(fp);
                fp = fopen("train.txt","a");
                fp1 = fopen("temp.txt","r");
                while(fscanf(fp1,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,&t.seat,&t.price)!=EOF)
               // while(fscanf(fp1,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                {
                     //fprintf(fp,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                     fprintf(fp,"%s %s %s %s %s %s %s %d %d\n",t.number,t.name,t.from,t.date,t.to,t.time,t.tclass,t.seat,t.price);
                }
                fclose(fp);
                fclose(fp1);
                fp = fopen("temp.txt","w");
                fclose(fp);

            }
        }
    }
    fclose(fp);
}

void sing(){
    system("cls");
    char r[10];
    gets(r);
    int k=1,l=0,i=0,j;
    char password[30];
    char regname[30];
    char ch;
    gotoxy(41,17);
    printf("Enter User Name: ");
    gets(regname);
    fp=fopen("student.txt","r");
    {
        while(fscanf(fp,"%s %s",student.name,student.password)!=EOF)
        if(strcmp(student.name,regname)==0)
            {
                k=0;
                l=1;
                break;
            }
    }
    fclose(fp);
    if(l==1)
    {
        gotoxy(41,18);
        printf("Enter User Password: ");
        while(1)
        {
            ch=getch();
            if(i==15)
                break;
            if(ch==13)
            {
                password[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else if(ch==9 || ch==32)
            {
                continue;
            }
            else
            {
                password[i]=ch;
                i++;
                printf("*");
            }
        }
        FILE *fp;
        fp=fopen("student.txt","r");
        {
        while(fscanf(fp,"%s %s",student.name,student.password)!=EOF)
        {
            if(strcmp(student.password,password)==0)
            {
                gotoxy(41,19);
                gotoxy(41,20);
                printf("Log in Successfully\n\n");
                k=1;
                gotoxy(41,21);
                printf("Continue Enter any key:.........");
                getche();
                system("cls");
                customer_menu();
                break;
            }
        }
        }
    fclose(fp);
    }
    if(k==0)
    {
        gotoxy(41,20);
        printf("====================================\n");
        gotoxy(41,21);
        printf("%%%%%%%% The Password Did not Match %%%%%%%%\n");
        gotoxy(41,22);
        printf("====================================\n");
     }
     if(l==0)
     {
        gotoxy(41,20);
        printf("====================================\n");
        gotoxy(41,21);
        printf("%%%%%% The User Name Did not Match %%%%%%\n");
        gotoxy(41,22);
        printf("====================================\n");
     }
    gotoxy(41,24);
    printf(" Try Again ? (1 / 0): ");
    int na;
    scanf("%d",&na);
    system("cls");
    if(na==1)
    sing();

}
void registation()
{
     char r[100];
      gets(r);
      system("cls");

     fp=fopen("student.txt","a+");
     {
                gotoxy(41,10);
                printf("Enter Your Information For Registration\n");
                gotoxy(41,11);
                printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
                gotoxy(41,12);
                printf("User Name: ");
                gets(student.name);
                gotoxy(41,13);
                printf("Password: ");
                gets(student.password);
                fprintf(fp,"%s %s\n",student.name,student.password);
                gotoxy(41,18);
                printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
                gotoxy(41,19);
                printf("Complete Your Registration\n");
    }
    fclose(fp);
    gotoxy(41,20);
    printf("Continue Enter any key:..............");
    getche();
    customer_menu();

}
COORD coord={0,0};

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

