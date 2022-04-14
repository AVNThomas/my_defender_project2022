/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** option_menu
*/

#include "../include/my_defender.h"

void init_option_button(menu_h *menu, int height, int width)
{
    int w_mid = width / 2;
    int h_mid = height / 2;
    menu->btn[3] = malloc(sizeof(button_h));
    menu->btn[3]->button_id = 'f';
    init_button(menu->btn[3],
    (sfVector2f){w_mid + 200, h_mid - 300}, (sfVector2f){200, 100}, "sound");
    menu->btn[4] = malloc(sizeof(button_h));
    menu->btn[4]->button_id = '8';
    init_button(menu->btn[4],
    (sfVector2f){w_mid + 200, h_mid - 100}, (sfVector2f){200, 100},
    "sound lvl");
    menu->btn[5] = malloc(sizeof(button_h));
    menu->btn[5]->button_id = 'u';
    init_button(menu->btn[5],
    (sfVector2f){w_mid + 50, h_mid - 75}, (sfVector2f){100, 50}, "up");
    menu->btn[6] = malloc(sizeof(button_h));
    menu->btn[6]->button_id = 'd';
    init_button(menu->btn[6],
    (sfVector2f){w_mid + 450, h_mid - 75}, (sfVector2f){100, 50}, "down");
    init_other_button(menu, height, width);
}

void sound_switch(my_defender_h *defd)
{
    if (defd->wind->sound == 1) {
        sfText_setFillColor(defd->menu->btn[3]->text,
        (sfColor) {255, 0, 0, 255});
        sfMusic_setVolume(defd->wind->music, 0);
        defd->wind->sound = 0;
    }
    else {
        sfText_setFillColor(defd->menu->btn[3]->text,
        (sfColor){255, 255, 255, 255});
        sfMusic_setVolume(defd->wind->music, defd->wind->sound_level);
        defd->wind->sound = 1;
    }
}

void sound_down(my_defender_h *defd)
{
    if (defd->wind->sound_level > 0) {
        defd->wind->sound_level -= 5;
        if (defd->wind->sound == 1)
            sfMusic_setVolume(defd->wind->music, defd->wind->sound_level);
    }
}

void sound_up(my_defender_h *defd)
{
    if (defd->wind->sound_level < 100) {
        defd->wind->sound_level += 5;
        if (defd->wind->sound == 1)
            sfMusic_setVolume(defd->wind->music, defd->wind->sound_level);
    }
}
