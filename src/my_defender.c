/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#include "../include/my_defender.h"

void init(my_defender_h *defd)
{
    init_window(defd);
    init_menu(defd->menu, defd->wind->video_mode.height,
    defd->wind->video_mode.width);
    game_init(defd);
}

int main(int ac, char **av)
{
    my_defender_h *defd = malloc(sizeof(my_defender_h));
    defd->menu = malloc(sizeof(menu_h));
    defd->wind = malloc(sizeof(window_h));
    init(defd);
    while (sfRenderWindow_isOpen(defd->wind->window)) {
        main_menu(defd);
        reset_menu(defd->menu);
        game_loop(defd);
    }
    sfMusic_stop(defd->wind->music);
}
