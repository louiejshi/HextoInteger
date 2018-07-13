// C Programming
//
//  Convert a hexadecimal number (0xABCD or ABCD) to its respective integer
//
//
//  Exercise_2-3
//
//  Created by Louie Shi on 7/12/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 1000

int htoi(char str[])
{
    int i = 0;
    double power = 0.0;
    int length = 0;
    int sum = 0;
    int digit = 0;
    
    if(str[i] == '0')           //Case starting with 0X
    {
        i++;
        if(str[i] == 'x' || str[i] == 'X')
        {
            i++;
            length = strlen(str) - 2;
            for(int j = length - 1 + 2; j >= 2; j--)
            {
                if(str[j] >= '0' && str[j] <= '9')
                {
                    digit = str[j] - '0';
                }
                else if(str[j] >= 'a' && str[j] <= 'f')
                {
                    digit = str[j] - 'a' + 10;
                }
                else if(str[j] >= 'A' && str[j] <= 'F')
                {
                    digit = str[j] - 'A' + 10;
                }
                
                sum = sum + (digit * (pow(16.0,power)));
                power++;
            }
        }
    }
    else                        //Case without 0X
    {
        length = strlen(str);
        for(int j = length - 1; j >= 0; j--)
        {
            if(str[j] >= '0' && str[j] <= '9')
            {
                digit = str[j] - '0';
            }
            else if(str[j] >= 'a' && str[j] <= 'f')
            {
                digit = str[j] - 'a' + 10;
            }
            else if(str[j] >= 'A' && str[j] <= 'F')
            {
                digit = str[j] - 'A' + 10;
            }
            
            sum = sum + (digit * (pow(16.0,power)));
            power++;
        }
    }
    
    return sum;
}

int main(int argc, const char * argv[])
{
    char number[MAXSIZE] = "0xB9CD";
    char number1[MAXSIZE] = "B9CD";
    

    int result = htoi(number);
    int result1 = htoi(number1);

    printf("The integer value of the hexadecimal %s is: %d \n", number, result);
    printf("The integer value of the hexadecimal %s is: %d \n", number1, result1);
    
    return 0;
}
