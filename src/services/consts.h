const int arena_width = 40;
const int arena_height = 20;

#ifdef _WIN32
const char c_wall_symbol = char(219);
const char* wall_symbol = &c_wall_symbol;
const char c_player_symbol = char(2);
const char* player_symbol = &c_player_symbol;
const char c_empty_symbol = ' ';
const char* empty_symbol = &c_empty_symbol;
const char c_explosion = char(176);
const char* explosion = &c_explosion;
const char c_great_explosion = char(177);
const char* great_explosion = &c_great_explosion;
const char c_greater_explosion = char(178);
const char* greater_explosion = &c_greater_explosion;
const char* bomb_character = "@";

#else

// arena symbols

const char* strong_wall_symbol = "\u2588";
const char* player_symbol = "\U0001FBC7";
const char* empty_symbol = " ";
const char* explosion = "\u2591";
const char* great_explosion = "\u2592";
const char* greater_explosion = "\u2593";
const char* bomb_character = "\u06de";

#endif // _WIN32

