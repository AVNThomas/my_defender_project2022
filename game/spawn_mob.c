/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** spawn_mob
*/

#include "../include/my_defender.h"

void mob_init(object_h *ene)
{
    ene->txt =
    sfTexture_createFromFile("asset/sheets/DinoSprites - doux.png", NULL);
    ene->sprt = sfSprite_create();
    ene->rect = (sfIntRect){72, 0, 24, 24};
    sfSprite_setTexture(ene->sprt, ene->txt, sfTrue);
    sfSprite_setTextureRect(ene->sprt, ene->rect);
    sfSprite_scale(ene->sprt, (sfVector2f){4, 4});
    sfSprite_setPosition(ene->sprt, (sfVector2f){300, -20});
}

void spawn_mob(my_defender_h *defd)
{
    struct enemy_t *element;
    element = malloc(sizeof(enemy_h));
    element->armor = 20;
    element->life = 100;
    element->type = 1;
    element->enemy = malloc(sizeof(object_h));
    mob_init(element->enemy);
    element->next = defd->game->enemy;
    defd->game->enemy = element;
}

void kill_last_mob(my_defender_h *defd)
{
    struct enemy_t *tmp = defd->game->enemy;
    if (tmp == NULL)
        return;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->life = 0;
}

void destroy_mod(struct enemy_t *enemy)
{
    struct enemy_t *tmp = enemy->next->next;
    sfTexture_destroy(enemy->next->enemy->txt);
    sfSprite_destroy(enemy->next->enemy->sprt);
    free(enemy->next->enemy);
    free(enemy->next);
    enemy->next = tmp;
}

void check_alive_mob(game_h *game)
{
    struct enemy_t *tmp = game->enemy;
    if (tmp == NULL)
        return;
    if (tmp->next == NULL && tmp->life == 0) {
        sfSound_play(game->hurt_sound);
        sfTexture_destroy(tmp->enemy->txt);
        sfSprite_destroy(tmp->enemy->sprt);
        game->enemy = NULL;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->next->life == 0) {
            sfSound_play(game->hurt_sound);
            destroy_mod(tmp);
            return;
        }
    }
    return;
}
