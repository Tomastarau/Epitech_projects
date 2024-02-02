/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "n4s.h"
#include "structures.h"

static void slow_then_stop(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    FILE *file = fopen(".fifo_n4s", "r");
    char *buf = NULL;
    size_t len = 0;

    printf("CAR_FORWARD:0\n");
    getline(&buf, &len, file);
    printf("CYCLE_WAIT:15\n");
    getline(&buf, &len, file);
    printf("STOP_SIMULATION\n");
    getline(&buf, &len, file);
}

static data_lidar_t lidar_info_right_left_side(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    data_lidar_t data;
    FILE *file = fopen(".fifo_n4s", "r");
    char *buf = NULL;
    size_t len = 0;
    char **lidar = NULL;

    printf("GET_INFO_LIDAR\n");
    getline(&buf, &len, file);
    lidar = my_str_to_word_array_minishell(buf, ':');
    if (strncmp(lidar[35], "Track Cleared", 10) == 0) {
        fprintf(stderr, "Course terminée !\n");
        slow_then_stop();
        data.track_cleared = true;
    } else
        data.track_cleared = false;
    data.lidar_right = atof((const char *)lidar[34]);
    data.lidar_left = atof((const char *)lidar[3]);
    data.lidar_front = atof((const char *)lidar[20]);
    return data;
}

static void loop(char *buf, size_t len, FILE *file)
{
    data_lidar_t lidar;

    while (lidar.track_cleared == false) {
        lidar = lidar_info_right_left_side();
        fprintf(stderr, "L:%f     R:%f     F:%f\n",
        lidar.lidar_left, lidar.lidar_right, lidar.lidar_front);
        if (lidar.lidar_left > lidar.lidar_right) {
            printf("CAR_FORWARD:%f\n", get_speed(lidar));
            getline(&buf, &len, file);
            printf("WHEELS_DIR:%f\n", get_rotation(lidar));
            getline(&buf, &len, file);
        }
        if (lidar.lidar_left < lidar.lidar_right) {
            printf("CAR_FORWARD:%f\n", get_speed(lidar));
            getline(&buf, &len, file);
            printf("WHEELS_DIR:-%f\n", get_rotation(lidar));
            getline(&buf, &len, file);
        }
    }
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char* argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);
    FILE *file = fopen(".fifo_n4s", "r");
    char *buf = NULL;
    size_t len = 0;

    printf("START_SIMULATION\n");
    getline(&buf, &len, file);
    fprintf(stderr, "%s\n", buf);
    printf("CAR_FORWARD:0.3\n");
    getline(&buf, &len, file);
    fprintf(stderr, "%s\n", buf);
    loop(buf, len, file);
    return 0;
}
