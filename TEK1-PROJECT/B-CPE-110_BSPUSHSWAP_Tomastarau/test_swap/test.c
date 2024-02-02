/*
** EPITECH PROJECT, 2022
** test swap elem
** File description:
** test swap elem
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "printf.h"
#include "swap.h"


void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (swap_elem, 1index1_greater_than_index2){
    int array [6] = {1, 2, 3, 4, 5, 6};
    int index1 = 2;
    int index2 = 4;
    swap_elem (array, index1, index2) ;
    cr_assert_eq (array[index1], 5) ;
    cr_assert_eq (array[index2], 3) ;
}

Test (swap_elem, 2index1_greater_than_index2){
    int array [6] = {1, 2, 3, 4, 5, 6};
    int index1 = 1;
    int index2 = 5;
    swap_elem (array, index1, index2) ;
    cr_assert_eq (array[index1], 6) ;
    cr_assert_eq (array[index2], 2) ;
}

Test (swap_elem, 3index1_greater_than_index2){
    int array [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int index1 = 2;
    int index2 = 14;
    swap_elem (array, index1, index2) ;
    cr_assert_eq (array[index1], 15) ;
    cr_assert_eq (array[index2], 3) ;
}

Test (swap_elem, 4index1_greater_than_index2){
    int array [6] = {6, 5, 4, 3, 2, 1};
    int index1 = 1;
    int index2 = 5;
    swap_elem (array, index1, index2) ;
    cr_assert_eq (array[index1], 1) ;
    cr_assert_eq (array[index2], 5) ;
}

Test (swap_elem, 5index1_greater_than_index2){
    int array [6] = {79, 78, 70, 71, 71, 70};
    int index1 = 2;
    int index2 = 5;
    swap_elem (array, index1, index2) ;
    cr_assert_eq (array[index1], 70) ;
    cr_assert_eq (array[index2], 70) ;
}

Test (swap_elem, 6index1_greater_than_index2){
    int array [6] = {0, 0, 0, 0, 0, 0};
    int index1 = 1;
    int index2 = 5;
    swap_elem (array, index1, index2) ;
    cr_assert_eq (array[index1], 0) ;
    cr_assert_eq (array[index2], 0) ;
}

Test (swap_elem, 7index1_greater_than_index2){
    int array [2] = {1, 1};
    int index1 = 0;
    int index2 = 1;
    swap_elem (array, index1, index2) ;
    cr_assert_eq (array[index1], 1) ;
    cr_assert_eq (array[index2], 1) ;
}

Test (swap_elem, 8index1_greater_than_index2){
    int array [2] = {1548, 8965};
    int index1 = 0;
    int index2 = 1;
    swap_elem (array, index1, index2) ;
    cr_assert_eq (array[index1], 8965) ;
    cr_assert_eq (array[index2], 1548) ;
}

Test (swap_elem, 9index1_greater_than_index2){
    int array [11] = {15, 85, 65, 98, 87, 12365, 875, 1, -15, -1235, 98};
    int index1 = 8;
    int index2 = 2;
    swap_elem (array, index1, index2) ;
    cr_assert_eq (array[index1], 65) ;
    cr_assert_eq (array[index2], -15) ;
}

Test (swap_elem, 10index1_greater_than_index2){
    int array [6] = {-45, -8, -963, -4, -78, -9652};
    int index1 = 0;
    int index2 = 5;
    swap_elem (array, index1, index2) ;
    cr_assert_eq (array[index1], -9652) ;
    cr_assert_eq (array[index2], -45) ;
}

Test (bubble_sort_array, 11index1_greater_than_index2){
    int i = 0;
    int array [6] = {-45, -8, -963, -4, -78, -9652};
    int array_sorted [6] = {-9652, -963, -78, -45, -8, -4};
    int taille = 6;
    bubble_sort_array (array, taille);
    while (i != 6){
        cr_assert_eq (array[i], array_sorted[i]);
        i++;
    }
}

Test (bubble_sort_array, 12index1_greater_than_index2){
    int i = 0;
    int array [13] = {5, 9, 3, 2, 7, 18, 92, 2, 2, 3, 7, 85, 95};
    int array_sorted [13] = {2, 2, 2, 3, 3, 5, 7, 7, 9, 18, 85, 92, 95};
    int taille = 13;
    bubble_sort_array (array, taille);
    while (i != 13){
        cr_assert_eq (array[i], array_sorted[i]);
        i++;
    }
}

Test (bubble_sort_array, 13index1_greater_than_index2){
    int i = 0;
    int array [31] = {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, \
    0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 2};
    int array_sorted [31] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
    int taille = 31;
    bubble_sort_array (array, taille);
    while (i != 31){
        cr_assert_eq (array[i], array_sorted[i]);
        i++;
    }
}

Test (bubble_sort_array, 14index1_greater_than_index2){
    int i = 0;
    int array [18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int array_sorted [18] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, \
    8, 9};
    int taille = 18;
    bubble_sort_array (array, taille);
    while (i != 18){
        cr_assert_eq (array[i], array_sorted[i]);
        i++;
    }
}

Test (bubble_sort_array, 15index1_greater_than_index2){
    int i = 0;
    int array [2] = {1, 2};
    int array_sorted [2] = {1, 2};
    int taille = 2;
    bubble_sort_array (array, taille);
    while (i != taille){
        cr_assert_eq (array[i], array_sorted[i]);
        i++;
    }
}

Test (bubble_sort_array, 16index1_greater_than_index2){
    int i = 0;
    int array [0] = {};
    int array_sorted [0] = {};
    int taille = 0;
    bubble_sort_array (array, taille);
    while (i != 1){
        cr_assert_eq (array[i], array_sorted[i]);
        i++;
    }
}

Test (bubble_sort_array, 17index1_greater_than_index2){
    int i = 0;
    int array [6] = {999999, 1, 2, 3, 4, 5};
    int array_sorted [6] = {1, 2, 3, 4, 5, 999999};
    int taille = 6;
    bubble_sort_array (array, taille);
    while (i != 6){
        cr_assert_eq (array[i], array_sorted[i]);
        i++;
    }
}

Test (bubble_sort_array, 18index1_greater_than_index2){
    int i = 0;
    int array [50] = {1, 5, 8, 7, 6, 3, 4, 8, 9, 6, 4, 1, 2, 5, 7, 8, 452,
    6532, 8745, 6589, 3215, 6587, 985, 321, 65, 4, 875, 231, 321, 548,
    9856, 2365, 22145, 2365, 215, 2547, 236, 9852, 14587, 24459, 32365,
    99999, 63554, 12554, 2365, 2554, 6859, 6223, 654, 874};
    int array_sorted [50] = {1, 1, 2, 3, 4, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8,
    8, 9, 65, 215, 231, 236, 321, 321, 452, 548, 654, 874, 875, 985, 2365,
    2365, 2365, 2547, 2554, 3215, 6223, 6532, 6587, 6589, 6859, 8745, 9852,
    9856, 12554, 14587, 22145, 24459, 32365, 63554, 99999};
    int taille = 50;
    bubble_sort_array (array, taille);
    while (i != taille){
        cr_assert_eq (array[i], array_sorted[i]);
        i++;
    }
}

Test (bubble_sort_array, 19index1_greater_than_index2){
    int i = 0;
    int array [350] = {1, 5, 8, 7, 6, 3, 4, 8, 9, 6, 4, 1, 2, 5, 7, 8, 452,
    6532, 8745, 6589, 3215, 6587, 985, 321, 65, 4, 875, 231, 321, 548,
    9856, 2365, 22145, 2365, 215, 2547, 236, 9852, 14587, 24459, 32365,
    99999, 63554, 12554, 2365, 2554, 6859, 6223, 654, 874,
    1, 5, 8, 7, 6, 3, 4, 8, 9, 6, 4, 1, 2, 5, 7, 8, 452,
    6532, 8745, 6589, 3215, 6587, 985, 321, 65, 4, 875, 231, 321, 548,
    9856, 2365, 22145, 2365, 215, 2547, 236, 9852, 14587, 24459, 32365,
    99999, 63554, 12554, 2365, 2554, 6859, 6223, 654, 874,
    1, 5, 8, 7, 6, 3, 4, 8, 9, 6, 4, 1, 2, 5, 7, 8, 452,
    6532, 8745, 6589, 3215, 6587, 985, 321, 65, 4, 875, 231, 321, 548,
    9856, 2365, 22145, 2365, 215, 2547, 236, 9852, 14587, 24459, 32365,
    99999, 63554, 12554, 2365, 2554, 6859, 6223, 654, 874,
    1, 5, 8, 7, 6, 3, 4, 8, 9, 6, 4, 1, 2, 5, 7, 8, 452,
    6532, 8745, 6589, 3215, 6587, 985, 321, 65, 4, 875, 231, 321, 548,
    9856, 2365, 22145, 2365, 215, 2547, 236, 9852, 14587, 24459, 32365,
    99999, 63554, 12554, 2365, 2554, 6859, 6223, 654, 874,
    1, 5, 8, 7, 6, 3, 4, 8, 9, 6, 4, 1, 2, 5, 7, 8, 452,
    6532, 8745, 6589, 3215, 6587, 985, 321, 65, 4, 875, 231, 321, 548,
    9856, 2365, 22145, 2365, 215, 2547, 236, 9852, 14587, 24459, 32365,
    99999, 63554, 12554, 2365, 2554, 6859, 6223, 654, 874,
    1, 5, 8, 7, 6, 3, 4, 8, 9, 6, 4, 1, 2, 5, 7, 8, 452,
    6532, 8745, 6589, 3215, 6587, 985, 321, 65, 4, 875, 231, 321, 548,
    9856, 2365, 22145, 2365, 215, 2547, 236, 9852, 14587, 24459, 32365,
    99999, 63554, 12554, 2365, 2554, 6859, 6223, 654, 874,
    1, 5, 8, 7, 6, 3, 4, 8, 9, 6, 4, 1, 2, 5, 7, 8, 452,
    6532, 8745, 6589, 3215, 6587, 985, 321, 65, 4, 875, 231, 321, 548,
    9856, 2365, 22145, 2365, 215, 2547, 236, 9852, 14587, 24459, 32365,
    99999, 63554, 12554, 2365, 2554, 6859, 6223, 654, 874};

    int array_sorted [350] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
    2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    9, 9, 9, 9, 9, 9, 9, 65, 65, 65, 65, 65, 65, 65, 215, 215, 215, 215,
    215, 215, 215, 231, 231, 231, 231, 231, 231, 231, 236, 236, 236, 236,
    236, 236, 236, 321, 321, 321, 321, 321, 321, 321, 321, 321, 321,
    321, 321, 321, 321, 452, 452, 452, 452, 452, 452, 452, 548, 548,
    548, 548, 548, 548, 548, 654, 654, 654, 654, 654, 654, 654, 874,
    874, 874, 874, 874, 874, 874, 875, 875, 875, 875, 875, 875, 875,
    985, 985, 985, 985, 985, 985, 985, 2365, 2365, 2365, 2365,
    2365, 2365, 2365, 2365, 2365, 2365, 2365, 2365, 2365, 2365,
    2365, 2365, 2365, 2365, 2365, 2365, 2365, 2547, 2547, 2547,
    2547, 2547, 2547, 2547, 2554, 2554, 2554, 2554, 2554,
    2554, 2554, 3215, 3215, 3215, 3215, 3215, 3215, 3215,
    6223, 6223, 6223, 6223, 6223, 6223, 6223, 6532, 6532,
    6532, 6532, 6532, 6532, 6532, 6587, 6587, 6587, 6587,
    6587, 6587, 6587, 6589, 6589, 6589, 6589, 6589, 6589,
    6589, 6859, 6859, 6859, 6859, 6859, 6859, 6859,
    8745, 8745, 8745, 8745, 8745, 8745, 8745, 9852,
    9852, 9852, 9852, 9852, 9852, 9852, 9856, 9856,
    9856, 9856, 9856, 9856, 9856, 12554, 12554,
    12554, 12554, 12554, 12554, 12554, 14587,
    14587, 14587, 14587, 14587, 14587,
    14587, 22145, 22145, 22145, 22145,
    22145, 22145, 22145, 24459, 24459,
    24459, 24459, 24459, 24459, 24459,
    32365, 32365, 32365, 32365, 32365,
    32365, 32365, 63554, 63554, 63554,
    63554, 63554, 63554, 63554, 99999,
    99999, 99999, 99999, 99999, 99999, 99999};
    int taille = 350;
    bubble_sort_array (array, taille);
    while (i != taille){
        cr_assert_eq (array[i], array_sorted[i]);
        i++;
    }
}
