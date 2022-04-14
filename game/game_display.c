/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** game_display
*/

#include "../include/my_defender.h"

void display_mob(game_h *game, sfRenderWindow *wind)
{
    struct enemy_t *tmp = game->enemy;
    for (; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(wind, tmp->enemy->sprt, NULL);
    }
}

void display_tower(game_h *game, sfRenderWindow *wind)
{
    struct tower_t *tmp = game->tower;
    for (; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(wind, tmp->tower->sprt, NULL);
    }
}

void game_display(game_h *game, sfRenderWindow *wind)
{
    sfRenderWindow_drawSprite(wind, game->background->sprt, NULL);
    display_mob(game, wind);
    display_tower(game, wind);
    if (game->button[3]->visible == sfTrue)
        sfRenderWindow_drawRectangleShape(wind, game-> pause_back, NULL);
    for (int i = 0; game->button[i] != NULL; i++) {
        if (game->button[i]->visible == sfTrue)
            sfRenderWindow_drawSprite(wind, game->button[i]->sprt, NULL);
    }
}
