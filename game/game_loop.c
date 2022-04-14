/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** game_loop
*/

#include "../include/my_defender.h"

void analyse_game_events(my_defender_h *defd)
{
    if (defd->wind->event.type == sfEvtClosed)
        sfRenderWindow_close(defd->wind->window);
    if (defd->wind->event.type == sfEvtMouseButtonPressed)
        check_gbutton(defd);
    if (defd->wind->event.key.code == 27)
        pause_menu(defd);
}

void game_func(my_defender_h *defd)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(defd->wind->window);

    defd->game->mouse_pos = (sfVector2f){ mp.x, mp.y };
    reset_clock(defd->game);
    check_alive_mob(defd->game);
    move_mob(defd->game);
    animate_mob(defd->game);
}

void game_loop(my_defender_h *defd)
{
    while (sfRenderWindow_isOpen(defd->wind->window)) {
        sfRenderWindow_clear(defd->wind->window, sfBlack);
        while (sfRenderWindow_pollEvent(defd->wind->window,
        &defd->wind->event)) {
            analyse_game_events(defd);
        }
        if (defd->game->button[3]->pressed == sfTrue)
            break;
        game_func(defd);
        game_display(defd->game, defd->wind->window);
        sfRenderWindow_display(defd->wind->window);
    }
    reset_game(defd);
}
