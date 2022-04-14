/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** move_mob
*/

#include "../include/my_defender.h"

void follow_path(struct enemy_t *tmp)
{
    tmp->enemy->coord = sfSprite_getPosition(tmp->enemy->sprt);
    if (tmp->enemy->coord.x <= 350 && tmp->enemy->coord.y <= 700) {
        sfSprite_move(tmp->enemy->sprt, (sfVector2f){0, 5});
        return;
    }
    if (tmp->enemy->coord.y <= 800 && tmp->enemy->coord.y >= 700
    && tmp->enemy->coord.x <= 1300) {
        sfSprite_move(tmp->enemy->sprt, (sfVector2f){5, 0});
        tmp->enemy->coord = sfSprite_getPosition(tmp->enemy->sprt);
        return;
    }
    if (tmp->enemy->coord.x >= 1300 && tmp->enemy->coord.y >= 300) {
        tmp->enemy->coord = sfSprite_getPosition(tmp->enemy->sprt);
        sfSprite_move(tmp->enemy->sprt, (sfVector2f){0, -5});
    }
    else
        sfSprite_move(tmp->enemy->sprt, (sfVector2f){5, 0});
}

void move_mob(game_h *game)
{
    struct enemy_t *tmp = game->enemy;
    game->ene_clock->time = sfClock_getElapsedTime(game->ene_clock->clock);
    if (sfTime_asMilliseconds(game->ene_clock->time) >= 25) {
        for (; tmp != NULL; tmp = tmp->next)
            follow_path(tmp);
        sfClock_restart(game->ene_clock->clock);
    }
}
