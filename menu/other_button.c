/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** other_button
*/

#include "../include/my_defender.h"

void init_other_button(menu_h *menu, int height, int width)
{
    int w_mid = width / 2;
    int h_mid = height / 2;
    menu->btn[7] = malloc(sizeof(button_h));
    menu->btn[7]->button_id = 'h';
    init_button(menu->btn[7],
    (sfVector2f){w_mid + 200, h_mid + 100}, (sfVector2f){200, 100},
    "Rules");
    menu->btn[8] = NULL;
    for (int i = 3; menu->btn[i] != NULL; i++)
        menu->btn[i]->visible = 0;
}

void htp_switch(my_defender_h *defd)
{
    if (defd->menu->htp_bool == sfTrue)
        defd->menu->htp_bool = sfFalse;
    else
        defd->menu->htp_bool = sfTrue;
}
