#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct{
   char name[25];
   char phone[25];
   char address[50];
   char email[25];
}c;
FILE *fp;
FILE *fp1;
int add_contact();
int view_contact();
int delete_contact();
int search_contact();
int edit_contact();
void name_edit();
void phone_number_edit();
void address_edit();
void email_edit();
void all_data_edit();
int main()
{
    system("cls");
    int choice;
    printf("\n\t **** Welcome to Contact Management System ****");
    while(1){
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[6] Exit\n\t\t=================\n\t\t");

    printf("\n\t\tEnter the choice: ");

    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        add_contact();
        break;
    case 2:
        view_contact();
        break;
    case 3:
        search_contact();
        break;
    case 4:
        edit_contact();
        break;
    case 5:
        delete_contact();
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("wrong choice !!!!!!!");
    }
  }
}
int add_contact()
{
    system("cls");
        char r[10];
        char number[10];
        gets(r);
        fp=fopen("contact.txt","a+");
        {
            printf("\n\n\n\t\t\t\tName : ");
            scanf("%s",c.name);
            printf("\n\t\t\t\tPhone Number : ");
            scanf("%s",&c.phone);
            printf("\n\t\t\t\tAddress : ");
            scanf("%s",c.address);
            printf("\n\t\t\t\tEmail : ");
            scanf("%s",c.email);
            fprintf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
            printf("\n\n\t\t\t\tRecord insert successful");

        }

       fclose(fp);

}
int view_contact()
{
    system("cls");
    fp=fopen("contact.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    fp=fopen("contact.txt","r");
    {
        printf("\n\n\n\t\tName                 Phone number            Address               Email\n");
        printf("========================================================================================");
        while(fscanf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
        {
            printf("\n\nNAME: %s",c.name);
            printf("\nPHONE NUMBER : %s",c.phone);
            printf("\nADDRESS : %s",c.address);
            printf("\nEMAIL : %s",c.email);
        }
        printf("\n\n=========================================================================================");

    }
   fclose(fp);

}
int delete_contact()
{
    system("cls");
     fp = fopen("contact.txt","r");
     fp1 = fopen("temp.txt","a");
     char number[100];
     char date[20];
     int f=0;
     printf("\n\n\n\t\t\t\tenter your name you want to Delete :  ");
     scanf("%s",&number);

     while(fscanf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
     {
            if(strcmp(c.name,number)==0)
            {
                    f =1;
                    printf("\n\n\n\t\t\t\tDelete successfull\n\n");
            }
            else
            {
                fprintf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
            }

     }
     if(f==0)
     {
            printf("\n\n\t\t\tname not found");
     }
     fclose(fp);
     fclose(fp1);
     fp = fopen("contact.txt","w");
    fclose(fp);
     fp = fopen("contact.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
int search_contact()
{
    system("cls");
    char number[30];
    fp = fopen("contact.txt","r");
    printf("\n\n\n\t\t\t\tenter your name  :  ");
    scanf("%s",&number);
    if(fp == NULL)
    {
            printf("file does not found !");
            exit(1);
    }
    else{
        fp=fopen("contact.txt","r");
        {
            while(fscanf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
            {
                if(strcmp(c.name,number)==0)
                {
                    printf("\n\n\n\t\tName                 Phone number            Address               Email\n");
                    printf("========================================================================================");
                    printf("\n\nNAME: %s",c.name);
                    printf("\nPHONE NUMBER : %s",c.phone);
                    printf("\nADDRESS : %s",c.address);
                    printf("\nEMAIL : %s",c.email);
                    printf("\n\n=========================================================================================");
                }

            }
        }
    }
    fclose(fp);

}
int edit_contact()
{
    system("cls");
    int choice;
    fp = fopen("contact.txt","r");
    fp1 = fopen("temp.txt","a");
    printf("\n\n\t\t\twhat would you like to edit?");
    printf("\n\n\t\t\t[1] Name Edit ");
    printf("\n\t\t\t[2] Phone Number Edit ");
    printf("\n\t\t\t[3] Address Edit");
    printf("\n\t\t\t[4] Email Edit");
    printf("\n\t\t\t[5] All Data Edit");
    printf("\n\n\t\t\t Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
       case 1:
          name_edit();
          break;
       case 2:
          phone_number_edit();
          break;
       case 3:
          address_edit();
          break;
       case 4:
          email_edit();
          break;
       case 5:
          all_data_edit();
          break;
       default:
        printf("\n\t Wrong  Choice");
        break;
    }
}
void name_edit()
{
    system("cls");
    char number[30];
    char present[30];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Name :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        if(strcmp(c.name,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Name :");
            scanf("%s",present);
            fprintf(fp1,"%s %s %s %s\n",present,c.phone,c.address,c.email);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
        }

    }
    if(f==0)
    {
        printf("\n\n\t\t\tName not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("contact.txt","w");
    fclose(fp);
    fp = fopen("contact.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);
}
void phone_number_edit()
{
    system("cls");
    char number[30];
    char present[30];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Name :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        if(strcmp(c.name,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter Your New Phone Number :");
            scanf("%s",present);
            fprintf(fp1,"%s %s %s %s\n",c.name,present,c.address,c.email);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
        }

    }
    if(f==0)
    {
        printf("\n\n\t\t\tName not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("contact.txt","w");
    fclose(fp);
    fp = fopen("contact.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);
}
void address_edit()
{
    system("cls");
    char number[30];
    char present[30];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Name :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        if(strcmp(c.name,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Address :");
            scanf("%s",present);
            fprintf(fp1,"%s %s %s %s\n",c.name,c.phone,present,c.email);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
        }

    }
    if(f==0)
    {
        printf("\n\n\t\t\tName not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("contact.txt","w");
    fclose(fp);
    fp = fopen("contact.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);
}
void email_edit()
{
    system("cls");
    char number[30];
    char present[30];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Name :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        if(strcmp(c.name,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Email :");
            scanf("%s",present);
            fprintf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,present);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
        }

    }
    if(f==0)
    {
        printf("\n\n\t\t\tName not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("contact.txt","w");
    fclose(fp);
    fp = fopen("contact.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);
}
void all_data_edit()
{
    system("cls");
    char number[30];
    char present_name[30];
    char present_phone[15];
    char present_address[25];
    char present_email[20];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter your Name :  ");
    scanf("%s",number);
    while(fscanf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        if(strcmp(c.name,number)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Name :");
            scanf("%s",present_name);
            printf("\n\n\t\t\tEnter The New Phone Number :");
            scanf("%s",present_phone);
            printf("\n\n\t\t\tEnter The New Address :");
            scanf("%s",present_address);
            printf("\n\n\t\t\tEnter The New Email :");
            scanf("%s",present_email);
            fprintf(fp1,"%s %s %s %s\n",present_name,present_phone,present_address,present_email);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
        }

    }
    if(f==0)
    {
        printf("\n\n\t\t\tName not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("contact.txt","w");
    fclose(fp);
    fp = fopen("contact.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s\n",c.name,c.phone,c.address,c.email)!=EOF)
    {
        fprintf(fp,"%s %s %s %s\n",c.name,c.phone,c.address,c.email);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
