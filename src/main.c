#include "uls.h"

int main(int argc, char **argv) {
    t_App *app = new_App();

    mx_read_flags(argv, argc, app->flags, &(app->dir_path));
    mx_make_command(app);
    // --------------
    mx_reading(app);
    // free appls -l
    return 0;
}
