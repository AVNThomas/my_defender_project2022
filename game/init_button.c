/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** init_button
*/

#include "../include/my_defender.h"

static void init_button_sprite(gbutton_h *btn
, sfVector2f pos, sfVector2f siz, char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    btn->sprt = sfSprite_create();
    sfSprite_setTexture(btn->sprt, texture, sfTrue);
    sfSprite_setPosition(btn->sprt, pos);
    sfSprite_scale(btn->sprt, (sfVector2f){0.5, 0.5});
}

void init_game_button(gbutton_h *button
, sfVector2f pos, sfVector2f size, char *path)
{
    button->pos = pos;
    button->size = size;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setOutlineColor(button->rect,
    (sfColor){15, 70, 120, 255});
    init_button_sprite(button, pos, size, path);
    sfRectangleShape_setOutlineThickness(button->rect, 5);
    sfRectangleShape_setFillColor(button->rect, (sfColor){9, 129, 165, 255});
    button->visible = sfTrue;
    button->pressed = 0;
}

void place_button(game_h *game)
{
    game->button[0] = malloc(sizeof(gbutton_h));
    game->button[0]->button_id = 'a';
    init_game_button(game->button[0],
    (sfVector2f){500, 500}, (sfVector2f){130, 130},
    "asset/tower/aoe_tow.png");
    game->button[1] = malloc(sizeof(gbutton_h));
    game->button[1]->button_id = 'b';
    init_game_button(game->button[1],
    (sfVector2f){700, 500}, (sfVector2f){130, 130},
    "asset/tower/slo_tow.png");
    pause_button(game);
    game->button[5] = NULL;
}
