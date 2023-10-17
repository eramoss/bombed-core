#ifndef consts
#define consts

const int arena_width = 31;
const int arena_height = 22;

#ifdef _WIN32
char c_wall_symbol = char(219);
char* strong_wall_symbol = &c_wall_symbol;
char c_player_symbol = char(2);
char* player_symbol = &c_player_symbol;
char c_empty_symbol = ' ';
char* empty_symbol = &c_empty_symbol;
char c_explosion = char(176);
char* explosion = &c_explosion;
char c_great_explosion = char(178);
char* great_explosion = &c_great_explosion;
char c_greater_explosion = char(178);
char* greater_explosion = &c_greater_explosion;
char c_bomb_character = char(64);
char* bomb_character = &c_bomb_character;
char c_enemy_symbol = char(36);
char* enemy_symbol = &c_enemy_symbol;
char* c_weak_wall_symbol = char(177);
char* weak_wall_symbol = &c_weak_wall_symbol;

#else

// arena symbols

const char* strong_wall_symbol = "\u2588\u2588";
const char* player_symbol = "\U0001F412";
const char* empty_symbol = "  ";
const char* explosion = "\u2591\u2591";
const char* great_explosion = "\u2593\u2593";
const char* greater_explosion = "\u2593\u2593";
const char* bomb_character = "\U0001F4A3";
const char* enemy_symbol = "\U0001F47B";
const char* weak_wall_symbol = "\u2592\u2592";

#endif // _WIN32

#endif // consts