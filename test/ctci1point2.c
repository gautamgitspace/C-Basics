//
//  main.c
//  CTCI 1.2
//
//  Created by Gautam on 1/17/16.
//  Copyright © 2016 Gautam. All rights reserved.
//


#include<stdlib.h>
#include<string.h>


void reverse(char *str)     //*str points to arr[0]
{
    char *end  = str;       //end points to opal, *end is 'o'
    char tmp;
    if (str)
    {              //check if string is not null
        while (*end)
            ++end;
    }
    --end; /* end pointer points to l now */
    
    while (str<end) //swaps until the pointers meet in the middle
    {
        tmp = *str; /* tmp = o */
        
        *str++ = *end;
        
        *end-- = tmp;
    }printf("%s\n", str);
    
}

int main()
{
    char arr[]="abcde";
    reverse(arr);
}