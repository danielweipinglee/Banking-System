#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define true 1
#define false 0
int G;
int F;
int C;
int S;
int vpin();
void Menu();
void Deposit();
void Withdraw();
void Query();
void Transfer();
void Cancel();
void clear();
int main()
{
srand(time(NULL));
int ANO = rand()%90000+10000;
int PIN = rand()%9000+1000;
int checking = rand()%10000;
int saving = rand()%1000;
G=ANO;
F=PIN;
C=checking;
S=saving;
printf("\t\t\t\t~~~Banking System~~~\t\t\t\t\n");
printf("************************************************************************************************\n");
printf("***This is highly secure banking system every invalid selection will result stsyem auto close***\n");
printf("************************************************************************************************\n"); 
printf("This is your first log in(Please remeber your account number and PIN)\n");
printf("Your ACCOUNT NUMBER IS %d\n",ANO);
printf("Your PIN IS %d\n",PIN);
Menu();
return 0;
}

void clear()
{
 while(getchar()!='\n');
}

int vpin()
{
int acct,pin;
int count=0;
int valid=0;
while(count<3)
{
printf("Enter Your Account Number:\n");
int numRead=scanf("%d",&acct);
if(numRead>0&&acct==G)
{
printf("Enter Your PIN:\n");
int numRead1=scanf("%d",&pin);
}
if (numRead>0) 
{
if((acct==G&&pin==F))
{
printf("Correct!\n");
valid=1;
return valid;
break;
}
}
clear();
count++;
printf("Incorrect Account Number or PIN! Attempt Reminder:%d\n",3-count);
}
if(valid)
{
printf("Correct!\n");
}
else
{
printf("Error\n");
printf("Your account has been locked due to three times incorrect attempts!\n");
valid=0;
return valid;
}
}

void Menu()
{
int select;
int count=0;
int vv=0;
printf("\t\t\t\t~~~Main Menu~~~\t\t\t\t\n");
printf("Choice the option to continue or type 5 to cancel service\n");
printf("Enter 1 to 5.\n");
printf("***********************************************************\n");
printf("1.Deposit\n");
printf("2.Withdraw\n");
printf("3.Query\n");
printf("4.Transfer\n");
printf("5.Cancel\n");
printf("***********************************************************\n");
while(1)
{
printf("Enter the number for your selection:");
int A=scanf("%d",&select);
if(A>0)
{
if (select==1||select==2 || select==3 || select ==4 || select ==5)
{
vv=1;
break;
}
}
clear();
count++;
printf("Incorrect Selection\n");
}
if(vv)
{
switch(select)
{
 case 1:
        if (vpin()==0)
        break;
        else 
        Deposit();break;
 case 2:
        if(vpin()==0)
        break;
        else 
        Withdraw();break; 
 case 3:
        if(vpin()==0)
        break;
        else
        Query();break;
 case 4:
        if(vpin()==0)
        break;
        else
        Transfer();break;
 case 5:
        Cancel();
        break;
 default:
        printf("ERROR!Incorrect Action!\n");
        Menu();
        break;
}
}
else 
{
printf("Error\n");
}
}



void Deposit()
{
int save,savea;
int v=0;
int count=0;
int number;
printf("\t\t\t\t~~~Deposit Funds~~\t\t\t\t\n");
printf("*****************************************************************************\n");                        
printf("***This allow you to save your money into your checking or saving  account***\n");
printf("*****************************************************************************\n");
printf("Current Balance:\n");
printf("Your checking account has:$%d\n",C);
printf("Your saving account has:$%d\n",S);
printf("********************************************************\n");
while(count<3)
{
printf("You want to save into your 1.checking or 2.saving?\n");
int Read=scanf("%d",&number);
if(Read>0)
{
if (number==1 || number ==2)
{
v=1;
break;
}
}
clear();
count++;
printf("Incorrect selection! Attempt Reminder:%d\n",3-count);
}
if(v&&number==1)
{
printf("How much you want to save into your checking account?$\n");
scanf("%d",&save);
printf("you are going to save $%d to your checking account!\n",save);
printf("********************************************************\n");
printf("Completed\n");
printf("Now your checking has $%d \n",C+save);
C+=save;
printf("Thank you! Hope to see you soon!\n");
Menu();
}
else if (v&&number==2)
{
printf("How much you want to save into your saving account?$\n");
scanf("%d",&savea);
printf("you are going to save $%d to your saving account!\n",savea);
printf("*******************************************************\n");
printf("Completed\n");
printf("Now your saving has $%d\n",S+savea);
S+=savea;
printf("Thank you! Hope to see you soon!\n");
Menu();
}
else
{ 
printf("Error\n");
printf("Your account has been locked due to three times incorrect attempts!\n");
}
}

