#include "uls.h"

void mx_apply(t_lfa *lfa) {
    //mx_apply_filters(lfa);
    mx_apply_sort(lfa);
    mx_apply_printmode(lfa);
}

void mx_apply_without_printing(t_lfa *lfa) {
    //mx_apply_filters(lfa);
    mx_apply_sort(lfa);
}
