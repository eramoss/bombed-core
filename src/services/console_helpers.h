#include <termios.h> // For input handling
#include <sys/ioctl.h> // For terminal dimensions
#include <unistd.h> // For usleep() function
#include <cstdlib>
#include <iostream>
#include <unistd.h>

char get_input_without_enter() {
  struct termios oldt, newt;
  char input;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  input = std::getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return input;
}

void clear_console() {
  system("clear"); // Clear the console on Linux
}


void hideCursor() {
  std::cout << "\033[?25l";   // Hide the cursor using ANSI escape sequence
}