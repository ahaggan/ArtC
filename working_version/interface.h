#include "display.h"
#include <unistd.h>

#define  ERROR_MAX  100

void initialise_interface(Menu* main_menu, Interface* interface, Mode mode);
int Interface_Events(Interface* interface);

void initialise_text_editor(Interface* interface, Mode mode, char* file_name);
void update_text_editor(int width, int height, Interface* interface);

void write_text_to_file(Interface* interface, char* file_name);

void generating(Draw *fractal, Interface *interface);
void generate_fractal(Draw *fractal, SDL_Win *window, int i);

void set_code_file(Interface *interface, Mode mode, char* file_name);
void set_challenges_based_on_level(char* file_name, Interface* interface);
void beginner_challenges(Interface *interface);
void intermediate_challenges(Interface *interface);
void expert_challenges(Interface *interface);
