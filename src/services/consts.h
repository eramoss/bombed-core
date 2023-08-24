const int arena_width = 40;
const int arena_height = 20;

#ifdef _WIN32
const char c_wall_symbol = char(219);
const char* wall_symbol = &c_wall_symbol;
const char c_player_symbol = char(2);
const char* player_symbol = &c_player_symbol;
const char c_empty_symbol = ' ';
const char* empty_symbol = &c_empty_symbol;


#else

// arena symbols

const char* strong_wall_symbol = "\u2588";
const char* player_symbol = "\U0001FBC7";
const char* empty_symbol = " ";


#endif // _WIN32


const char* explosion = "\U0001BAC7";
const char* great_explosion = "\U0001BAC7";
const char* greater_explosion = "\U0001BAC7";
const char* bomb_character = "@";