#include "uls.h"

static void default_settings(t_App *app);
static void time_and_hiden_files(t_App *app);
static void check_other_flags(t_App *app);

void mx_make_command(t_App *app) {
    default_settings(app);
    // TODO: добавить isatty и изменить app->command[cview]
    time_and_hiden_files(app);
    check_other_flags(app);
}

static void default_settings(t_App *app) {
    app->command[cfilter] = filter_delhidden;
    app->command[csort] = sort_name;
    app->command[reverse] = off;
    app->command[cformat_size] = format_size_noth;
    app->command[cview] = view_many_per_line;
    app->command[numerically] = off;
    app->command[time_format] = format_time_short;
    app->command[time_type] = time_type_m;
    app->command[col_inode] = off;
    app->command[col_blocks] = off;
    app->command[col_user] = on;
    app->command[col_group] = on;
    app->command[cheader] = header_no; // TODO: header!
}

static void time_and_hiden_files(t_App *app) {
    if (app->flags[a])
        app->command[cfilter] = filter_nofilter;
    if (app->flags[A])
        app->command[cfilter] = filter_deldir;
    if (app->flags[t]) {
        app->command[csort] = sort_mtime;
        if (app->flags[c])
            app->command[csort] = sort_ctime;
    }
    if (app->flags[u])
        app->command[time_type] = time_type_a;
    if (app->flags[U])
        app->command[time_type] = time_type_c;
    if (app->flags[T])
        app->command[time_format] = format_time_full;
    if (app->flags[i])
        app->command[col_inode] = on;
}

static void check_other_flags(t_App *app) {
    if (app->flags[s])
        app->command[col_blocks] = on;
    if (app->flags[o]) {
        app->command[col_group] = off;
        app->flags[l] = on;
    }
    if (app->flags[g]) {
        app->command[col_user] = off;
        app->flags[l] = on;
    }
    if (app->flags[n]) {
        app->command[numerically] = on;
        app->flags[l] = on;
    }
    if (app->flags[r])
        app->command[reverse] = on;
    if (app->flags[l])
        app->command[cview] = view_long_format;
}
