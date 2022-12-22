#define _WIN32_WINNT 0x0500
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

int ConsoleTitle(void);
int MaximizeOutputWindow(void);
int SetConsoleSize(void);
int loading();
int user_registration();
int user_login();
int i=0,choice,n,a;
int rem=0,pc=0,optioon=0;
char ch;
FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;

struct registration
{
    char fname[30];
    char sname[25];
    char mobile[50];
    char uname[30];
    char pass[25];
    int cash;

}reg,cus[100],cust[100],y[99];

struct Details
{
    char cname[30];
    int cash;
    int flag;
}d,detl[100],detl2[100];



int main()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t");
    char a[16] = "Loading......!!";
    for(i=0;i<16;i++)
    {
        printf("%c",a[i]);
        Sleep(60);
        printf(" ");
    }
    printf("\n\n\n\t\t\t\t");
        system("pause");
        system("cls");
    int n;
    printf("\n\n\n\n\t\t");
    printf("\t\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ WELCOME TO THE PROJECT $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\t\t");
    printf("\t\t\t\t\t\t\t\t\t<<<<<<<<<<<<<<<ADMIN PAGE>>>>>>>>>>>>>>>>>\n\n\n\n\t\t");
    printf("1. Log in\n\n\t\t");
    printf("2. Registration\n\n\n\n\t\t");
    printf("Enter Your Choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        loading();
        user_login();
        break;
    case 2:
        loading();
        user_registration();
        break;
    default:
        printf("\n\n\t\t");
        printf("Wrong Pressed\n\n\t");
        system("pause");
        main();
    }

}





int loading()

{
    int i;
    char a[8]="Loading";
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
    for(i=0; i<20; i++)
    {
        printf("\xB2");
        Sleep(10);
    }
    for(i=0; i<8; i++)
    {
        printf(" ");
        printf("%c",a[i]);
        Sleep(60);
    }
    for(i=0; i<20; i++)
    {
        printf("\xB2");
        Sleep(10);
    }

}


int user_login()

{
    system("cls");
    system("COLOR 0E");
    printf("\n\n\n\n\t\t");
    printf("\t\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ WELCOME TO CBOD $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t-------------------------------------USER LOGIN PAGE---------------------------------------\n\n\n\n");
    printf("\n\n\t\tFor Login Enter User Name & Password\n\n");
    int i, rem=0, optioon=0;
    char ch;
    FILE *fp1,*fp2;
    fflush(stdin);
    char uname1[30];
    char passl[30];
    printf("\n\n\t\t\tUser Name: ");
    gets(uname1);
    fflush(stdin);

    printf("\n\t\t\tPassword: ");
    gets(passl);
    fp1 = fopen("regis.bin","rb+");
    fread(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);
    for(i=0; i<100; ++i)
    {
        if ((0==strcmp(uname1,cust[i].uname)) && (0==strcmp(passl,cust[i].pass)))
        {
            printf("\n\n\t\tLogin Successfully\n");
            printf("\n %s \n",cust[i].fname);
            printf("\n");

            optioon=1;
            loading();
            system("cls");
            reg.cash = cust[i].cash;
            strcpy(reg.fname,cust[i].fname);
            strcpy(reg.mobile,cust[i].mobile);
            strcpy(reg.uname,cust[i].uname);
            printf("\n %s \n",reg.fname);

            home_page(i);
            i=100;


        }

    }
    if(optioon==1)
    {
        system("pause");
    }
    else
    {

        printf("\n\n\t\t\tWrong User Name or Password\n\n\n\n\t\t");
        system("pause");
        printf("\n\n\n\n\t\t\t");
        printf("Press 1 for Log in Again\n\n\t\t\t");
        printf("Press 2 for Registration\n\n\n\n\t\t\t");
        printf("Enter Your Choice: ");
        fflush(stdin);
        scanf("%d",&choice);
        if(choice==1)
        {
            loading();
            user_login();
        }
        else if(choice==2)
        {
            loading();
            user_registration();
        }
        else
        {
            printf("\n\n\n\t\tWrong Entry\n\n\n\t\t");
            system("pause");
            main();
        }
    }
}

