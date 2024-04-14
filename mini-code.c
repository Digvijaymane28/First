#include <stdio.h>
#include <math.h>
#include<string.h>

void deci_to_binary();
void binary_to_deci();
void deci_to_octal();
void oct_to_deci();
void deci_to_hexa();
void hexa_to_deci();

// Global variables
int cnt = 0, i, number;
int bin[16];

int main()
{
    int choice;
    printf("WEL-COME IN NUMBER SYSTEM CONVERSION.\n\n");

    while (choice )
    {
        printf("\n\n1) Decimal to Binary. \n2) Binary to decimal. \n3) Decimal to octal. \n4) Octal to Decimal. \n5)Decimal to Hexadecimal. \n6)Hexadecimal to Decimal \n7) Exit.\n\n");
        printf("Enter option from above list = ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deci_to_binary();
            break;

        case 2:
            binary_to_deci();
            break;

        case 3:
            deci_to_octal();
            break;

        case 4:
            oct_to_deci();
            break;
        case 5:
              deci_to_hexa();
            break;
        case 6:
              hexa_to_deci();
             break;
   
        case 7:
            printf("Exit Successful.");
            break;
        


        default:
            printf("Invalid Option.");
        }
    }
}

/*C program to convert number from decimal to binary*/
void deci_to_binary()
{
     // File pointers for input and output files
    FILE *inputFile, *outputFile;
    // Open input file in read mode
    inputFile = fopen("input.txt", "a+");
    
    printf("\n\nEnter decimal number: ");
    scanf("%d", &number);
    fprintf(input,"\nDecimal Number is ");
    fprintf(input,"%d",number);
    fclose(input);

    while (number > 0)
    {
        bin[cnt] = number % 2;
        number = number / 2;
        cnt++;
    }

    /*print value in reverse order*/
    printf("\n\nRESULT\n");
    printf("Binary value is: ");
    for (i = (cnt - 1); i >= 0; i--)
    {
        printf("%d", bin[i]);
    }
}

/*C program to convert number from binary to decimal*/
void binary_to_deci()
{
   int binary_num;
  printf("Enter a number:");
  scanf("%d",&binary_num);

  int i=0,decimal_num=0,rem;
  while(binary_num!=0)
   {
    rem = binary_num%10;

    if(rem==1)
     {
      decimal_num=decimal_num + pow(2,i);
     }
    binary_num = binary_num/10;
    i++;
   }
  
  printf("\n\nRESULT\n");
  printf("Decimal value is: ");
  printf("%d",decimal_num);
  printf("\n"); 


}

/*C program to convert number from decimal to octal*/
void deci_to_octal()
{
    int decimal_num,i=0;
    
    printf("Enter Decimal number:");
    scanf("%d",&decimal_num);

    int octal_num[8];
    while(decimal_num != 0)
    {
       octal_num[i] = decimal_num % 8; 
       decimal_num = decimal_num/8;
       i++;
    }

    printf("\n\nRESULT\n");
    printf("Octal value is: ");
    for(int j= i-1;j>=0;j--)
    {
        printf("%d",octal_num[j]);

    }
}

/*C program to convert number from octal to decimal*/
void oct_to_deci()
{
    int quot, store = 0, power = 0;

    printf("Enter octal Number=");
    scanf("%d", &number);
    quot = number;

    while (quot != 0)
    {
        bin[cnt] = quot % 10;
        quot = quot / 10;
        cnt++;
    }

    printf("\n\nRESULT\n");
    printf("Decimal value is: ");
    for (i = 0; i < cnt; i++)
    {
        power = 0;
        power = pow(8, i); // pow is a function.This function use to store number raise to power.
        store = store + (bin[i] * power);
    }
    printf("%d", store);
}

void deci_to_hexa()
{
    int num,temp,rem,i=1,j;
    char hexa[16];
    printf("Enter Decimal number:");
    scanf("%d",&num);
    temp=num;
    while(temp!=0)
    {
        rem=temp%16;
        if(rem<10)
            rem=rem+48;
        else
             rem=rem+55;
              hexa[i++]=rem;
              temp=temp/16;
    }
    printf("Hexadecimal number is :");
    for(j=i-1;j>0;j--)
    {
        printf("%c",hexa[j]);
    }


}

void hexa_to_deci()
{
     char hexa[16];
    int sum=0,i,len,j=0;
    printf("Enter hexadecimal number:");
    scanf("%s",&hexa);
    len=strlen(hexa);
    for(i=len-1;i>=0;i--)
    {
        if(hexa[i]>='0'&& hexa[i]<='9')
        {
            sum=sum+(hexa[i]-48)*pow(16,j);
            j++;
        }
        else if(hexa[i]>='A'&& hexa[i]<='F')
        {
            sum=sum+(hexa[i]-55)*pow(16,j);
            j++;

        }
    }
    printf("decimal value is %d",sum);
}
