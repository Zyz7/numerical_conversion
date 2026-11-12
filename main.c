#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

char getch(); 
void buffer();
void error();
void menu();
void decimal();
void binary();
void octal();
void hexadecimal();
int validateDecimal(char *);
void decimalToBinary(long);
void decimalToOctal(long);
void decimalToHexa(long);
int validateBinary(char *);
void binaryToDecimal(char *);
void binaryToOctal(char *);
void binaryToHexa(char *);
int validateOctal(char *);
void octalToDecimal(long);
void octalToBinary(long);
void octalToHexa(long);
int validateHexa(char *);
int valueHexadecimal(char v);
void hexaToDecimal(char *);
void hexaToBinary(char *);
void hexaToOctal(char *);
void exitMsg();

int main() 
{    
    menu();
    return 0;
}

void menu() 
{
    int option;

    //system("clear");

    printf("\n\033[0;34m********************************\n");
    printf("***** Numerical Conversion *****\n");
    printf("********************************\033[0m\n\n");

    printf("Select conversion type:\n");
    printf("1 Decimal conversion\n");
    printf("2 Binary conversion\n");
    printf("3 Octal conversion\n");
    printf("4 Hexadecimal conversion\n");
    printf("5 Exit the program\n\n");

    printf("Select a number (1 - 5):\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        decimal();
        break;
    
    case 2:
        binary();
        break;

    case 3:
        octal();
        break;

    case 4:
        hexadecimal();
        break;

    case 5:
        exitMsg();
        break;
    
    default:
        printf("\n\033[0;31mError: the option must be between 1 to 5\033[0m\n");
        error();
        menu();
        break;
    }
}

