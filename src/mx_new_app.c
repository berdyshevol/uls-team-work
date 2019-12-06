#include "uls.h"

static void inicialization_app_al(t_App *app) {
    app->al[at_inode] = 1;     // inod
    app->al[at_blocks] = 1;    // blocks
    app->al[at_chmod] = -1;    // cmod_code
    app->al[at_links] = 1;     // number
    app->al[at_user] = -2;     // user_name
    app->al[at_group] = -2;    // group
    app->al[at_file_size] = 1; // size
    app->al[at_time] = -1;     // data
    app->al[at_file_name] = 0; // file_name
}// al -> align(выравнивать)

t_App *new_App(void) {
    t_App *app = malloc(sizeof(t_App));
    
    app->al = malloc(at_MAX * sizeof(int));
    app->flags = malloc(size * sizeof(int));
    app->cur_dir = NULL;
    mx_clear_flags(app->flags);
    inicialization_app_al(app);
    return app;
}

