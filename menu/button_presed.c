/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** button_presed
*/

#include "../include/my_defender.h"

static button_fct_h button_tab[8] = {
    {'a', play_button},
    {'b', quit_button},
    {'c', option_button},
    {'f', sound_switch},
    {'u', sound_up},
    {'d', sound_down},
    {'h', htp_switch},
    {0, NULL},
};

char check_button_pressed(my_defender_h *defd, button_h *but)
{
    sfVector2i mouse_pos_i =
    sfMouse_getPositionRenderWindow(defd->wind->window);
    sfVector2f pos;
    pos.x = mouse_pos_i.x;
    pos.y = mouse_pos_i.y;
    if ((pos.x >= but->position.x && pos.x <= but->size.x + but->position.x) &&
    (pos.y >= but->position.y && pos.y <= but->size.y + but->position.y)) {
        return (but->button_id);
    }
    return (0);
}

void find_flag(my_defender_h *defd, char tmp)
{
    for (int i = 0; button_tab[i].button != 0; i++)
        if (button_tab[i].button == tmp)
            button_tab[i].ptr_fct(defd);
}

void check_button(my_defender_h *defd)
{
    char tmp = 0;
    for (int i = 0; defd->menu->btn[i]; i++) {
        if (defd->menu->btn[i]->visible == sfFalse)
            continue;
        tmp = check_button_pressed(defd, defd->menu->btn[i]);
        if (tmp != 0)
            find_flag(defd, tmp);
    }
}

void analyse_events(my_defender_h *defd)
{
    if (defd->wind->event.type == sfEvtClosed ||
    defd->menu->btn[1]->pressed == 1)
                sfRenderWindow_close(defd->wind->window);
    if (defd->wind->event.type == sfEvtMouseButtonPressed) {
        defd->menu->mouse_pressed = 1;
        sfSound_play(defd->menu->click_sound);
        check_button(defd);
    }
    else
        defd->menu->mouse_pressed = 0;
}
