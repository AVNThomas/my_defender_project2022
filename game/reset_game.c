/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-samuel.ludmann
** File description:
** reset_game
*/

#include "../include/my_defender.h"

void kill_all_mob(enemy_h *en)
{
    if (en == NULL)
        return;
    enemy_h *ltmp = en->next;
    sfSprite_destroy(en->enemy->sprt);
    free(en);
    if (ltmp == NULL)
        return;
    return (kill_all_mob(ltmp));
}

void reset_game(my_defender_h *defd)
{
    defd->game->button[3]->pressed = sfFalse;
    defd->game->button[2]->visible = sfFalse;
    defd->game->button[3]->visible = sfFalse;
    defd->game->button[4]->visible = sfFalse;
    defd->game->pause = sfFalse;
    kill_all_mob(defd->game->enemy);
    defd->game->enemy = NULL;
}
