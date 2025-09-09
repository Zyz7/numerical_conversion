#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <ctype.h>
#include <string.h>

char getch(); 
void buffer();
void error();
void menu();
void decimal();
int validateDecimal(char *);
void decimalToBinary(long);
void decimalToOctal(long);
void exitMsg();

// https://github.com/Alkaison/Number-System-Converter/blob/main/Code%20Files/Number-System-Converter.c

int main() 
{    
    menu();
    return 0;
}

void menu() 
{
    int number;

    system("clear");

    printf("\n\033[0;34m********************************\n");
    printf("***** Numerical Conversion *****\n");
    printf("********************************\033[0m\n\n");

    printf("Select conversion type:\n");
    printf("1 Decimal conversion\n");
    printf("2 Binary conversion\n");
    printf("3 Octal conversion\n");
    printf("4 Hexadecimal conversion\n");
    printf("5 Exit the program\n\n");

    printf("Select a number:\n");
    scanf("%d", &number);

    switch (number)
    {
    case 1:
        decimal();
        break;
    
    case 2:
        printf("Press 2\n");
        break;

    case 3:
        printf("Press 3\n");
        break;

    case 4:
        printf("Press 4\n");
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
        printf("\n\033[0;32m***** Conversion Results *****\033[0m\n");
        decimalToBinary(strtol(chain, NULL, 10));
        decimalToOctal(strtol(chain, NULL, 10));
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
        menu();
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
    printf("\n");
}

void exitMsg()
{
    system("clear");
    printf("\n********************************\n");
    printf("*****    Closed Program    *****\n");
    printf("********************************\n");
}
