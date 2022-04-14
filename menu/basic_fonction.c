/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** basic_fonction
*/

#include "../include/my_defender.h"

int my_strlen(char *str)
{
    if (str == NULL)
        return (0);
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

char *my_itos(int i)
{
    int size = 0;
    int itmp = 1;
    char *str;

    for (int tmp = i; tmp >= 10; tmp /= 10)
        size++;
    str = malloc(sizeof(char) * (size + 1));
    for (int i = size; i >= 0; i--) {
        itmp *= 10;
        str[i] = (i % itmp) / (itmp / 10) + '0';
        i =- (i % itmp);
    }
    str[size + 1] = '\0';
    return (str);
}
