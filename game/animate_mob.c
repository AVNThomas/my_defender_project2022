/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-samuel.ludmann
** File description:
** animate_mob
*/

#include "../include/my_defender.h"

void walk_mob(struct enemy_t *tmp)
{
    tmp->enemy->rect.left += 24;
    if (tmp->enemy->rect.left >= 144)
        tmp->enemy->rect.left = 72;
    sfSprite_setTextureRect(tmp->enemy->sprt, tmp->enemy->rect);
}

void animate_mob(game_h *game)
{
    struct enemy_t *tmp = game->enemy;
    game->ene_animation->time =
    sfClock_getElapsedTime(game->ene_animation->clock);
    if (sfTime_asMilliseconds(game->ene_animation->time) >= 100) {
        for (; tmp != NULL; tmp = tmp->next)
            walk_mob(tmp);
        sfClock_restart(game->ene_animation->clock);
    }

}