char getch() {
    struct termios oldt, newt;
    char c;

    // Guarda configuración actual del terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Desactiva modo canónico y eco
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 1;  // Espera al menos 1 carácter
    newt.c_cc[VTIME] = 0; // Sin tiempo de espera

    // Aplica nueva configuración
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Lee un carácter
    read(STDIN_FILENO, &c, 1);

    // Restaura configuración original
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

void buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void error()
{
    printf("Press to any key to continue...\n");
    getch();
    buffer();
}

void decimal()
{
    int ch;
    char chain[100];

    printf("\n\033[0;34m***** Decimal Conversion *****\033[0m\n");
    printf("Enter the decimal number:\n");
    scanf("%s", chain);

    if (validateDecimal(chain) == 0) 
    {
        printf("\n\033[0;31mError: the number must be a positive integer\033[0m\n");
        error();
        decimal();
    } 
    else
    {
        printf("\n\033[0;32m***** Conversion Results : %s *****\n", chain);
        decimalToBinary(strtol(chain, NULL, 10));
        decimalToOctal(strtol(chain, NULL, 10));
        decimalToHexa(strtol(chain, NULL, 10));
        printf("\033[0m\n");
    }

    printf("\nYou want to convert another number 'y' or 'n': \n");
    buffer();
    ch = getchar();

    switch (ch)
    {
    case 'y':
    case 'Y':
        decimal();
        break;

    case 'n':
    case 'N':
        menu();
        break;
    
    default:
        printf("\n\033[0;31mError: the options are only 'y' or 'n'\033[0m\n");
        error();
        decimal();
        break;
    }
}

int validateDecimal(char *chain)
{
    if (strlen(chain) < 0) return 0;

    for (int i = 0; chain[i] != '\0'; i++)
    {
        if (!isdigit(chain[i])) return 0;
    }

    return 1;
}

void decimalToBinary(long num)
{
    int binary[50], i = 0;

    if (num == 0) 
    {
        printf("\nBinary number: 0");
        return;
    }

    while (num > 0)
    {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
    
    printf("\nBinary number: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
}

void decimalToOctal(long num)
{
    int octal[100], i = 0;

    if (num == 0) 
    {
        printf("\nOctal number: 0\n");
        return;
    }

    while (num != 0)
    {
        octal[i++] = num % 8;
        num = num / 8;
    }

    printf("\nOctal number: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }
}

void decimalToHexa(long num)
{
    char hexa[100];
    int i = 0;

    if (num == 0) 
    {
        printf("\nHexadecimal number: 0\n");
        return;
    }

    while (num != 0) {
        int temp = num % 16;
        if (temp < 10)
        {
            hexa[i++] = temp + 48;
        }
        else 
        {
            hexa[i++] = temp + 55;
        }

        num = num / 16;
    }

    printf("\nHexadecimal number: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexa[j]);
    }
}

void binary()
{
    int ch;
    char chain[100];

    printf("\n\033[0;34m***** Binary Conversion *****\033[0m\n");
    printf("Enter the binary number:\n");
    scanf("%s", chain);

    if (validateBinary(chain) == 0) 
    {
        printf("\n\033[0;31mError: the number must be a binary\033[0m\n");
        error();
        binary();
    } 
    else
    {
        printf("\n\033[0;32m***** Conversion Results : %s *****\n", chain);
        binaryToDecimal(chain);
        binaryToOctal(chain);
        binaryToHexa(chain);
        printf("\033[0m\n");
    }

    printf("\nYou want to convert another number 'y' or 'n': \n");
    buffer();
    ch = getchar();

    switch (ch)
    {
    case 'y':
    case 'Y':
        binary();
        break;

    case 'n':
    case 'N':
        menu();
        break;
    
    default:
        printf("\n\033[0;31mError: the options are only 'y' or 'n'\033[0m\n");
        error();
        binary();
        break;
    }
}

int validateBinary(char *chain)
{
    if (strlen(chain) < 0) return 0;

    for (int i = 0; chain[i] != '\0'; i++)
    {
        if (!isdigit(chain[i])) return 0;

        if (chain[i] != '0' && chain[i] != '1') 
            return 0;           
    }

    return 1;
}

void binaryToDecimal(char *chain)
{
    int decimal = 0;
    int longitud = strlen(chain);
    int base = 1;

    for (int i = longitud - 1; i >= 0; i--)
    {
        if (chain[i] == '1')
            decimal = decimal + base;
        base = base * 2; 
    }

    printf("\nBinary number: %d", decimal);
}

void binaryToOctal(char *chain)
{
    int decimal = 0;
    int longitud = strlen(chain);
    int base = 1;

    for (int i = longitud - 1; i >= 0; i--)
    {
        if (chain[i] == '1')
            decimal = decimal + base;
        base = base * 2; 
    }

    decimalToOctal(decimal);
}

void binaryToHexa(char *chain)
{
    int decimal = 0;
    int longitud = strlen(chain);
    int base = 1;

    for (int i = longitud - 1; i >= 0; i--)
    {
        if (chain[i] == '1')
            decimal = decimal + base;
        base = base * 2; 
    }

    decimalToHexa(decimal);
}

void octal()
{
    int ch;
    char chain[100];

    printf("\n\033[0;34m***** Octal Conversion *****\033[0m\n");
    printf("Enter the octal number:\n");
    scanf("%s", chain);

    if (validateOctal(chain) == 0) 
    {
        printf("\n\033[0;31mError: the number must be a octal\033[0m\n");
        error();
        octal();
    } 
    else
    {
        printf("\n\033[0;32m***** Conversion Results : %s *****\n", chain);
        octalToDecimal(strtol(chain, NULL, 10));
        octalToBinary(strtol(chain, NULL, 10));
        octalToHexa(strtol(chain, NULL, 10));
        printf("\033[0m\n");
    }

    printf("\nYou want to convert another number 'y' or 'n': \n");
    buffer();
    ch = getchar();

    switch (ch)
    {
    case 'y':
    case 'Y':
        octal();
        break;

    case 'n':
    case 'N':
        menu();
        break;
    
    default:
        printf("\n\033[0;31mError: the options are only 'y' or 'n'\033[0m\n");
        error();
        octal();
        break;
    }
}

int validateOctal(char *chain)
{
    if (strlen(chain) < 0) return 0;

    for (int i = 0; chain[i] != '\0'; i++)
    {
        if (!isdigit(chain[i])) return 0;

        if (chain[i] < '0' || chain[i] > '7') 
            return 0;           
    }

    return 1;
}

void octalToDecimal(long num)
{
    int i = 0;
    int decimal = 0;

    while (num != 0)
    {
        int dig = num % 10;
        decimal += dig * pow(8, i);
        num = num / 10;
        i++;      
    }

    printf("\nDecimal number: %d", decimal);
}

void octalToBinary(long num)
{
    int i = 0;
    int decimal = 0;

    while (num != 0)
    {
        int dig = num % 10;
        decimal += dig * pow(8, i);
        num = num / 10;
        i++;      
    }

    decimalToBinary(decimal);
}

void octalToHexa(long num)
{
    int i = 0;
    int decimal = 0;

    while (num != 0)
    {
        int dig = num % 10;
        decimal += dig * pow(8, i);
        num = num / 10;
        i++;      
    }

    decimalToHexa(decimal);
}

void hexadecimal()
{
    int ch;
    char chain[100];

    printf("\n\033[0;34m***** Hexadecimal Conversion *****\033[0m\n");
    printf("Enter the hexadecimal number:\n");
    scanf("%s", chain);

    if (validateHexa(chain) == 0) 
    {
        printf("\n\033[0;31mError: the number must be a hexadecimal\033[0m\n");
        error();
        hexadecimal();
    } 
    else
    {
        printf("\n\033[0;32m***** Conversion Results : %s *****\n", chain);
        hexaToDecimal(chain);
        hexaToBinary(chain);
        hexaToOctal(chain);
        printf("\033[0m\n");
    }

    printf("\nYou want to convert another number 'y' or 'n': \n");
    buffer();
    ch = getchar();

    switch (ch)
    {
    case 'y':
    case 'Y':
        hexadecimal();
        break;

    case 'n':
    case 'N':
        menu();
        break;
    
    default:
        printf("\n\033[0;31mError: the options are only 'y' or 'n'\033[0m\n");
        error();
        hexadecimal();
        break;
    }
}

int validateHexa(char *chain)
{
    if (strlen(chain) < 0) return 0;

    for (int i = 0; chain[i] != '\0'; i++)
    {
        if (!isdigit(chain[i]) && 
            chain[i] < 'A' || chain[i] > 'F') 
            return 0;     
    }

    return 1;
}

int valueHexadecimal(char v)
{
    if (v >= '0' && v <= '9')
        return v - '0';
    else if (v >= 'A' && v <= 'F')
        return v - 'A' + 10;
}

void hexaToDecimal(char *chain)
{
    int decimal = 0;
    int longitud = strlen(chain);

    for (int i = 0; i < longitud; i++) 
    {
        int value = valueHexadecimal(chain[i]);
        decimal = decimal * 16 + value;
    }

    printf("\nDecimal number: %d", decimal);
}

void hexaToBinary(char *chain)
{
    int decimal = 0;
    int longitud = strlen(chain);

    for (int i = 0; i < longitud; i++) 
    {
        int value = valueHexadecimal(chain[i]);
        decimal = decimal * 16 + value;
    }

    decimalToBinary(decimal);
}

void hexaToOctal(char *chain)
{
    int decimal = 0;
    int longitud = strlen(chain);

    for (int i = 0; i < longitud; i++) 
    {
        int value = valueHexadecimal(chain[i]);
        decimal = decimal * 16 + value;
    }

    decimalToOctal(decimal);
}

void exitMsg()
{
    system("clear");
    printf("\n********************************\n");
    printf("*****    Closed Program    *****\n");
    printf("********************************\n");
}
