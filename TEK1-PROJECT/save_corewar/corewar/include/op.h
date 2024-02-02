/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** op.h
*/


#ifndef _OP_H_
    #define _OP_H_
    //extern  op_t                     op_tab[];
    typedef char                     args_type_t;
    #define IDX_MOD                  512
    #define COMMENT_CHAR             '#'
    #define LABEL_CHAR               ':'
    #define LABEL_CHARS              "abcdefghijklmnopqrstuvwxyz_0123456789"
    #define DIRECT_CHAR              '%'
    #define SEPARATOR_CHAR           ','
    #define NAME_CMD_STRING          ".name"
    #define COMMENT_CMD_STRING       ".comment"
    #define REG_NUMBER               16
    #define MAX_ARGS_NUMBER          4
    #define T_REG                    1
    #define T_DIR                    2
    #define T_IND                    4
    #define T_LAB                    8
    #define MEM_SIZE                 (6 * 1024)
    #define IND_SIZE                 2
    #define DIR_SIZE                 4
    #define REG_SIZE                 DIR_SIZE
    #define PROG_NAME_LENGTH         128
    #define COMMENT_LENGTH           2048
    #define CYCLE_TO_DIE             1536
    #define NBR_LIVE                 40
    typedef struct op_s {
        char                         *mnemonique;
        char                         *comment;
        char                         nbr_args;
        char                         code;
        int                          nbr_cycles;
        args_type_t                  type[MAX_ARGS_NUMBER];
    }op_t;
    typedef struct header_s {
        #define COREWAR_EXEC_MAGIC   0xea83f3
        int                          prog_size;
        int                          magic;
        char                         prog_name[PROG_NAME_LENGTH + 1];
        char                         comment[COMMENT_LENGTH + 1];
    }header_t;
#endif
