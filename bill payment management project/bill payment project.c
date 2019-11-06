#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int x,int y);
int admin();
int add();
int edit();
int delete();
int view();
int customer();
int singin();
int registation();
int current_month();
int previous_month();
int payment();
int history();
struct {
    char name[50];
    char password[50];
    char id[100];
}student;

struct {
    char number[50];
    int  present;
    int previous;
    char time[20];
}t;
FILE *fp;
FILE *fp1;
FILE *fp2;
int main()
{
     system("color 4e");
    printf("\n\n          \t\t\t\t ***************\n");
    printf("            \t\t\t\t *  WELCOME TO *\n");
    printf("            \t\t\t\t * ELECTRICITY *\n");
    printf("            \t\t\t\t *    BILL     *\n");
    printf("            \t\t\t\t *  MANAGEMENT *\n");
    printf("            \t\t\t\t *    SYSTEM   *\n");
    printf("            \t\t\t\t ***************");

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
int admin()
{
     system("cls");

        int c;

       char str[5]="1234";
       char str1[5];
       int choice;
            int d=1,e=0,q=0;
            char pas[30];
            char chr;
       printf("\n\n\n\t\t\t\tenter your password: ");
       scanf("%s",str1);
       c=strcmp(str1,str);
       /*if(c==1)
        {
              gotoxy(41,18);
            printf("Enter User Password: ");

            while(1)
            {
                 chr=getch();
                if(e==15)
                    break;
                if(chr==13)
                {
                    pas[e]='\0';
                    break;
                }
                else if(chr==8)
                {
                    if(e>0)
                    {
                        e--;
                        printf("\b \b");
                    }
                }
                else if(chr==9 || chr==32)
                {
                    continue;
                }
                else
                {
                    pas[e]=chr;
                    e++;
                    printf("*");
                }
            }*/


       while(1){
       if(c==0){
               printf("\n\t\t\t\t\t ===================.");
               printf("\n\t\t\t\t\t  Admin Menu.");
               printf("\n\t\t\t\t\t ===================.\n");
               printf("\t\t\t\t\t\t[1] Add Record\n");
               printf("\t\t\t\t\t\t[2] Edit Record \n");
               printf("\t\t\t\t\t\t[3] Delete Record\n");
               printf("\t\t\t\t\t\t[4] View All Record\n");
               printf("\t\t\t\t\t\t[5] Exit\n");
               printf("\t\t\t\t\t\t[6] Go to back Main Menu\n");


               printf("\n\n\n\t\t\t\t\t\tEnter your choice  :  ");
               scanf("%d",&choice);

               switch(choice)
               {
                         case 1:
                                 add();
                                 break;
                         case 2:
                                  edit();
                                  break;
                         case  3:
                            delete();
                            break;
                         case 4:
                            view();
                            break;
                         case 5:
                             exit(0);
                            break;
                         case 6:
                            main();

                        default:
                        printf("\n\n\t\t\t\tWrong choice !\n\n");
                        break;

               }


       }
       }


}
int add()
{

        system("cls");
        char r[10];
        gets(r);
        fp=fopen("bill.txt","a+");
        {
                    gotoxy(41,12);
                    printf("Meter  Number: ");
                    gets(t.number);
                    gotoxy(41,13);
                    printf("Present Bill Amount: ");
                    scanf("%d",&t.present);
                    gotoxy(41,14);
                    printf("previous Bill Amount: ");
                    scanf("%d",&t.previous);
                    gotoxy(41,15);
                    printf("Last Date of Payment : ");
                    scanf("%s",t.time);
                    gotoxy(41,16);
                    fprintf(fp,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                    gotoxy(41,17);
                    printf("Record insert successful");

        }
       fclose(fp);


}
int edit()
{
                        system("cls");
                        int choice;
                        char number[50];
                        int present;
                        int f=0;
                         fp = fopen("bill.txt","r");
                         fp1 = fopen("temp.txt","a");
                        printf("\n\n\t\t\twhat would you like to edit?");
                        printf("\n\n\t\t\t[1] Present Bill Amount");
                        printf("\n\t\t\t[2] Previous Bill Amount");
                        printf("\n\t\t\t[3] Last Date of Payment");

                        printf("'\n\n\t\t\t Enter your choice : ");
                        scanf("%d",&choice);
                        if(choice == 1)
                        {
                            printf("\n\n\n\t\t\t\t Enter your Meter number :  ");
                            scanf("%s",number);


                                    while( fscanf(fp,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                    {
                                                if(strcmp(t.number,number)==0)
                                                {
                                                        f =1;
                                                        printf("\n\n\t\t\tenter new present bill amount :");
                                                        scanf("%d",&present);
                                                        fprintf(fp1,"%s %d %d %s\n",t.number,present,t.previous,t.time);
                                                        printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
                                                }
                                                else{
                                                       fprintf(fp1,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                                    }

                                    }
                                    if(f==0)
                                    {
                                        printf("\n\n\t\t\tMeter number not found");
                                    }
                                     fclose(fp);
                                     fclose(fp1);
                                     fp = fopen("bill.txt","w");
                                     fclose(fp);
                                     fp = fopen("bill.txt","a");
                                      fp1 = fopen("temp.txt","r");

                                      while(fscanf(fp1,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                      {
                                          fprintf(fp,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                      }
                                      fclose(fp);
                                      fclose(fp1);
                                      fp = fopen("temp.txt","w");
                                      fclose(fp);
                        }
                        if(choice ==2)
                        {
                            int present;
                            printf("\n\n\n\t\t\t\tenter your Meter number :  ");
                            scanf("%s",number);
                                    while( fscanf(fp,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                    {
                                                if(strcmp(t.number,number)==0)
                                                {
                                                        f =1;
                                                        printf("\n\n\t\t\tenter new previous bill amount :");
                                                        scanf("%d",&present);
                                                        fprintf(fp1,"%s %d %d %s\n",t.number,t.present,present,t.time);
                                                        printf("\n\n\n\t\t\t\tsuccees update\n\n ");
                                                }
                                                else{
                                                       fprintf(fp1,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                                    }

                                    }
                                    if(f==0)
                                    {
                                        printf("\n\n\t\t\tMeter number not found");
                                    }
                                     fclose(fp);
                                     fclose(fp1);
                                     fp = fopen("bill.txt","w");
                                     fclose(fp);
                                      fp = fopen("bill.txt","a");
                                      fp1 = fopen("temp.txt","r");

                                      while(fscanf(fp1,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                      {
                                          fprintf(fp,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                      }
                                      fclose(fp);
                                      fclose(fp1);
                                      fp = fopen("temp.txt","w");
                                      fclose(fp);

                         }
                        if(choice ==3)
                        {
                            char date[20];
                            printf("\n\n\n\t\t\t\tenter your Meter number :  ");
                            scanf("%s", &number);

                              while( fscanf(fp,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                    {
                                                if(strcmp(t.number,number)==0)
                                                {
                                                        f =1;
                                                        printf("\n\n\t\t\tenter new Date :");
                                                        scanf("%s",date);
                                                        fprintf(fp1,"%s %d %d %s\n",t.number,t.present,t.previous,date);
                                                        printf("\n\n\n\t\t\t\tsuccees update \n\n");
                                                }
                                                else{
                                                       fprintf(fp1,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                                    }

                                    }
                                    if(f==0)
                                    {
                                        printf("\n\n\t\t\tMeter number not found");
                                    }
                                     fclose(fp);
                                     fclose(fp1);
                                     fp = fopen("bill.txt","w");
                                     fclose(fp);
                                      fp = fopen("bill.txt","a");
                                      fp1 = fopen("temp.txt","r");

                                      while(fscanf(fp1,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                      {
                                          fprintf(fp,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                      }
                                      fclose(fp);
                                      fclose(fp1);
                                      fp = fopen("temp.txt","w");
                                      fclose(fp);

                        }

}
int delete()
{
    system("cls");
                            fp = fopen("bill.txt","r");
                             fp1 = fopen("temp.txt","a");
                            char number[100];
                            char date[20];
                            int f=0;
                            printf("\n\n\n\t\t\t\tenter your Meter number you want to Delete :  ");
                            scanf("%s",&number);

                              while( fscanf(fp,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                    {
                                                if(strcmp(t.number,number)==0)
                                                {
                                                        f =1;
                                                        printf("\n\n\n\t\t\t\tDelete successfull\n\n");

                                                }
                                                else{
                                                       fprintf(fp1,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                                    }

                                    }
                                    if(f==0)
                                    {
                                        printf("\n\n\t\t\tMeter number not found");
                                    }
                                     fclose(fp);
                                     fclose(fp1);
                                     fp = fopen("bill.txt","w");
                                     fclose(fp);
                                      fp = fopen("bill.txt","a");
                                      fp1 = fopen("temp.txt","r");

                                      while(fscanf(fp1,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                      {
                                          fprintf(fp,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                      }
                                      fclose(fp);
                                      fclose(fp1);
                                      fp = fopen("temp.txt","w");
                                      fclose(fp);



}
int view()
{
            system("cls");
            fp=fopen("bill.txt","r");
            if(fp == NULL)
            {
                printf("file does not found !");
                exit(1);
            }
            else
            fp=fopen("bill.txt","r");
            {
                    printf("\n\n\n\t\tMeter No\tPresent Amount \tPrevious Amount \tLast Date of payment \n");
                    while(fscanf(fp,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                    {
                        printf("\t\t%s\t\t%d\t\t%d\t\t\t%s\n",t.number,t.present,t.previous,t.time);
                    }

            }
           fclose(fp);

}
int customer()
{
    int choice;
        system("cls");
        while(1){
                    printf("\n\t\t\t =============================================");
                    printf("\n\t\t\t\tWELCOME TO ELETRICITY BILL MANAGEMENT SYSTEM");

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
                            signin();
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
                return 0;
}
int customer_menu()
{
                   system("cls");
                    int choice;
                    while(1){
                    printf("\n\t\t\t =============================================");
                    printf("\n\t\t\t\tWELCOME TO ELETRICITY BILL MANAGEMENT SYSTEM");
                    printf("\n\t\t\t =============================================");
                     printf("\n\t\t\t\t\t ===================.");
                    printf("\n\t\t\t\t\t  Customer Menu.");
                      printf("\n\t\t\t\t\t ===================.\n");
                    printf("\n\n\t\t\t\t\t1. View Bill current month");

                    printf("\n\t\t\t\t\t2. View Bill Previous Record");

                    printf("\n\t\t\t\t\t3. Bill Payment Option");

                    printf("\n\t\t\t\t\t4. Payment History ");


                    printf("\n\t\t\t\t\t5. Exit");

                    printf("\n\t\t\t\t\t6. Go to back Main menu");

                    printf("\n\n\n\t\t\t\t\tEnter Your Choice: ");
                    scanf("%d",&choice);

                switch(choice)
                {
                     case 1:
                         current_month();
                         break;
                     case 2:
                          previous_month();
                          break;
                     case 3:
                        payment();
                        break;
                        case 4:
                        history();
                        break;
                     case 5:
                        exit(0);
                        break;
                     case 6:
                         main();
                         break;
                    default:
                           printf("\n\n\t\t\t\tWrong choice !\n\n");
                           break;
                }
                    }

}
int signin()
{
    system("cls");

            char r[10];
            gets(r);
            int k=1,l=0,i=0,j;
            char password[30];
            char regname[30];
            char ch;
              gotoxy(41,16);

              gotoxy(41,17);
            printf("Enter User Name: ");
              gets(regname);

            fp=fopen("student.txt","r");
            {
                while(fscanf(fp,"%s %s %s",student.name,student.id,student.password)!=EOF)
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
                 while(fscanf(fp,"%s %s %s",student.name,student.id,student.password)!=EOF)
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
                        return 0;
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
                signin();
            return 0;

}
int registation()
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
                printf("Meter No: ");
                gets(student.id);
                 gotoxy(41,14);
                printf("Password: ");
                gets(student.password);
                fprintf(fp,"%s %s %s\n",student.name,student.id,student.password);
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

   return 0;

}
int current_month()
{
                             system("cls");

                            char number[100];
                            char date[20];
                            fp = fopen("bill.txt","r");
                            printf("\n\n\n\t\t\t\tenter your Meter number  :  ");
                            scanf("%s",number);
                              if(fp == NULL)
                                {
                                    printf("file does not found !");
                                    exit(1);
                                }
                                else
                                 fp=fopen("bill.txt","r");
                                {
                                      while( fscanf(fp,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                            {
                                                        if(strcmp(t.number,number)==0)
                                                        {
                                                                   printf("\n\t\t***************************************\n");
                                                                   printf("\n\t\t\tMeter Number :: %s",number);
                                                                   printf("\n\t\t\tPresent  Bill Amount :: %d",t.present);
                                                                   printf("\n\t\t\tLast Date of payment :: %s",t.time);
                                                                   printf("\n\n\t\t***************************************\n");
                                                        }
                                            }
                                 }
                                fclose(fp);



}
int previous_month()
{
                            system("cls");

                            char number[100];
                            char date[20];
                            fp = fopen("bill.txt","r");
                            printf("\n\n\n\t\t\t\tenter your Meter number  :  ");
                            scanf("%s",number);
                              if(fp == NULL)
                                {
                                    printf("file does not found !");
                                    exit(1);
                                }
                                else
                                 fp=fopen("bill.txt","r");
                                {
                                      while( fscanf(fp,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                            {
                                                        if(strcmp(t.number,number)==0)
                                                        {
                                                                   printf("\n\t\t***************************************\n");
                                                                   printf("\n\t\t\tMeter Number :: %s",number);
                                                                   printf("\n\t\t\tPrevious  Bill Amount :: %d",t.previous);
                                                                   printf("\n\t\t\t Last Date of payment :: %s",t.time);
                                                                   printf("\n\n\t\t***************************************\n");
                                                        }
                                            }
                                 }
                                fclose(fp);


}
int payment()
{
     system("cls");

                                int present,sum,pay,due;
                                  fp = fopen("bill.txt","r");
                                 fp1 = fopen("temp.txt","a");
                                fp2= fopen("bill 2.txt","a");

                                char number[100];
                                char date[20];
                                int f=0;
                                printf("\n\n\n\t\t\t\tenter your Meter number :  ");
                                scanf("%s",number);

                                    while( fscanf(fp,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                    {
                                    if(strcmp(t.number,number)==0)
                                    {
                                                    f =1;
                                                    printf("\n\t\t***************************************\n");
                                                    printf("\n\t\t\tMeter Number :: %s",number);
                                                    printf("\n\t\t\tPresent Bill Amount :: %d",t.present);
                                                    printf("\n\t\t\tPrevious  Bill Amount :: %d",t.previous);
                                                    printf("\n\t\t\tLast Date :: %s",t.time);
                                                    printf("\n\n\t\t***************************************\n");

                                                    sum = t.present+t.previous;
                                                    printf("\n\n\t\t\t Total Bill is :: %d",sum);


                                                    printf("\n\n\t\t\tenter your payment amount bill is :: ");
                                                    scanf("%d",&pay);
                                                    if(pay==sum)
                                                    {
                                                            t.present=0;
                                                            t.previous=0;
                                                            fprintf(fp1,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                                            printf("\n\n\t\t\tYour Payment Success");
                                                            printf("\n\n*****THANK YOU*****");
                                                    }
                                                    else{
                                                        int due = sum-pay;
                                                        printf("\n\n\t\t\tyour due bill is :: %d",due);
                                                        t.present=0;
                                                        due = due +15;
                                                        fprintf(fp2,"%s %d %d\n",number,pay,due);
                                                        fclose(fp2);
                                                        printf("\n\n\t\t\tExtra amount for due is 15 TK \n\n\t\t\t So next month u need to pay:%d Tk Extra",due);
                                                        fprintf(fp1,"%s %d %d %s\n",t.number,t.present,due,t.time);
                                                    }



                                                }
                                                else{
                                                       fprintf(fp1,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                                    }

                                    }
                                    if(f==0)
                                    {
                                        printf("\n\n\t\t\tMeter number not found");
                                    }

                                     fclose(fp);
                                     fclose(fp1);
                                     fp = fopen("bill.txt","w");
                                     fclose(fp);
                                      fp = fopen("bill.txt","a");
                                      fp1 = fopen("temp.txt","r");

                                      while(fscanf(fp1,"%s %d %d %s\n",t.number,&t.present,&t.previous,t.time)!=EOF)
                                      {
                                          fprintf(fp,"%s %d %d %s\n",t.number,t.present,t.previous,t.time);
                                      }
                                      fclose(fp);
                                      fclose(fp1);
                                      fp = fopen("temp.txt","w");
                                      fclose(fp);


}
int history()
{
      system("cls");
      int pay,due,f=0;
      char num[100],number[100];
      printf("\n\n\n\t\t\t\t Enter your Meter number :  ");
      scanf("%s",num);
      fp2=fopen("bill 2.txt","r");
      while( fscanf(fp2,"%s %d %d \n", &number,&pay,&due)!=EOF)
                {
                if(strcmp(number,num)==0)
                {
                f=1;
            //fp2=fopen("bill 2.txt","r");
            if(fp2 == NULL)
            {
                printf("file does not found !");
                exit(1);
            }

            else
            {
                    printf("\n\n\n\t\tMeter\t\tYou paid \t\tDue Amount \t\n");
                    while(fscanf(fp2,"%s %d \t%d \n",&number,&pay,&due)!=EOF)
                    {
                    printf("\t\t%s\t\t%d\t\t\t%d\n",number,pay,due);
                    }

            }
            }
            }
             fclose(fp2);
           fp2=fopen("bill 2.txt","r");

                if(f==0)
                    {
                  printf("\n\n\t\t\tMeter number not found");
                    }

           fclose(fp2);



            //fp2=fopen("bill 2.txt","r");


       }
COORD coord={0,0};

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

