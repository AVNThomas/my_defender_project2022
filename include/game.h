/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** game
*/

#pragma once

#include "../include/my_defender.h"

typedef struct clock_t
{
    sfClock *clock;
    sfTime time;
}clock_h;

typedef struct game_button_t
{
    sfRectangleShape *rect;
    sfSprite *sprt;
    sfVector2f pos;
    sfVector2f size;
    int button_id;
    int pressed;
    sfBool visible;
}gbutton_h;

typedef struct object_t
{
    sfSprite *sprt;
    sfTexture *txt;
    sfIntRect rect;
    sfVector2f coord;
}object_h;

typedef struct enemy_t
{
    object_h *enemy;
    int life;
    int armor;
    int type;
    struct enemy_t *next;
}enemy_h;

typedef struct tower_t
{
    object_h *tower;
    int type;
    struct tower_t *next;
}tower_h;

typedef struct placeholder_t
{
    sfRectangleShape *rect;
    sfVector2f position;
}placeholder_h;

typedef struct shop_t
{
    placeholder_h *placeholder;
    sfBool is_building;
}shop_h;

typedef struct game_t
{
    gbutton_h *button[7];
    object_h *background;
    clock_h *ene_clock;
    clock_h *ene_animation;
    sfBool pause;
    sfSound *hurt_sound;
    sfSoundBuffer *hurtbuff;
    sfRectangleShape *pause_back;
    sfVector2f mouse_pos;
    shop_h *shop;
    int money;
    int score;
    struct enemy_t *enemy;
    struct tower_t *tower;
}game_h;
