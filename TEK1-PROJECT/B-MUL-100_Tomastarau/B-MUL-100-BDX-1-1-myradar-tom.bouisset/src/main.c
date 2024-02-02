/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
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

int main(int argc, char *argv[])
{
    srand(time(NULL));
    sfRenderWindow *window = createmywindow(1920, 1080, 32, "My radar");
    sfEvent event;
    int i = 0;
    int iteration = 5000;
    sfCircleShape *circle_tab[5000] = {0};
    sfVector2f pos_circle = {rand() % 1920, rand() % 1080};
    sfVector2f pos_circle1 = {rand() % 1920, rand() % 1080};

    while (i <= iteration){
        circle_tab[i] = create_circle(pos_circle, 25.0);
        circle_tab[i + 1] = create_circle(pos_circle1, 25.0);
        pos_circle.x = rand() % 1800;
        pos_circle.y = rand() % 1000;
        pos_circle1.x = rand() % 1800;
        pos_circle1.y = rand() % 1000;
        i = i + 2;
    }
    i = 0;
    while (sfRenderWindow_isOpen(window)){
        sfRenderWindow_clear(window, sfWhite);
        while (i < iteration){
            is_intersecting_circles(circle_tab[i], circle_tab[i + 1]);
            sfRenderWindow_drawCircleShape(window, circle_tab[i], NULL);
            sfRenderWindow_drawCircleShape(window, circle_tab[i + 1], NULL);
            analyse_events(window, event);
            i++;
            sfRenderWindow_display(window);
        }
        analyse_events(window, event);
    }
    i = 0;
    while (i < iteration){
        sfCircleShape_destroy(circle_tab[i]);
        i++;
    }
    return 1;
}