void Withdraw()
{
int accounttype;
int count=0;
int withdraw;
int sw;
int va=0;
printf("\t\t\t\t~~~Withdraw Funds~~~\t\t\t\t\n");
printf("***************************************************************************\n");
printf("***This allow you to withdraw money from your checking or saving account***\n");
printf("***************************************************************************\n");
printf("Current Balance:\n");
printf("Your checking account has:$%d\n",C);
printf("Your saving account has:$%d\n",S);
printf("***************************************************************************\n");
while(count<3)
{
printf("Choose either 1.Checking Accuount or 2.Saving Account:");
int R=scanf("%d",&accounttype);
if(R>0)
{
if(accounttype==1||accounttype==2)
{
va=1;
break;
}
}
clear();
count++;
printf("Incorrect Selection! Attempt Reminder:%d\n",3-count);
}
if(va)
{
printf("How much you want to withdraw?$");
scanf("%d",&sw);
}
printf("***************************************************************************\n");
if((accounttype==1&&C>sw)||(accounttype==1&&C==sw))
{
printf("Completed\n");
printf("Now your checking account has $%d\n",C-sw);
C-=sw;
printf("Thank you!");
Menu();
}
else if(accounttype==1&&C<sw)
{
printf("Sorry, you do not have enough money to withdraw. Your transection can not be process.\n");
Menu();
}
else if((accounttype==2&&S>sw)||(accounttype==2&&S==sw))
{
printf("Completed\n");
printf("Now your saving account has $%d\n",S-sw);
S-=sw;
Menu();
}
else if(accounttype==2&&S<sw)
{
printf("Sorry, you do not have enough money to withdraw. Your transection can not be process.\n");
Menu();
}
else
{
printf("Your account has been locked due to three times incorrect attempts!\n");
}
}


void Transfer()
{
int s;
int a;
int v1=0;
int count=0;
printf("\t\t\t\t~~~Transfer Funds~~~\t\t\t\t\n");
printf("************************************************************************************\n");
printf("***This allow you to transfer your money between your checking and saving account***\n");
printf("************************************************************************************\n");
printf("Current Balance:\n");
printf("Your checking account has:$%d\n",C);
printf("Your saving account has:$%d\n",S);
printf("************************************************************************************\n");
while(count<3)
{
printf("Please select 1.Checking Account or 2.Saving Account that you want to transfer from:");
int R1=scanf("%d",&s);
if(R1>0)
{
if(s==1||s==2)
{
v1=1;
break;
}
}
clear();
count++;
printf("Incorrect Selection! Attempt Reminder:%d\n",3-count);
}
if(v1)
{
printf("Please enter the amount that you want to transfer:$"); 
scanf("%d",&a);
}
if((s==1&&C>a)||(s==1&&C==a))
{
printf("You are going to transfer $%d to your Saving Account.\n",a);
printf("************************************************************************************\n");
printf("Completed\n");
printf("Now you have $%d in your Checking Account!\n",C-a);
printf("NOw you have $%d in your Saving Account!\n",S+a);
printf("Thank you!\n");
C-=a;
S+=a;
Menu();
}
else if(s==1&&C<a)
{
printf("Sorry, you current Checking Account has not enough money for transfer!\n");
Menu();
}
if((s==2&&S>a)||(s==2&&S==a))
{
printf("You are going to transfer $%d to your Checking Account.\n",a);
printf("************************************************************************************\n");
printf("Completed\n");
printf("Now you have $%d in your Checking Account!\n",C+a);
printf("Now you have $%d in your Saving Account!\n",S-a);
printf("Thank you!\n");
C+=a;
S-=a;
Menu();
}
else if(s==2&&S<a)
{
printf("Sorry, you current Saving Account has not enough money for transfer!\n");
Menu();
}
else
{
printf("Error!\n");
printf("Your account has been locked due to three times incorrect attempts!\n");
Menu();
}
}

void Cancel()
{
int c;
printf("\t\t\t\t~~~Cancel~~~\t\t\t\t\n");
printf("Are you sure you wwant to quit and cancel the transection(1.Yes 2.No):");
scanf("%d",&c);
if(c==1)
{
return; 
}
if(c==2)
{
printf("I am glad you back!\n");
printf("\n");
printf("\n");
Menu();
}
}

void Query()
{
printf("\t\t\t~~~Query Funds!!!\t\t\t\n");
printf("Checking:$%d\n",C);
printf("Saving:$%d\n",S);
printf("\n");
printf("\n");
Menu();
}
