/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-samuel.ludmann
** File description:
** pause_button
*/

#include "../include/my_defender.h"

void pause_button(game_h *game)
{
    game->button[2] = malloc(sizeof(gbutton_h));
    game->button[2]->button_id = 'c';
    init_game_button(game->button[2],
    (sfVector2f){820, 700}, (sfVector2f){600, 200},
    "asset/Exit Button.png");
    game->button[3] = malloc(sizeof(gbutton_h));
    game->button[3]->button_id = 'd';
    init_game_button(game->button[3],
    (sfVector2f){820, 450}, (sfVector2f){600, 200},
    "asset/Menu Button.png");
    game->button[4] = malloc(sizeof(gbutton_h));
    game->button[4]->button_id = 'e';
    init_game_button(game->button[4],
    (sfVector2f){820, 200}, (sfVector2f){600, 200},
    "asset/New game Button.png");
    game->button[2]->visible = sfFalse;
    game->button[3]->visible = sfFalse;
    game->button[4]->visible = sfFalse;
}
