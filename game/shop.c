/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** shop
*/

#include "../include/my_defender.h"

void init_placeholder(game_h *defd)
{
    defd->shop->placeholder->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(defd->shop->placeholder->rect,
    (sfColor){ 0, 0, 0, .5 });
}

void init_shop(game_h *defd)
{
    defd->shop = malloc(sizeof(shop_h));
    defd->shop->is_building = sfFalse;
    init_placeholder(defd);
}

void toggle_building(game_h *defd)
{
    if (defd->shop->is_building == sfTrue) {
        defd->shop->is_building == sfFalse;
    } else {
        defd->shop->is_building == sfTrue;
    }
}

