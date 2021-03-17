/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** files_name.h
*/

#ifndef FILES_NAME_H
#define FILES_NAME_H

static char const *STAR = "ressources/star.png";
static char const *PLAYER = "ressources/player.png";
static char const *LOADING = "ressources/scr_load.png";
static char const *CURSOR = "ressources/cursor_point.png";
static char const *INVENTORY = "ressources/inventory.png";
static char const *QUEST_INFOS = "ressources/quest_infos.png";
static char const *QUEST_BUTTON = "ressources/quest_button.png";
static char const *SNOW = "ressources/particle.png";
static char const *HODOR = "ressources/hodor.png";
static char const *HTPL = "ressources/howtoplay.png";

static char const *FONT = "ressources/font/256.ttf";

static char const *SEED = "config/.random_seed";
static char const *BACKUP = "config/.backup";
static char const *COLL = "config/.collisions";

static char const *TRANSITION = "ressources/map/transition.png";
static char const *EMPTY = "ressources/map/empty.png";

static char const *MENUS = "ressources/menu/menus.png";
static char const *CADRE = "ressources/menu/cadre.png";
static char const *BUTTONS = "ressources/menu/buttons.png";
static char const *BACK_TREE = "ressources/menu/btree.png";
static char const *FRONT_TREE = "ressources/menu/ftree.png";
static char const *BACK_MOUNT = "ressources/menu/mount.png";
static char const *MENU_BG = "ressources/menu/background.png";
static char const *FRONT_MOUNT = "ressources/menu/mountain.png";

static char const *SKELETON_1 = "ressources/sprites_enemies/skeleton_1.png";
static char const *STAT_MENU = "ressources/menu/stat_menu.png";
static char const *MENU_SKILL = "ressources/sprite_skills/skill.png";
static char const *SKILL_BUTTON = "ressources/sprite_skills/gui.png";
static char const *STAT_MENU_BG = "ressources/menu/stat_menu.jpeg";

static char const *PAUSE_PATH[5] = {"ressources/parche.png",
                                    "ressources/new.png",
                                    "ressources/continue.png",
                                    "ressources/opt.png",
                                    "ressources/exit.png"};

static sfVector2f PAUSE_POS[5] = {(sfVector2f){690, 305},
                                (sfVector2f){815, 380},
                                (sfVector2f){815, 460},
                                (sfVector2f){815, 540},
                                (sfVector2f){815, 620}};

#endif
