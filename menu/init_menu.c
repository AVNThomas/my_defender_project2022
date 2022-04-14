/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** init_menu
*/

#include "../include/my_defender.h"

static void init_text(button_h *btn, sfVector2f pos, sfVector2f siz, char *txt)
{
    sfVector2f txt_pos;
    txt_pos.x = pos.x + siz.x / my_strlen(txt);
    txt_pos.y = pos.y - siz.y / 2;
    sfFont *font = sfFont_createFromFile("menu/game_over.ttf");
    btn->text = sfText_create();
    sfText_setString(btn->text, txt);
    sfText_setColor(btn->text, sfWhite);
    sfText_setPosition(btn->text, txt_pos);
    sfText_setFont(btn->text, font);
    sfText_setCharacterSize(btn->text, siz.y);
}

void init_button(button_h *button, sfVector2f pos, sfVector2f size, char *txt)
{
    button->position = pos;
    button->size = size;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, button->position);
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setOutlineColor(button->rect,
    (sfColor){15, 70, 120, 255});
    sfRectangleShape_setOutlineThickness(button->rect, 5);
    sfRectangleShape_setFillColor(button->rect, (sfColor){9, 129, 165, 255});
    init_text(button, pos, size, txt);
    button->visible = sfTrue;
    button->pressed = 0;
}

/*
// les seul truc que tu peux modifier içi sont les couleur et la taille
// des bordures.
//
// sfRectangleShape_setOutlineThickness(button->rect, 2);
// sfRectangleShape_setFillColor(button->rect, sfBlue);
// sfRectangleShape_setOutlineColor(button->rect, sfRed);
//
*/

void init_all_button(menu_h *menu, int height, int width)
{
    int w_mid = width / 2;
    int h_mid = height / 2;
    menu->btn[0] = malloc(sizeof(button_h));
    menu->btn[0]->button_id = 'a';
    init_button(menu->btn[0],
    (sfVector2f){w_mid - 600, h_mid - 400}, (sfVector2f){250, 150}, "Play");
    menu->btn[1] = malloc(sizeof(button_h));
    menu->btn[1]->button_id = 'b';
    init_button(menu->btn[1],
    (sfVector2f){w_mid - 600, h_mid + 200}, (sfVector2f){250, 150}, "Quit");
    menu->btn[2] = malloc(sizeof(button_h));
    menu->btn[2]->button_id = 'c';
    init_button(menu->btn[2],
    (sfVector2f){w_mid - 600, h_mid - 100}, (sfVector2f){250, 150}, "Option");
}

/*
// pour ajouter un nouveau bouton il faut mettre les lignes de code ci dessuous
// menu->button[la case du bouton] = malloc(sizeof(button_h));
// menu->btn[case du bouton]->button_id = 'id';
// init_button(menu->btn[case du bouton],
// (sfVector2f){position}, (sfVector2f){taille});
// il faut remplacer "la case du bouton", "id", "position", "taille"
*/

void reset_menu(menu_h *menu)
{
    for (int i = 0; menu->btn[i]; i++)
        menu->btn[i]->pressed = 0;
}

void init_menu(menu_h *menu, int height, int width)
{
    sfTexture *texture = sfTexture_createFromFile("asset/menu_fond.jpg", NULL);
    sfTexture *txt = sfTexture_createFromFile("asset/how_to_play.png", NULL);
    menu->sprite = sfSprite_create();
    menu->htp = sfSprite_create();
    sfSprite_setTexture(menu->sprite, texture, sfTrue);
    sfSprite_setTexture(menu->htp, txt, sfTrue);
    sfSprite_scale(menu->sprite, (sfVector2f){2, 2});
    sfSprite_scale(menu->htp, (sfVector2f){2, 2});
    sfSprite_setPosition(menu->htp, (sfVector2f){500, 200});
    menu->click_sound = sfSound_create();
    menu->click_buff = sfSoundBuffer_createFromFile("asset/Chicken_plop.ogx");
    sfSound_setBuffer(menu->click_sound, menu->click_buff);
    menu->htp_bool = sfFalse;
    sfSound_setVolume(menu->click_sound, 50);
    init_all_button(menu, height, width);
    init_option_button(menu, height, width);
}
