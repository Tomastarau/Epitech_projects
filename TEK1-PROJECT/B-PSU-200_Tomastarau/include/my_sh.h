/*
** EPITECH PROJECT, 2023
** my_sh
** File description:
** my_sh
*/

#ifndef MY_SH_H_
    #define MY_SH_H_

int check_exec_exist(char* executable_name);

int handle_exit(char **argv, int argc);

void handle_child(char** args, char* pathname ,char** env);

int handle_parent(int pid, char*** args, char** pathname, char*** env);

int path_handling(char* pathname, char** args, char** env);

int is_slash(char* str);

int mysh(char** env);

char** create_new_env(char **env);

int len_of_2d_array(char** tab);

char* search_env(char* variable, char** env);

int exec_builtin(char **argv, int argc, char*** env);

int chdir_access_error(char **argv, int argc, char*** env);

char** replace_env_oldpwd(char** env, char* oldpwd);

char** set_new_env(const char *name, const char *value, char** env);

int folder_exist(char **argv);

char** add_new_env_var(char** new_env, const char* env_var, int len_ev);

int check_cd_error_exist(char **argv, int argc, char ***env);

void free_2d_array(char **array);

int env_error(char** argv);

char** re_write_env(char **new_env, const char *name_value, int i);

char** unset_env(const char *name, char** env);

int set_env_verification(char **env, const char *name, int specificator, int i);

char **sub_set_new_env(char **env, char** new_env, int i);

char **final_var_len_ev_1(char** new_env, char* name_value, int i, int len_ev);

char **final_var_len_ev(char** new_env, char* name_value, int i, int len_ev);

char* name_value_string(const char *name, const char *value);

int env_fonction(char **argv, char*** env, int argc);

int exec_env_command(char** argv, char** env);

char** set_new_env_no_value(char *name, char** env);

char **modif_pwd_env(char **env);

char** re_write_env_no_val(char **new_env, char* name, int i);

#endif /* !MY_SH_H_ */
