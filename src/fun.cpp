// Copyright 2022 UNN-IASR
#include <ctype.h>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include "fun.h"


unsigned int faStr1(const char* str)
{
    bool InWord=false;
    int CountOfWords = 0;//count of words
    int COWWOD = 0;//count of words without digits
    int i = 0;
    while (str[i])
    {
        if (InWord == false && str[i] != ' ')
        {
            int COL = i; //position of machine 
            int COLWD=i; //position of machine without digits
            CountOfWords += 1;
            InWord = true;
            while (str[COL] != ' ' && str[COL]!='\0')
            {
                if (isalpha(str[COL]))
                {
                    COLWD += 1;
                }
                COL++;
            }
            if (COL == COLWD)
            {
                COWWOD++;
            }
        }
        else
        {
            if (InWord == true && str[i] == ' ')
            {
                InWord = false;
            }
        }
        i++;
    }
    return COWWOD;
}

unsigned int faStr2(const char* str) 
{
    int i = 0;
    int CountOfWords = 0;
    int COWA = 0;//Count of words accepted
    bool InWord = false;
    bool IsAccepted = false;
    while (str[i])
    {
        if (InWord == false && str[i] != ' ')
        {
            if ('A' <= str[i] && str[i] <= 'Z')
            {
                IsAccepted = true;
            }
            int COL = i+1; //position of machine after ZAGLAVNAYA
            CountOfWords += 1;
            InWord = true;
            while (str[COL] != ' ' && str[COL] != '\0' && IsAccepted)
            {
                if ('a' <= str[COL] && str[COL] <= 'z')
                {
                   
                }
                else
                {
                    IsAccepted=false;
                }
                COL++;
            }
            if (IsAccepted)
            {
                COWA++;
                IsAccepted = false;
            }
        }
        else
        {
            if (InWord == true && str[i] == ' ')
            {
                InWord = false;
                IsAccepted = false;
            }
        }
        i++;

    }
    return COWA;
   // if (('A' <= str[COL] && str[COL] <= 'Z')
}

unsigned int faStr3(const char* str) 
{
    int i = 0;
    double CS = 0;//CountSymbols
    int CountOfWords = 0;
    int COWA = 0;//Count of words accepted
    int answer = 0;
    bool InWord = false;
    while (str[i])
    {
        if (InWord == false && str[i] != ' ')
        {
            int COL = i ; //position of machine 
            CountOfWords += 1;
            InWord = true;
            while (str[COL] != ' ' && str[COL] != '\0')
            {
                COL++;
            }  
            CS += COL - i;
        }
        else
        {
            if (InWord == true && str[i] == ' ')
            {
                InWord = false;

            }
        }
        i++;

    }
    answer = round(CS / CountOfWords);
    return answer;
    // if (('A' <= str[COL] && str[COL] <= 'Z')
}
