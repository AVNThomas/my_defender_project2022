/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** tower
*/

#include "../include/my_defender.h"

void tower_init(object_h *tow, int type, sfVector2f pos)
{
    tow->txt =
    sfTexture_createFromFile("asset/tower/attack_tow.png", NULL);
    tow->coord = pos;
    tow->sprt = sfSprite_create();
    sfSprite_setTexture(tow->sprt, tow->txt, sfFalse);
    sfSprite_setPosition(tow->sprt, tow->coord);
    sfSprite_setScale(tow->sprt, (sfVector2f){ .5, .5 });
}

void place_tower(my_defender_h *defd, int type, sfVector2f pos)
{
    struct tower_t *tower;
    tower = malloc(sizeof(enemy_h));
    tower->type = type;
    tower->tower = malloc(sizeof(object_h));
    tower_init(tower->tower, tower->type, pos);
    tower->next = defd->game->tower;
    defd->game->tower = tower;
}

void spawn_tower(my_defender_h *defd)
{
    place_tower(defd, 0,
    (sfVector2f){ defd->game->mouse_pos.x - ((253*0.5) / 2),
    defd->game->mouse_pos.y - ((260*0.5) / 2)});
}
