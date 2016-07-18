//
//  main.c
//  test
//
//  Created by Gautam on 1/6/16.
//  Copyright © 2016 Gautam. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void calSpaces()
{
    char s[100], *str;
    int space=0;
    printf("Enter a string to calculate spaces:\n");
    gets(s);
    str=s;
    for(space=0; *str; str++)
    {
        if(*str != ' ')continue;
        space++;
    }
    printf("Spaces = %d\n",space);
}

void calCharacters()
{
    int characters=0;
    char s[100], *str;
    printf("Enter a string to calculate characters: ");
    gets(s);
    str=s;
    for(characters=0; *str; str++)
    {
        if(*str!=' ')characters++;
    }
    printf("Characters = %d\n",characters);
}

int main()
{
    calSpaces();
    calCharacters();
}
