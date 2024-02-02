/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** init champions
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "lib.h"
#include "my_printf.h"

static int read_champion_body(champion_t *champ, int fd)
{
    if (lseek(fd, 0x890, SEEK_SET) == -1
        || (champ->body = malloc(champ->file_size - 0x890)) == NULL
        || lseek(fd, 0x890, SEEK_SET) == -1
        || read(fd, champ->body, champ->body_size) == -1) {
        my_put_strerr("Error (read_champion_body) lseek, malloc or read.\n");
        return ERROR;
    }
    return SUCCESS;
}

static int init_champion(champion_t *champ, char *filepath, int idx)
{
    int fd;

    champ->id = idx;
    champ->header = NULL;
    champ->body = NULL;
    if (champ == NULL || filepath == NULL)
        return ERROR;
    if ((fd = open_file(filepath)) == -1)
        return ERROR;
    champ->file_size = lseek(fd, 0, SEEK_END);
    champ->body_size = champ->file_size - 0x890;

    if (read_champion_body(champ, fd) == ERROR) {
        free(champ->body);
        close(fd);
        return ERROR;
    }
    close(fd);
    return SUCCESS;
}

static int loop_to_init(corewar_t *core, char *str, int idx)
{
    size_t length = my_strlen(str);

    if (length > 4 && (my_strcmp((str + (length - 4)), ".cor")) == 0) {
        if ((core->champ[idx] = malloc(sizeof(champion_t))) == NULL)
            return ERROR;
        if (init_champion(core->champ[idx], str, idx) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

int init_champions(corewar_t *core, char **argv)
{
    int idx = 0;

    if (core == NULL)
        return ERROR;
    for (int i = 1; argv[i]; i++) {
        if (loop_to_init(core, argv[i], idx) == ERROR)
            return ERROR;
        idx++;
    }
    return SUCCESS;
}