int add_details(int x,int flag)
{
    int i, rem=0, optioon;
    FILE *fp5,*fp6;
    fp6=fopen("p2number.bin","rb+");
    if (fp6==NULL)
    {
        fp6 = fopen("p2number.bin","wb+");
        fwrite(&rem, sizeof(rem), 1, fp6);
        fclose(fp6);
    }
    fread(&rem, sizeof(rem), 1, fp6);
    fclose(fp6);
    fp5 = fopen("regis(2).bin","rb+");
    if (fp5==NULL)
    {
        fp5 = fopen("regis(2).bin","wb+");
        fclose(fp5);
    }
    fread(&detl, sizeof(detl), 1, fp5);
    fclose(fp5);
    fflush(stdin);
    printf("\nrem value = %d\n",rem);
    for(i=rem; i<rem+1; ++i)

    {

        printf("\n\n\n\t\t\tUser Name: ");
        gets(detl[i].cname);
        fflush(stdin);
        detl[i].cash = x;
        detl[i].flag = flag;


    }
    fp5 = fopen("regis(2).bin","wb+");
    fwrite(&detl, sizeof(detl), 1, fp5);
    fclose(fp5);
    fp6 = fopen("p2number.bin","wb+");
    ++rem;
    fwrite(&rem, sizeof(rem), 1, fp6);
    fclose(fp6);
}

void show_details()
{
    FILE *fp5,*fp6;
    fp5 = fopen("regis(2).bin","rb+");
    if (fp5==NULL)
    {
        printf("\n No Entry \n");
    }
    fread(&detl2, sizeof(detl2), 1, fp5);
    fclose(fp5);
    fflush(stdin);
    for(i=0; i<100; ++i)
    {
        if(detl2[i].cash == 0)
        {
            break;
        }
        if(detl2[i].flag)
            printf("\nCash In [ Name : %s  ; Price : %d ]\n",detl2[i].cname,detl2[i].cash);
        else{
            printf("\nCash Out [ Name : %s  ; Price : %d ]\n",detl2[i].cname,detl2[i].cash);
        }



    }

    getch();
}


int user_registration(void)
{
    system("cls");

    printf("\n\n\n\t\t\t\t");
    printf("\t\t\t\t    For Registration: Enter Your[Full Name,User Name,Password,Mobile Number]\n\n");
    int i, rem=0, optioon;
    FILE *fp1,*fp2;
    fp2=fopen("pnumber.bin","rb+");
    if (fp2==NULL)
    {
        fp2 = fopen("pnumber.bin","wb+");
        fwrite(&rem, sizeof(rem), 1, fp2);
        fclose(fp2);
    }
    fread(&rem, sizeof(rem), 1, fp2);
    fclose(fp2);

    fp1 = fopen("regis.bin","rb+");
    if (fp1==NULL)
    {
        fp1 = fopen("regis.bin","wb+");
        fclose(fp1);
    }
    fread(&cus, sizeof(cus), 1, fp1);
    fclose(fp1);
    fflush(stdin);
    for(i=rem; i<rem+1; ++i)

    {

        printf("\n\n\n\t\t\tFull Name: ");
        gets(cus[i].fname);
        printf("\n\n\t\t\tUser Name: ");
        gets(cus[i].uname);
        printf("\n\n\t\t\tPassword: ");
        gets(cus[i].pass);
        printf("\n\n\t\t\tMobile Number: ");
        gets(cus[i].mobile);
        fflush(stdin);
        cus[i].cash = 22;

    }

    fp1 = fopen("regis.bin","wb+");
    fwrite(&cus, sizeof(cus), 1, fp1);
    fclose(fp1);
    fp2 = fopen("pnumber.bin","wb+");
    ++rem;
    fwrite(&rem, sizeof(rem), 1, fp2);
    fclose(fp2);
    pc=pc+1;
    printf("\n\n\t\tYour are successfully Registered\n\n\t\t");
    printf("Thanks For Your Registration\n\n\t\t\t");
    printf("Press 1 for Login\n\n\t\t\t");
    printf("Press 2 for Again Registration\n\n\t\t\t");
    printf("Enter You choice: ");
    scanf("%d",&choice);
    if(choice==1)
    {
        loading();
        user_login();
    }
    else if(choice==2)
    {
        loading();
        user_registration();
    }
    else
    {
        printf("\n\n\n\t\tWrong Entry\n\n\n\t\t");
        system("pause");
        main();
    }
}
int home_page(int i)

