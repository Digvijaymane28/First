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
    printf("-----------------------------------------------------\n");
    printf("          Welcome to Number System Converter  \n");
    printf("-----------------------------------------------------\n");
    while (choice )
    {
        printf("\n\n1) Decimal to Binary. \n2) Binary to Decimal. \n3) Decimal to Octal. \n4) Octal to Decimal. \n5) Decimal to Hexadecimal. \n6) Hexadecimal to Decimal \n7) Exit.\n\n");
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
    FILE *InputFile,*OutputFile;                    
    InputFile=fopen("Input.txt","a+");     
     
    // Open input file
    printf("\nEnter decimal number: ");
    scanf("%d", &number);

    fprintf(InputFile,"\nDecimal number : ");  
    fprintf(InputFile,"%d",number);             
    fclose(InputFile);

    while (number > 0)
    {
        bin[cnt] = number % 2;
        number = number / 2;
        cnt++;
    }
     
     OutputFile=fopen("Output.txt","a+");
    /*print value in reverse order*/
    printf("\nRESULT\n");
    printf("Binary value is: ");
    // Write output to file
    fprintf(OutputFile,"\nBinary number : ");
    for (i = (cnt - 1); i >= 0; i--)
    {
        printf("%d",bin[i]);
        fprintf(OutputFile, "%d",bin[i]);
    }
    // Close output file
    fclose(OutputFile);
}

/*C program to convert number from binary to decimal*/
void binary_to_deci()
{
    // File pointers for input and output files
    FILE *InputFile, *OutputFile;
    
    // Open input file 
    InputFile = fopen("Input.txt", "a+");
    int binary_num;
    printf("Enter a Binary number:");
    scanf("%d",&binary_num);

    fprintf(InputFile,"\nBinary number : ");
    fprintf(InputFile,"%d",binary_num);
    fclose(InputFile);

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
    OutputFile=fopen("Output.txt","a+");
  
    printf("\n\nRESULT\n");
    printf("Decimal value is: ");
    // Write output to file
    fprintf(OutputFile,"\nDecimal number : ");
    printf("%d",decimal_num);
    fprintf(OutputFile, "%d",decimal_num);
    printf("\n"); 

    // Close output file
    fclose(OutputFile);

}

/*C program to convert number from decimal to octal*/
void deci_to_octal()
{
    // File pointers for input and output files
    FILE *InputFile, *OutputFile;
    
    // Open input file
    InputFile = fopen("Input.txt", "a+");
    int decimal_num,i=0;
    
    printf("Enter Decimal number:");
    scanf("%d",&decimal_num);

    fprintf(InputFile,"\nDecimal number : ");
    fprintf(InputFile,"%d",decimal_num);
    fclose(InputFile);

    int octal_num[8];
    while(decimal_num != 0)
    {
       octal_num[i] = decimal_num % 8; 
       decimal_num = decimal_num/8;
       i++;
    }
    // Open output file 
    OutputFile=fopen("Output.txt","a+");

    printf("\n\nRESULT\n");
    printf("Octal value is: ");
    // Write output to file
    fprintf(OutputFile,"\nOctal number : ");
    for(int j= i-1;j>=0;j--)
    {
        printf("%d",octal_num[j]);
        fprintf(OutputFile, "%d",octal_num[j]);

    }
    // Close output file
    fclose(OutputFile);
}

/*C program to convert number from octal to decimal*/
void oct_to_deci()
{
    // File pointers for input and output files
    FILE *InputFile, *OutputFile;
    
    // Open input file
    InputFile= fopen("Input.txt", "a+");
    int rem=0,number,count=0,dec=0;

    printf("Enter octal Number=");
    scanf("%d", &number);

    fprintf(InputFile,"\nOctal number : ");
    fprintf(InputFile,"%d",number);
    fclose(InputFile);

    while(number)
    {
        rem=number%10;
        dec=dec+rem*pow(8,count);
        number=number/10;
        count++;
    }
    // Open output file 
    OutputFile=fopen("Output.txt","a+");
  
    printf("\n\nRESULT\n");
    printf("Decimal value is: ");
    // Write output to file
    fprintf(OutputFile,"\nDecimal number : ");
    printf("%d",dec);
    fprintf(OutputFile, "%d",dec);
   // Close output file
    fclose(OutputFile);
}

void deci_to_hexa()
{
    // File pointers for input and output files
    FILE *InputFile, *OutputFile;
    
    // Open input file
    InputFile = fopen("Input.txt", "a+");
    int num,temp,rem,i=1,j;
    char hexa[16];
    printf("Enter Decimal number:");
    scanf("%d",&num);
    temp=num;

    fprintf(InputFile,"\nDecimal number : ");
    fprintf(InputFile,"%d",num);
    fclose(InputFile);

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

    // Open output file 
    OutputFile=fopen("Output.txt","a+");
    printf("Hexadecimal number is :");
    // Write output to file
    fprintf(OutputFile,"\nHexadecimal number : ");
    for(j=i-1;j>0;j--)
    {
        printf("%c",hexa[j]);
        fprintf(OutputFile, "%c",hexa[j]);
    }
   // Close output file
   fclose(OutputFile);
}

void hexa_to_deci()
{
    // File pointers for input and output files
    FILE *InputFile, *OutputFile;
    
    // Open input file 
    InputFile = fopen("Input.txt", "a+");
     char hexa[16];
    int sum=0,i,len,j=0;
    printf("Enter Hexadecimal number:");
    scanf("%s",&hexa);

    fprintf(InputFile,"\nHexadecimal number : ");
    fprintf(InputFile,"%s",hexa);
    fclose(InputFile);

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

    // Open output file 
    OutputFile=fopen("Output.txt","a+");
    printf("Decimal value is %d",sum);
    // Write output to file
    fprintf(OutputFile,"\nDecimal number : ");
    fprintf(OutputFile, "%d",sum);
    // Close output file
    fclose(OutputFile);
}
