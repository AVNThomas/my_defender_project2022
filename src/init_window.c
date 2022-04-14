/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** init_window
*/

#include "../include/my_defender.h"

void init_window(my_defender_h *defd)
{
    defd->wind->video_mode.width = 1980;
    defd->wind->video_mode.height = 1050;
    defd->wind->video_mode.bitsPerPixel = 32;
    defd->wind->window =
    sfRenderWindow_create(defd->wind->video_mode, "defender",
    sfClose, NULL);
    defd->wind->sound_level = 50;
    defd->wind->music = sfMusic_createFromFile("asset/inter.ogg");
    sfMusic_setVolume(defd->wind->music, defd->wind->sound_level);
    sfMusic_play(defd->wind->music);
    defd->wind->sound = 1;
}