{
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t\t  ******************************************************************\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t  *************************User Dashbord****************************\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t   ******************************************************************\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t__________________________________\n\n");

    printf("\n User name = %s \n",reg.uname);
    printf("\n Full name = %s \n",reg.fname);
    printf("\n Mobile No = %s \n",reg.mobile);
    printf("\n Total Balance = %d\n",reg.cash);




    //CashIn(10,i);

    printf("\n\n\n\t\t\tPress 1.========<> Cash In 5 Taka \n\n\t\t\t");
    printf("Press 2.========<> Cash In 2 Taka\n\n\t\t\t");
    printf("Press 3.========<> Cash In 1 Taka\n\n\t\t\t");
    printf("Press 4.========<> Cash Out 5 Taka\n\n\t\t\t");
    printf("Press 5.========<> Cash Out 2 Taka\n\n\t\t\t");
    printf("Press 6.========<> Cash Out 1 Taka\n\n\t\t\t");
    printf("Press 7.========<> Show Transiction \n\n\t\t\t");
    printf("Press 8.========<> Exit\n\n\n\n\t\t\t");

    printf("Enter Your Choice: ");

    scanf("%d",&n);
    switch(n)
    {
    case 1:
        system("cls");
        add_details(5,1);
        CashOut5taka(i);


        break;
    case 2:
        system("cls");
        add_details(2,1);
        CashOut2taka(i);
        break;
    case 3:
        system("cls");
        add_details(1,1);
        CashOut1taka(i);
        break;
    case 4:
        system("cls");
        add_details(5,0);
        CashIn5taka(i);

        break;
    case 5:
        system("cls");
        add_details(2,0);
        CashIn2taka(i);
        break;
    case 6:
        system("cls");
        add_details(1,0);
        CashIn1taka(i);
    case 7:
        show_details();
        home_page(i);
    case 8:
        getch();
        break;
    default:
        printf("\n\n\n\t\t\tWrong Entry\n\n\t\t\t");
        system("pause");
        home_page(i);


    }
}

void CashIn5taka(int i){

    fp1 = fopen("regis.bin","rb+");
    fread(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    reg.cash-=5;
    cust[i].cash-=5;
    fp1 = fopen("regis.bin","wb+");
    fwrite(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    home_page(i);
}
void CashIn2taka(int i){

    fp1 = fopen("regis.bin","rb+");
    fread(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    reg.cash-=2;
    cust[i].cash-=2;
    fp1 = fopen("regis.bin","wb+");
    fwrite(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    home_page(i);
}
void CashIn1taka(int i){

    fp1 = fopen("regis.bin","rb+");
    fread(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    reg.cash-=1;
    cust[i].cash-=1;
    fp1 = fopen("regis.bin","wb+");
    fwrite(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    home_page(i);
}
void CashOut2taka(int i){

    fp1 = fopen("regis.bin","rb+");
    fread(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    reg.cash+=2;
    cust[i].cash+=2;
    fp1 = fopen("regis.bin","wb+");
    fwrite(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    home_page(i);
}

void CashOut1taka(int i){

    fp1 = fopen("regis.bin","rb+");
    fread(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    reg.cash+=1;
    cust[i].cash+=1;
    fp1 = fopen("regis.bin","wb+");
    fwrite(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    home_page(i);
}
void CashOut5taka(int i){

    fp1 = fopen("regis.bin","rb+");
    fread(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    reg.cash+=5;
    cust[i].cash+=5;
    fp1 = fopen("regis.bin","wb+");
    fwrite(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);

    home_page(i);
}
