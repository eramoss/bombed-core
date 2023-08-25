const int arena_width = 40;
const int arena_height = 20;

#ifdef _WIN32
char c_wall_symbol = char(219);
char* strong_wall_symbol = &c_wall_symbol;
char c_player_symbol = char(2);
char* player_symbol = &c_player_symbol;
char c_empty_symbol = ' ';
char* empty_symbol = &c_empty_symbol;
char c_explosion = char(176);
char* explosion = &c_explosion;
char c_great_explosion = char(177);
char* great_explosion = &c_great_explosion;
char c_greater_explosion = char(178);
char* greater_explosion = &c_greater_explosion;
char* bomb_character = "@";
char* enemy_symbol = "$";

#else

// arena symbols

const char* strong_wall_symbol = "\u2588";
const char* player_symbol = "&";
const char* empty_symbol = " ";
const char* explosion = "\u2591";
const char* great_explosion = "\u2592";
const char* greater_explosion = "\u2593";
const char* bomb_character = "\u25C9";
const char* enemy_symbol = "$";

#endif // _WIN32

