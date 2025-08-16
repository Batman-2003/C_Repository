#ifndef _ARENA_H_
#define _ARENA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRINGIFY(x) #x

typedef struct Arena_t {
    const size_t ARENA_SIZE;
    void* arena_p;
    // struct Arena_t* itself_ptr;
    size_t curr_ind;
} Arena_t;

// * Declarations
Arena_t a_createArena(const size_t _arena_size);
Arena_t* ap_createArena(const size_t _arena_size);
void* vp_arenaAlloc(Arena_t* const arena_p,const size_t num_of_bytes);
void v_printArena(Arena_t* const arena_p);
void v_resetArena(Arena_t* const arena_p);
void v_destroyArena(Arena_t* const arena_p);


// * Definitions
Arena_t a_createArena(const size_t _arena_size) {
    Arena_t ret_var = {
        .ARENA_SIZE = _arena_size,
        .arena_p = calloc(_arena_size, 1),
        .curr_ind = 0,
    };
    if (!ret_var.arena_p) {
        printf("Error while Creating Arena\n");
        return (Arena_t){
            .arena_p = NULL,
        };
    }

    printf("Created Arena of size: %zu Bytes\n", ret_var.ARENA_SIZE);
    v_printArena(&ret_var);

    return ret_var;
}

Arena_t* ap_createArena(const size_t _arena_size) {
    Arena_t temp_arena = {
        .ARENA_SIZE = _arena_size,
        .arena_p = calloc(_arena_size, 1),
        .curr_ind = 0,
    };

    if (!temp_arena.arena_p) {
        printf("Error While Creating arena!!\nTODO: Handle this\n");
        return NULL;
    }
    printf("Arena of Size: %zu was created/allocated successfully\n", temp_arena.ARENA_SIZE);

    temp_arena.arena_p = (Arena_t*)vp_arenaAlloc(&temp_arena, sizeof(Arena_t));
    v_printArena(&temp_arena);
    Arena_t* return_ptr = (Arena_t*)temp_arena.arena_p;
    memcpy(return_ptr, &temp_arena, sizeof(Arena_t));
    v_printArena(return_ptr);
    return return_ptr;
}

void* vp_arenaAlloc(Arena_t* const arena_p, size_t num_of_bytes) {
    void* ret_ptr = arena_p->arena_p + arena_p->curr_ind;
    arena_p->curr_ind += num_of_bytes;
    return ret_ptr;
}

void v_printArena(Arena_t* const arena_p) {
    printf("\n\n");

    printf("Printing Arena Struct ...\n");
    printf("%28s: %p\n",  STRINGIFY(arena_p),    arena_p->arena_p);
    printf("%28s: %zu\n", STRINGIFY(ARENA_SIZE), arena_p->ARENA_SIZE);
    printf("%28s: %zu\n", STRINGIFY(curr_ind),   arena_p->curr_ind);
}

void v_resetArena(Arena_t* const arena_p) {
    arena_p->curr_ind = sizeof(Arena_t);
    memset(arena_p->arena_p + arena_p->curr_ind, 0, arena_p->ARENA_SIZE - arena_p->curr_ind);
    printf("Arena was Reset\n\n");
}

void v_destroyArena(Arena_t* const arena_p) {
    free(arena_p->arena_p);
    // free(arena_p);
    printf("Arena Destroyed ?? ");
}

#endif // _ARENA_H_