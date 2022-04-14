/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** button_fonction
*/

#include "../include/my_defender.h"

void play_button(my_defender_h *defd)
{
    defd->menu->btn[0]->pressed = 1;
}

void quit_button(my_defender_h *defd)
{
    defd->menu->btn[1]->pressed = 1;
}

void option_button(my_defender_h *defd)
{
    for (int i = 3; defd->menu->btn[i] != NULL; i++) {
        if (defd->menu->btn[i]->visible == sfTrue)
            defd->menu->btn[i]->visible = sfFalse;
        else
            defd->menu->btn[i]->visible = sfTrue;
    }
}

void hover_button(my_defender_h *defd, button_h *but)
{
    sfVector2i mouse_pos_i =
    sfMouse_getPositionRenderWindow(defd->wind->window);
    sfVector2f pos;
    pos.x = mouse_pos_i.x;
    pos.y = mouse_pos_i.y;
    if ((pos.x >= but->position.x && pos.x <= but->size.x + but->position.x) &&
    (pos.y >= but->position.y && pos.y <= but->size.y + but->position.y)) {
        sfRectangleShape_setFillColor(but->rect,
        (sfColor){20, 100, 255, 255});
        if (defd->menu->mouse_pressed == 1)
            sfRectangleShape_setFillColor(but->rect,
            (sfColor){120, 129, 165, 255});
    }
    else {
        sfRectangleShape_setFillColor(but->rect, (sfColor){9, 129, 165, 255});
    }
}
