/*
** EPITECH PROJECT, 2023
** my_sh
** File description:
** my_sh
*/

#ifndef MY_SH_H_
    #define MY_SH_H_
    #include <stdbool.h>

typedef struct node {
    char* data;
    struct node* prev;
    struct node* next;
} node_t;

node_t* create_node(char* data);
void update_node(node_t *head, char *old_value, char *new_value);
void write_prompt(node_t* env);
void insert_at_end(node_t** head, char* data);
void delete_node(node_t** head, char* data);
void display_list(node_t* head);
void free_list(node_t** head);
void print_tab(char **tab);
int len_verification(char **args);
int redirect_io(const char *filename, const char *redirect_type);
void pipe_ditrib(char** commands, node_t *env_list);
int parse_builtin(char **argv, node_t* env_list);
int handle_exit(char **argv, int argc);
void execute_pipe_command(char *commands[], int num_commands, char** env);
int detect_separator(const char *str);
int trypath(char *final_path, char **args, char **env);
void handle_child(char** args, char *pathname, char** env, node_t *env_list);
int handle_parent(char*** args, char** pathname, node_t *env_list);
int path_handling(char** args, node_t* env_list);
int is_slash(char* str);
int mysh(node_t *env_list);
int exec_error_simple_command(char **args, char* final_path);
int cd_if_not_a_dir(char **argv);
bool is_there_this_delimiter(char *str, char which_delimiter);
node_t *create_new_env_list(char **env);
bool is_delimiter(char *str);
int len_of_chained_list(node_t *env);
int is_builtin(const char *command);
int is_there_separator(char** args);
void handle_both(char **parsed_command, node_t *env_list);
void handle_fork_exec(char **parsed_command, node_t *env_list);
int len_of_2d_array(char **tab);
int list_length(node_t *head);
void exec_complexe_command(char *command_array, node_t *env_list);
char* search_env(char* variable, node_t *env);
char* try_every_path_command(char **args, node_t *env_list);
int exec_simple_command(char *pathname, char **args, node_t *env_list, \
char **env);
char **linked_list_to_char_array(node_t *head);
int exec_builtin(char **argv, int argc, node_t* env);
int chdir_access_error(char **argv, int argc, node_t* env);
node_t *replace_env_oldpwd(node_t *env, char *oldpwd);
void set_new_env(const char *name, const char *value, node_t* env);
int folder_exist(char **argv);
int check_cd_error_exist(char **argv, int argc, node_t *env);
void free_2d_array(char **array);
int env_error(char** argv);
char* fillpath(char* final_path, char **path, char** path_env, int i);
int unset_env(const char *name, node_t* env, int argc);
int set_env_verif(node_t *env, const char *name, int specificator, int i);
char* name_value_string(const char *name, const char *value);
int env_fonction(char **argv, node_t *env, int argc);
int exec_env_command(char** argv, node_t** env);
void set_new_env_no_value(char *name, node_t* env);
node_t *modif_pwd_env(node_t *env);

#endif /* !MY_SH_H_ */
