/*
** EPITECH PROJECT, 2022
** check if circle are intersecting
** File description:
** check circles if intersecting
*/
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include "my_radar.h"
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>

int is_intersecting_circles (sfCircleShape *c1, sfCircleShape *c2)
{
    float pos_c1_x = sfCircleShape_getPosition(c1).x;
    float pos_c1_y = sfCircleShape_getPosition(c1).y;
    float pos_c2_x = sfCircleShape_getPosition(c2).x;
    float pos_c2_y = sfCircleShape_getPosition(c2).y;
    sfVector2f center_c1 = {(pos_c1_x + sfCircleShape_getRadius(c1)), (pos_c1_y + sfCircleShape_getRadius(c1))};
    sfVector2f center_c2 = {(pos_c2_x + sfCircleShape_getRadius(c2)), (pos_c2_y + sfCircleShape_getRadius(c2))};
    //(Cx - Dx)² + (Cy - Dy)² <= (Cr + Dr)² == 1
    float resultat = ((((pos_c1_x - pos_c2_x) * (pos_c1_x - pos_c2_x)) + ((pos_c1_y - pos_c2_y) * (pos_c1_y - pos_c2_y))));
    float radius = ((sfCircleShape_getRadius(c1) + sfCircleShape_getRadius(c2)) * (sfCircleShape_getRadius(c1) + sfCircleShape_getRadius(c2)));
    if (resultat <= radius){
        sfCircleShape_setFillColor(c1, sfBlack);
        sfCircleShape_setFillColor(c2, sfBlack);
    }
}