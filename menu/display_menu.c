/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** display_menu
*/

#include "../include/my_defender.h"

void menu_display(menu_h *menu, sfRenderWindow *wind)
{
    sfRenderWindow_drawSprite(wind, menu->sprite, NULL);
    for (int i = 0; menu->btn[i]; i++)
        if (menu->btn[i]->visible == sfTrue) {
            sfRenderWindow_drawRectangleShape(wind, menu->btn[i]->rect, NULL);
            sfRenderWindow_drawText(wind ,menu->btn[i]->text, NULL);
        }
    if (menu->htp_bool == sfTrue) {
        sfRenderWindow_drawSprite(wind, menu->htp, NULL);
    }
}
