#include "uls.h"

bool cmp_size(void *data1, void *data2) {
    if (((t_attr *)data1)->file_size > ((t_attr *)data2)->file_size)
        return true;
    else
        return false; 
}

bool cmp_c_time(void *data1, void *data2) {
    if (((t_attr *)data1)->c_time > ((t_attr *)data2)->c_time)
        return true;
    else
        return false; 
}

bool cmp_a_time(void *data1, void *data2) {
    if (((t_attr *)data1)->a_time > ((t_attr *)data2)->a_time)
        return true;
    else
        return false; 
}

bool cmp_m_time(void *data1, void *data2) {
    if (((t_attr *)data1)->m_time > ((t_attr *)data2)->m_time)
        return true;
    else
        return false; 
}

bool cmp_name(void *data1, void *data2) {
    if (mx_strcmp(((t_attr *)data1)->file_name, ((t_attr *)data2)->file_name) > 0)
        return true;
    else
        return false; 
}
