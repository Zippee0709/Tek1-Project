/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Contient les prototypages de libmy.a
*/

#ifndef NAVY
#define NAVY

#include <unistd.h>
extern const int MAP_MAX;
extern const int LINE_MAX;
extern void *ptr;

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
    char number;
}coord_t;

typedef struct {
    pid_t pid_one;
    pid_t pid_two;
    int player;
    int value;
}global_t;

char **read_pos(char *pos);
int player_one(char *posfile, int status);
int player_two(int p_one_pid, char *posfile);
int start_fill_map(char **pos, char map[MAP_MAX][MAP_MAX]);
void print_map(char map[MAP_MAX][MAP_MAX]);
void fill_map_null(char map[MAP_MAX][MAP_MAX]);
int sent_signal(char *coord, pid_t pid);
int start_game(char **pos, char map[MAP_MAX][MAP_MAX], int player, int pid_one);
int catch_signal(void);
void my_handler_sent(int signum);
void my_update(char map[MAP_MAX][MAP_MAX], pid_t pid_one, pid_t pid_two);
int my_catch_missed_hit_signal(char *buffer, char map[MAP_MAX][MAP_MAX]);
int my_get_number(char letter);
int check_status_game(char m[MAP_MAX][MAP_MAX], char e[MAP_MAX][MAP_MAX],
        global_t *game, int status);
void print_all_map(global_t *game, char map[MAP_MAX][MAP_MAX],
        char map_enemy[MAP_MAX][MAP_MAX]);
void print_map_status(int status, global_t *game, char map[MAP_MAX][MAP_MAX],
        char map_enemy[MAP_MAX][MAP_MAX]);
void print_map_for_second_player(int pid_one, char map[MAP_MAX][MAP_MAX],
        char map_enemy[MAP_MAX][MAP_MAX]);
void init_all(char **pos, char map[MAP_MAX][MAP_MAX],
        char map_enemy[MAP_MAX][MAP_MAX]);
void init_pid(pid_t pid_one, pid_t pid_two, int player, global_t *game);
int check_error(char **parse, int actual_pos);
int get_status(char map[MAP_MAX][MAP_MAX]);
void check_pid_send_signal(char *buffer, pid_t pid_one, pid_t pid_two);
int on_turn(char map_enemy[MAP_MAX][MAP_MAX], pid_t pid_one, pid_t pid_two);
void wait_turn(char map[MAP_MAX][MAP_MAX], pid_t pid_one, pid_t pid_two);
int game_pending(global_t *game, char map[MAP_MAX][MAP_MAX],
        char map_enemy[MAP_MAX][MAP_MAX]);
int my_check_nb_boat(char **pos);
#endif
