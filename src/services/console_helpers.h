#include <iostream>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>

void clear_console() {
  system("cls"); // Clear the console on Windows
}

void hide_cursor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(hConsole, &cursorInfo);
}

#else

#include <termios.h>
#include <sys/ioctl.h>

void clear_console() {
  system("clear"); // Clear the console on Linux
}

void hide_cursor() {
  std::cout << "\033[?25l"; // Hide the cursor using ANSI escape sequence
}

#endif



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
