/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** pause_menu
*/

#include "../include/my_defender.h"

void pause_menu(my_defender_h *defd)
{
    if (defd->game->pause == sfFalse) {
        defd->game->pause = sfTrue;
        defd->game->button[2]->visible = sfTrue;
        defd->game->button[3]->visible = sfTrue;
        defd->game->button[4]->visible = sfTrue;
    }
    else {
        defd->game->pause = sfFalse;
        defd->game->button[2]->visible = sfFalse;
        defd->game->button[3]->visible = sfFalse;
        defd->game->button[4]->visible = sfFalse;
    }
}

void reset_clock(game_h *game)
{
    if (game->pause == sfTrue) {
        sfClock_restart(game->ene_clock->clock);
        sfClock_restart(game->ene_animation->clock);
    }
}

void quit_game(my_defender_h *defd)
{
    sfRenderWindow_close(defd->wind->window);
}

void go_to_menu(my_defender_h *defd)
{
    defd->game->button[3]->pressed = 1;
}
