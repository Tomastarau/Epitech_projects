/*
** EPITECH PROJECT, 2023
** get_speed_and_degree
** File description:
** calcul the speed and the degree of rotation for turning
*/

#include "n4s.h"

float get_speed(data_lidar_t lidar)
{
    if (lidar.lidar_left <= 260 ||
    lidar.lidar_right <= 260) {
        fprintf(stderr, "\ntest\n");
        return 0.04;
    }
    if (lidar.lidar_front >= 1750 && lidar.lidar_left >= 450 && \
lidar.lidar_right > 450)
        return 1.0;
    if (lidar.lidar_front >= 1300 && lidar.lidar_left >= 450 && \
lidar.lidar_right > 450)
        return 0.7;
    if (lidar.lidar_front >= 750)
        return 0.5;
    if (lidar.lidar_front >= 400)
        return 0.3;
    if (lidar.lidar_front >= 300)
        return 0.15;
    if (lidar.lidar_front >= 260)
        return 0.05;
    return 0.05;
}

float get_rotation(data_lidar_t lidar)
{
    if (lidar.lidar_left <= 260 ||
    lidar.lidar_right <= 260) {
        fprintf(stderr, "\ntest\n");
        return 0.4;
    }
    if (lidar.lidar_front >= 1500)
        return 0.02;
    if (lidar.lidar_front >= 1000)
        return 0.05;
    if (lidar.lidar_front >= 600)
        return 0.1;
    if (lidar.lidar_front >= 400)
        return 0.2;
    if (lidar.lidar_front >= 260)
        return 0.5;

    return 0.45;
}
