/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** button
*/

#include "../include/my_defender.h"

static button_fct_h button_tab[6] = {
    {'a', spawn_mob},
    {'b', kill_last_mob},
    {'c', quit_game},
    {'d', go_to_menu},
    {'e', reset_game},
    {0, NULL},
};

char check_gbutton_pressed(my_defender_h *defd, gbutton_h *but)
{
    sfVector2i mouse_pos_i =
    sfMouse_getPositionRenderWindow(defd->wind->window);
    sfVector2f pos;
    pos.x = mouse_pos_i.x;
    pos.y = mouse_pos_i.y;
    if ((pos.x >= but->pos.x && pos.x <= but->size.x + but->pos.x) &&
    (pos.y >= but->pos.y && pos.y <= but->size.y + but->pos.y))
        return (but->button_id);
    return (0);
}

void find_gflag(my_defender_h *defd, char tmp)
{
    for (int i = 0; button_tab[i].button != 0; i++)
        if (button_tab[i].button == tmp)
            button_tab[i].ptr_fct(defd);
}

void check_gbutton(my_defender_h *defd)
{
    char tmp = 0;
    for (int i = 0; defd->game->button[i]; i++) {
        if (defd->game->button[i]->visible == sfFalse)
            continue;
        tmp = check_gbutton_pressed(defd, defd->game->button[i]);
        if (tmp != 0)
            find_gflag(defd, tmp);
    }
}
