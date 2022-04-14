/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** game_init
*/

#include "../include/my_defender.h"

void init_background(object_h *backg)
{
    backg->txt = sfTexture_createFromFile("asset/map.jpg", NULL);
    backg->sprt = sfSprite_create();
    sfSprite_setTexture(backg->sprt, backg->txt, sfTrue);
    sfSprite_scale(backg->sprt, (sfVector2f){1, 0.7});
}

void game_init(my_defender_h *defd)
{
    defd->game = malloc(sizeof(game_h));
    defd->game->enemy = NULL;
    defd->game->tower = NULL;
    defd->game->pause = sfFalse;
    defd->game->pause_back = sfRectangleShape_create();
    sfRectangleShape_setSize(defd->game->pause_back, (sfVector2f){2000, 1100});
    sfRectangleShape_setFillColor(defd->game->pause_back,
    (sfColor){0, 0, 0, 100});
    defd->game->hurt_sound = sfSound_create();
    defd->game->hurtbuff =
    sfSoundBuffer_createFromFile("asset/Villager_hurt1.ogx");
    sfSound_setBuffer(defd->game->hurt_sound, defd->game->hurtbuff);
    sfSound_setVolume(defd->game->hurt_sound, defd->wind->sound_level);
    defd->game->background = malloc(sizeof(object_h));
    defd->game->ene_clock = malloc(sizeof(clock_h));
    defd->game->ene_animation = malloc(sizeof(clock_h));
    defd->game->ene_clock->clock = sfClock_create();
    defd->game->ene_animation->clock = sfClock_create();
    init_background(defd->game->background);
    place_button(defd->game);
}
