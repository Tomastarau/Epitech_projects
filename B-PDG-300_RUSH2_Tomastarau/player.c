/*
** EPITECH PROJECT, 2024
** player c header
** File description:
** player
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "player.h"
#include "struct.h"


static void player_creator(PlayerClass *this, va_list *args)
{
    (void)args;
    this->identifier = strdup("Kreog");
    this->power = rand() % 42;
    printf("Player()\n");
}

static void player_destructor(PlayerClass *this)
{
    free(this->identifier);
    free(this);
    printf("~Player()\n");
}

static const PlayerClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PlayerClass),
        .__name__ = "Player",
        .__ctor__ = (ctor_t)&player_creator,
        .__dtor__ = (dtor_t)&player_destructor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .identifier = NULL,
    .power = -1
};

const Class *Player = (const Class *)&_description;
