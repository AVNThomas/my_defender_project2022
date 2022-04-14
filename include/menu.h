/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** menu
*/

#pragma once

#include "my_defender.h"

typedef struct button_t
{
    sfRectangleShape *rect;
    sfText *text;
    sfVector2f position;
    sfVector2f size;
    int button_id;
    int pressed;
    sfBool visible;
}button_h;

typedef struct menu_t
{
    button_h *btn[10];
    sfSprite *sprite;
    sfSprite *htp;
    sfSound *click_sound;
    sfSoundBuffer *click_buff;
    sfBool htp_bool;
    sfBool mouse_pressed;
}menu_h;
