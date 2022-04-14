/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "game.h"

typedef struct window_t
{
    sfMusic *music;
    float sound_level;
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfEvent event;
    sfBool sound;
}window_h;

typedef struct my_defender_t
{
    window_h *wind;
    menu_h *menu;
    game_h *game;
}my_defender_h;

typedef struct BUTTON_FCT
{
    char button;
    void(*ptr_fct)(my_defender_h *);
} button_fct_h;

void menu_display(menu_h *menu, sfRenderWindow *wind);
void hover_button(my_defender_h *defd, button_h *but);
void init_window(my_defender_h *defd);
void main_menu(my_defender_h *defd);
void init_menu(menu_h *menu, int height, int width);
void init_button(button_h *button, sfVector2f pos, sfVector2f size, char *txt);
void analyse_events(my_defender_h *defd);
void play_button(my_defender_h *defd);
void quit_button(my_defender_h *defd);
void reset_menu(menu_h *menu);
void init_option_button(menu_h *menu, int height, int width);
void sound_switch(my_defender_h *defd);
void option_button(my_defender_h *defd);
int my_strlen(char *str);
void init_other_button(menu_h *menu, int height, int width);
void sound_down(my_defender_h *defd);
void sound_up(my_defender_h *defd);
char *my_itos(int i);
void htp_switch(my_defender_h *defd);
void game_display(game_h *game, sfRenderWindow *wind);
void game_init(my_defender_h *defd);
void game_loop(my_defender_h *defd);
void place_button(game_h *game);
char check_gbutton_pressed(my_defender_h *defd, gbutton_h *but);
void spawn_mob(my_defender_h *defd);
void check_gbutton(my_defender_h *defd);
void check_alive_mob(game_h *game);
void kill_last_mob(my_defender_h *defd);
void move_mob(game_h *game);
void reset_clock(game_h *game);
char check_button_pressed(my_defender_h *defd, button_h *but);
void pause_menu(my_defender_h *defd);
void quit_game(my_defender_h *defd);
void go_to_menu(my_defender_h *defd);
void reset_game(my_defender_h *defd);
void pause_button(game_h *game);
void init_game_button(gbutton_h *button
, sfVector2f pos, sfVector2f size, char *path);
void spawn_tower(my_defender_h *defd);
void init_shop(game_h *defd);
void animate_mob(game_h *game);
