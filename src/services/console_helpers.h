#ifndef console_helpers
#define console_helpers 

#include <iostream>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>

void clear_console(bool is_to_print_map = false) {
  if (is_to_print_map) {
    short int CX = 0, CY = 0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  }
  else {
    system("cls"); // Clear the console on Windows
  }
}

void hide_cursor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(hConsole, &cursorInfo);
}

char get_input_without_enter() {
  return _getch();
}

void pause_console() {
  system("pause");
}

#else

#include <termios.h>
#include <sys/ioctl.h>

void clear_console(bool is_to_print_map = false) {
  is_to_print_map ?
    system("clear") : system("clear"); // Clear the console on Linux
}

void hide_cursor() {
  std::cout << "\033[?25l"; // Hide the cursor using ANSI escape sequence
}

char get_input_without_enter() {
  struct termios old_terminal, new_terminal;
  char input;

  tcgetattr(STDIN_FILENO, &old_terminal);
  new_terminal = old_terminal;
  new_terminal.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal);

  input = std::getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);

  return input;
}

void pause_console() {
  system("read 0 -p");
}

#endif

#endif // console_helpers