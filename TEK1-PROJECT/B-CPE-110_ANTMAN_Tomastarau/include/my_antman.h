/*
** EPITECH PROJECT, 2023
** my_antman
** File description:
** my_antman
*/

#ifndef MY_ANTMAN_H_
    #define MY_ANTMAN_H_

    int check_tab_if_dup_and_replace(char **tab, char *word, int i_table_comp);

    void compressing_algo(char **tab, char **tab_of_dup, int i_sec_tab);

    int check_tab_if_dup(char **tab, char *word);

    char **check_howmany_same(char *tab[], char**tab_of_dup, int i, int j);

    void my_text_compression(char *str);

    int is_character(char c);

    char *concatenate_double_array(char **tab);

    char *concatenate_double_array_of_dup(char **tab);

    void print_tab(char **tab);

    void str_to_standard_output(char *str, char *str_of_dup);

    void str_to_standard_output_giant(char *str);

    void send_same_file(char * str);

    int my_antman(char *argv[], struct stat stats);

    int my_strstrlen(char **tab);

    char **fill_tab_of_dup_2(char const *str);

    char **fill_tab_of_dup(char const *str);

    void check_if_spec_char(char **compressed_text, char **tab_of_dup, int i);

    void my_text_decompression(char const *str);

    char *concatenate_double_array_giant(char **tab, char **tab_of_dup);

    char *concatenate_double_array_bis(char **tab, char **tab_of_dup, \
char *new_str);

    int my_giantman(char *argv[], struct stat stats);

    char *file_to_str(const char *filepath);

    void write_header_compression(char *image);

    int write_header_decompression(char *image);

    int count_lines(char *str);

    void image_compression(char *argv);

    void image_file_decompression(char *filepath);

#endif /* !MY_ANTMAN_H_ */
