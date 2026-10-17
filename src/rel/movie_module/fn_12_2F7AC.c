#include "types.h"

typedef struct {
    int (*m_callback)(int, int, int, int);
} movie_object;

typedef struct {
    movie_object *m_objs[15];
} movie_hook_table;

typedef struct {
    int result;
    int index;
} loop_state;

int fn_12_2F7AC(movie_hook_table *arg0, movie_hook_table *arg1) {
    loop_state s;
    movie_object **table = arg1->m_objs;

    s.result = 0;
    s.index = s.result;
    *arg0 = *arg1;
    do {
        movie_object *obj = *table;
        if (obj == NULL) {
            break;
        }
        s.result = obj->m_callback(0, 0, 0, 0);
        if (s.result != 0) {
            break;
        }
        s.index++;
        table++;
    } while (s.index < 15);
    return s.result;
}

