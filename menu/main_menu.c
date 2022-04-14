/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_menu
*/

#include "../include/my_defender.h"

void menu_func(my_defender_h *defd)
{
    for (int i = 0; defd->menu->btn[i] != NULL; i++) {
        hover_button(defd, defd->menu->btn[i]);
    }
}

void main_menu(my_defender_h *defd)
{
    while (sfRenderWindow_isOpen(defd->wind->window)) {
        sfRenderWindow_clear(defd->wind->window, sfBlack);
        while (sfRenderWindow_pollEvent(defd->wind->window,
        &defd->wind->event)) {
            analyse_events(defd);
        }
        menu_func(defd);
        if (defd->menu->btn[0]->pressed == 1)
            break;
        menu_display(defd->menu, defd->wind->window);
        sfRenderWindow_display(defd->wind->window);
    }
}
