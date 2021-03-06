#include "display.h"

void initialise_SDL(Menu* menu) {
    SDL_Win_Init(&menu-> window, "Art.C");
    SDL_TTF_Init();
}   

/* Main Menu */
void display_main_menu(Menu* main_menu) {
    int win_width, win_height;

    render_update(main_menu->window);

    SDL_GetWindowSize(main_menu->window.win, &win_width, &win_height);
    display_menu_background(win_width, win_height, main_menu);
    display_logo(win_width, win_height, main_menu);
    display_canvas_button(win_width, win_height, main_menu);
    display_challenges_button(win_width, win_height, main_menu);
    display_menu_help_button(win_width, win_height, main_menu);
    display_quit_button(win_width, win_height, main_menu);
}

void display_menu_background(int win_width, int win_height, Menu* main_menu) {
    int background_x, background_y, background_w, background_h;

    background_x = 0;
    background_y = 0;
    background_w = win_width;
    background_h = win_height;

    make_rect(&main_menu->window, &main_menu->background, background_x, 
                background_y, background_w, background_h, 
                  255, 255, 255);
}

void display_logo(int win_width, int win_height, Menu* main_menu) {
    int logo_x, logo_y, logo_w, logo_h;
    SDL_Texture* image = load_image("display/images/artc_logo.bmp", 
                                      &main_menu->window);

    logo_x = win_width / LEFT_MARGIN;
    logo_y = win_height / TOP_MARGIN; 
    logo_w = LOGO_WIDTH;
    logo_h = LOGO_HEIGHT;

    make_rect(&main_menu->window, &main_menu->logo, 
                logo_x, logo_y, logo_w, logo_h, 
                  230, 230, 230);

    SDL_RenderCopy(main_menu->window.renderer, image, 
                     NULL, &main_menu->logo.rect);
    SDL_DestroyTexture(image); 

}

void display_canvas_button(int win_width, int win_height, Menu* main_menu) {
    int canvas_button_x, canvas_button_y, canvas_button_w, canvas_button_h;
    SDL_Texture* image = load_image("display/images/canvas.bmp", 
                                      &main_menu->window);

    canvas_button_x = win_width / LEFT_MARGIN;
    canvas_button_y = main_menu->logo.rect.y + main_menu->logo.rect.h + 
                        (win_height / TOP_MARGIN);
    canvas_button_w = MENU_BUTTON_WIDTH;
    canvas_button_h = MENU_BUTTON_HEIGHT;

    make_rect(&main_menu->window, &main_menu->canvas_button, 
                canvas_button_x, canvas_button_y, 
                canvas_button_w, canvas_button_h, 
                  241, 14, 71);

    SDL_RenderCopy(main_menu->window.renderer, image, 
                     NULL, &main_menu->canvas_button.rect);
    SDL_DestroyTexture(image); 

}

void display_challenges_button(int win_width, int win_height, Menu* main_menu) {
    int challenges_button_x, challenges_button_y;
    int challenges_button_w, challenges_button_h;
    SDL_Texture* image = load_image("display/images/challenges.bmp", 
                                      &main_menu->window);

    challenges_button_x = win_width / LEFT_MARGIN;
    challenges_button_y = main_menu->canvas_button.rect.y + 
                            main_menu->canvas_button.rect.h +
                             (win_height / MENU_BUTTON_DIST);
    challenges_button_w = main_menu->canvas_button.rect.w;
    challenges_button_h = main_menu->canvas_button.rect.h;

    make_rect(&main_menu->window, &main_menu->challenges_button, 
                challenges_button_x, challenges_button_y, 
                challenges_button_w, challenges_button_h, 
                  241, 14, 71);

    SDL_RenderCopy(main_menu->window.renderer, image, 
                     NULL, &main_menu->challenges_button.rect);
    SDL_DestroyTexture(image); 
}

void display_menu_help_button(int win_width, int win_height, Menu* main_menu) {
    int menu_help_button_x, menu_help_button_y;
    int menu_help_button_w, menu_help_button_h;
    SDL_Texture* image = load_image("display/images/help.bmp", 
                                      &main_menu->window);

    menu_help_button_x = win_width / LEFT_MARGIN;
    menu_help_button_y = main_menu->challenges_button.rect.y + 
                           main_menu->challenges_button.rect.h +
                             (win_height / MENU_BUTTON_DIST);
    menu_help_button_w = main_menu->canvas_button.rect.w;
    menu_help_button_h = main_menu->canvas_button.rect.h;

    make_rect(&main_menu->window, &main_menu->menu_help_button, 
                menu_help_button_x, menu_help_button_y, 
                menu_help_button_w, menu_help_button_h, 
                  241, 14, 71);

    SDL_RenderCopy(main_menu->window.renderer, image, 
                     NULL, &main_menu->menu_help_button.rect);
    SDL_DestroyTexture(image); 
}

void display_quit_button(int win_width, int win_height, Menu* main_menu) {
    int quit_button_x, quit_button_y, quit_button_w, quit_button_h;
    SDL_Texture* image = load_image("display/images/quit.bmp", 
                                      &main_menu->window);

    quit_button_x = win_width / LEFT_MARGIN;
    quit_button_y = main_menu->menu_help_button.rect.y + 
                      main_menu->menu_help_button.rect.h +
                        win_height / MENU_BUTTON_DIST;
    quit_button_w = main_menu->canvas_button.rect.w;
    quit_button_h = main_menu->canvas_button.rect.h;

    make_rect(&main_menu->window, &main_menu->quit_button, 
                quit_button_x, quit_button_y, quit_button_w, quit_button_h, 
                  100, 90, 90);

    SDL_RenderCopy(main_menu->window.renderer, image, 
                     NULL, &main_menu->quit_button.rect);
    SDL_DestroyTexture(image); 
}

/* Challenges Menu */
void display_challenges_menu(Menu* challenges) {
    int win_width, win_height;

    render_update(challenges->window);

    SDL_GetWindowSize(challenges->window.win, &win_width, &win_height);

    display_challenges_background(win_width, win_height, challenges);
    display_header(win_width, win_height, challenges);
    display_beginner_button(win_width, win_height, challenges);
    display_intermediate_button(win_width, win_height, challenges);
    display_expert_button(win_width, win_height, challenges);
    display_main_menu_button(win_width, win_height, challenges);
}

void display_challenges_background(int win_width, int win_height, 
                                     Menu* challenges) {
    int background_x, background_y, background_w, background_h;

    background_x = 0;
    background_y = 0;
    background_w = win_width;
    background_h = win_height;

    make_rect(&challenges->window, &challenges->background, 
                background_x, background_y, background_w, background_h, 
                  255, 255, 255);
}

void display_header(int win_width, int win_height, Menu* challenges) {
    int header_x, header_y, header_w, header_h;
    SDL_Texture* image = load_image("display/images/challenges_header.bmp", 
                                      &challenges->window);

    header_w = LOGO_WIDTH;
    header_h = LOGO_HEIGHT;
    header_x = win_width / LEFT_MARGIN;
    header_y = win_height / TOP_MARGIN;

    make_rect(&challenges->window, &challenges->header, 
                header_x, header_y, header_w, header_h, 
                  220, 100, 100);

    SDL_RenderCopy(challenges->window.renderer, image, 
                     NULL, &challenges->header.rect);
    SDL_DestroyTexture(image); 
}

void display_beginner_button(int win_width, int win_height, Menu* challenges) {
    int beginner_x, beginner_y, beginner_w, beginner_h;
    SDL_Texture* image = load_image("display/images/beginner.bmp", 
                                      &challenges->window);

    beginner_x = win_width / LEFT_MARGIN;
    beginner_y = challenges->header.rect.y + challenges->header.rect.h + 
                   (win_height / MENU_BUTTON_DIST);
    beginner_w = MENU_BUTTON_WIDTH;
    beginner_h = MENU_BUTTON_HEIGHT;

    make_rect(&challenges->window, &challenges->beginner, 
                beginner_x, beginner_y, beginner_w, beginner_h, 
                  241, 14, 71);

    SDL_RenderCopy(challenges->window.renderer, image, 
                     NULL, &challenges->beginner.rect);
    SDL_DestroyTexture(image); 
}

void display_intermediate_button(int win_width, int win_height, 
                                   Menu* challenges) {
    int intermediate_x, intermediate_y, intermediate_w, intermediate_h;
    SDL_Texture* image = load_image("display/images/intermediate.bmp", 
                                      &challenges->window);

    intermediate_x = win_width / LEFT_MARGIN;
    intermediate_y = challenges->beginner.rect.y + challenges->beginner.rect.h +
                       (win_height / MENU_BUTTON_DIST);
    intermediate_w = MENU_BUTTON_WIDTH;
    intermediate_h = MENU_BUTTON_HEIGHT;

    make_rect(&challenges->window, &challenges->intermediate, 
                intermediate_x, intermediate_y, intermediate_w, intermediate_h, 
                  241, 14, 71);

    SDL_RenderCopy(challenges->window.renderer, image, 
                     NULL, &challenges->intermediate.rect);
    SDL_DestroyTexture(image); 
}

void display_expert_button(int win_width, int win_height, Menu* challenges) {
    int expert_x, expert_y, expert_w, expert_h;
    SDL_Texture* image = load_image("display/images/expert.bmp", 
                                      &challenges->window);

    expert_x = win_width / LEFT_MARGIN;
    expert_y = challenges->intermediate.rect.y + 
               challenges->intermediate.rect.h +
                 (win_height / MENU_BUTTON_DIST);
    expert_w = MENU_BUTTON_WIDTH;
    expert_h = MENU_BUTTON_HEIGHT;

    make_rect(&challenges->window, &challenges->expert, 
                expert_x, expert_y, expert_w, expert_h, 
                  241, 14, 71);

    SDL_RenderCopy(challenges->window.renderer, image, 
                     NULL, &challenges->expert.rect);
    SDL_DestroyTexture(image); 
}

void display_main_menu_button(int win_width, int win_height, Menu* challenges) {
    int main_menu_x, main_menu_y, main_menu_w, main_menu_h;
    SDL_Texture* image = load_image("display/images/main_menu.bmp", 
                                      &challenges->window);

    main_menu_x = win_width / LEFT_MARGIN;
    main_menu_y = challenges->expert.rect.y + challenges->expert.rect.h +
                    (win_height / MENU_BUTTON_DIST);
    main_menu_w = MENU_BUTTON_WIDTH;
    main_menu_h = MENU_BUTTON_HEIGHT;

    make_rect(&challenges->window, &challenges->main_menu, 
                main_menu_x, main_menu_y, main_menu_w, main_menu_h, 
                  100, 90, 90);

    SDL_RenderCopy(challenges->window.renderer, image, 
                     NULL, &challenges->main_menu.rect);
    SDL_DestroyTexture(image); 
}

/* Help Menu */
void display_help_screen(Menu* help_menu) {
    int win_width, win_height;

    SDL_GetWindowSize(help_menu->window.win, &win_width, &win_height);

    display_help_text(help_menu, win_width, win_height);
    display_back_button(help_menu, win_width, win_height);
}

void display_help_text(Menu* help_menu, int win_width, int win_height) {
    int help_x, help_y, help_w, help_h;
    SDL_Texture* image = load_image("display/images/help_screen.bmp", 
                                      &help_menu->window);

    help_x = 0;
    help_y = 0;  
    help_w = win_width;
    help_h = win_height;

    make_rect(&help_menu->window, &help_menu->help_screen, 
                help_x, help_y, help_w, help_h, 
                  230, 230, 230);

    SDL_RenderCopy(help_menu->window.renderer, image, 
                     NULL, &help_menu->help_screen.rect);
    SDL_DestroyTexture(image); 
}

void display_back_button(Menu* help_menu, int win_width, int win_height) {
    int back_button_x, back_button_y, back_button_w, back_button_h;
    SDL_Texture* image = load_image("display/images/back.bmp", 
                                      &help_menu->window);

    back_button_x = win_width / BACK_BUTTON_MARGIN;
    back_button_y = win_height / BACK_BUTTON_MARGIN;
    back_button_w = BACK_BUTTON_WIDTH;
    back_button_h = BACK_BUTTON_HEIGHT;

    make_rect(&help_menu->window, &help_menu->back_button, 
                back_button_x, back_button_y, back_button_w, back_button_h, 
                  100, 90, 90);

    SDL_RenderCopy(help_menu->window.renderer, image, 
                     NULL, &help_menu->back_button.rect);
    SDL_DestroyTexture(image); 
}


void display_popup_text(Menu* menu) {
    switch(menu->hover) {
        case canvas :
            display_canvas_text(menu);
            break;
        case challenges_menu_choice:
            display_challenges_text(menu);
            break;
        case beginner :
            display_beginner_text(menu);
            break;
        case intermediate :
            display_intermediate_text(menu);
            break;
        case expert :
            display_expert_text(menu);
            break;
        default :
            return;
    }
}

void display_canvas_text(Menu* main_menu) {
    int win_width, win_height;
    int canvas_text_x, canvas_text_y, canvas_text_w, canvas_text_h;
    SDL_Texture* image = load_image("display/images/program_a_work_of_art.bmp", 
                                      &main_menu->window);

    SDL_GetWindowSize(main_menu->window.win, &win_width, &win_height);

    canvas_text_x = main_menu->canvas_button.rect.w + win_width / LEFT_MARGIN;
    canvas_text_y = main_menu->canvas_button.rect.y;
    canvas_text_w = MENU_POPUP_WIDTH;
    canvas_text_h = MENU_POPUP_HEIGHT;

    make_rect(&main_menu->window, &main_menu->canvas_text, 
                canvas_text_x, canvas_text_y, canvas_text_w, canvas_text_h, 
                  230, 230, 230);

    SDL_RenderCopy(main_menu->window.renderer, image, 
                     NULL, &main_menu->canvas_text.rect);
    SDL_DestroyTexture(image); 
}

void display_challenges_text(Menu* main_menu) {
    int win_width, win_height;
    int challenges_text_x, challenges_text_y;
    int challenges_text_w, challenges_text_h;
    SDL_Texture* image = load_image("display/images/learn_how_to_code.bmp", 
                                      &main_menu->window);

    SDL_GetWindowSize(main_menu->window.win, &win_width, &win_height);

    challenges_text_x = main_menu->challenges_button.rect.w + 
                          (win_width / LEFT_MARGIN);
    challenges_text_y = main_menu->challenges_button.rect.y;
    challenges_text_w = MENU_POPUP_WIDTH;
    challenges_text_h = MENU_POPUP_HEIGHT;

    make_rect(&main_menu->window, &main_menu->challenges_text, 
                challenges_text_x, challenges_text_y, 
                challenges_text_w, challenges_text_h, 
                  230, 230, 230);

    SDL_RenderCopy(main_menu->window.renderer, image, 
                     NULL, &main_menu->challenges_text.rect);
    SDL_DestroyTexture(image); 
}

void display_beginner_text(Menu* challenges) {
    int win_width, win_height;
    int beginner_text_x, beginner_text_y, beginner_text_w, beginner_text_h;
    SDL_Texture* image = load_image("display/images/beginner_text.bmp", 
                                      &challenges->window);

    SDL_GetWindowSize(challenges->window.win, &win_width, &win_height);

    beginner_text_x = challenges->beginner.rect.w + win_width / LEFT_MARGIN;
    beginner_text_y = challenges->beginner.rect.y;
    beginner_text_w = MENU_POPUP_WIDTH;
    beginner_text_h = MENU_POPUP_HEIGHT;

    make_rect(&challenges->window, &challenges->beginner_text, 
                beginner_text_x, beginner_text_y, 
                beginner_text_w, beginner_text_h, 
                  230, 230, 230);

    SDL_RenderCopy(challenges->window.renderer, image, 
                     NULL, &challenges->beginner_text.rect);
    SDL_DestroyTexture(image); 
}

void display_intermediate_text(Menu* challenges) {
    int win_width, win_height;
    int intermediate_text_x, intermediate_text_y;
    int intermediate_text_w, intermediate_text_h;
    SDL_Texture* image = load_image("display/images/intermediate_text.bmp", 
                                      &challenges->window);

    SDL_GetWindowSize(challenges->window.win, &win_width, &win_height);

    intermediate_text_x = challenges->intermediate.rect.w + 
                            win_width / LEFT_MARGIN;
    intermediate_text_y = challenges->intermediate.rect.y;
    intermediate_text_w = MENU_POPUP_WIDTH;
    intermediate_text_h = MENU_POPUP_HEIGHT;

    make_rect(&challenges->window, &challenges->intermediate_text, 
                intermediate_text_x, intermediate_text_y, 
                intermediate_text_w, intermediate_text_h, 
                  230, 230, 230);

    SDL_RenderCopy(challenges->window.renderer, image, 
                     NULL, &challenges->intermediate_text.rect);
    SDL_DestroyTexture(image); 
}

void display_expert_text(Menu* challenges) {
    int win_width, win_height;
    int expert_text_x, expert_text_y, expert_text_w, expert_text_h;
    SDL_Texture* image = load_image("display/images/expert_text.bmp", 
                                      &challenges->window);

    SDL_GetWindowSize(challenges->window.win, &win_width, &win_height);

    expert_text_x = challenges->expert.rect.w + win_width / LEFT_MARGIN;
    expert_text_y = challenges->expert.rect.y;
    expert_text_w = MENU_POPUP_WIDTH;
    expert_text_h = MENU_POPUP_HEIGHT;

    make_rect(&challenges->window, &challenges->expert_text, 
                expert_text_x, expert_text_y, expert_text_w, expert_text_h, 
                  230, 230, 230);

    SDL_RenderCopy(challenges->window.renderer, image, 
                     NULL, &challenges->expert_text.rect);
    SDL_DestroyTexture(image); 
}


/* Interface */
void display_interface(Interface *interface, Mode mode, int refresh_canvas) {
    int win_width, win_height;

    SDL_GetWindowSize(interface->window.win, &win_width, &win_height);

    display_toolbar(win_width, win_height, interface, mode);
    display_menu_button(win_width, win_height, interface, mode);
    display_help_button(win_width, win_height, interface, mode);
    display_reset_button(win_width, win_height, interface, mode);
    display_generate_button(win_width, win_height, interface);
    display_text_editor(win_width, win_height, interface); 

    if(refresh_canvas) {
        display_canvas(win_width, win_height, interface, mode);
    }
   
    if (mode == challenge_mode) {
        display_learn_button(win_width, win_height, interface);
        display_current_challenge(win_width, win_height, interface);
        display_previous_button(win_width, win_height, interface);
        display_next_button(win_width, win_height, interface);
    }

    display_dividers(win_width, win_height, interface, mode);
}

void display_toolbar(int win_width, int win_height, 
                       Interface* interface, Mode mode) {
    int toolbar_x, toolbar_y, toolbar_w, toolbar_h;

    toolbar_x = 0;
    toolbar_y = 0;
    toolbar_h = win_height / BUTTON_HEIGHT;

    if (mode == challenge_mode) {
        toolbar_w = win_width;
    }
    else {
        toolbar_w = win_width / TEXT_ED_WIDTH;
    }

    make_rect(&interface->window, &interface->toolbar, 
                toolbar_x, toolbar_y, toolbar_w, toolbar_h, 
                  200, 200, 200);
}

void display_reset_button(int win_width, int win_height, 
                            Interface* interface, Mode mode) {
    int reset_button_x, reset_button_y, reset_button_w, reset_button_h;
    char reset_text[RESET_GENERATE_TEXTBOX];

    reset_button_w = (win_width / TEXT_ED_WIDTH) / 2;
    reset_button_h = win_height / BUTTON_HEIGHT;
    reset_button_x = 0;
    reset_button_y = win_height - reset_button_h;

    make_rect(&interface->window, &interface->reset_button, 
                reset_button_x, reset_button_y, reset_button_w, reset_button_h, 
                  241, 35, 65);

    if (mode == challenge_mode) {
        text_align_central(reset_text, "Reset", RESET_GENERATE_TEXTBOX);
    }
    else {
        text_align_central(reset_text, "Clear", RESET_GENERATE_TEXTBOX);
    }
    make_text(&interface->window, &interface->reset_button.rect, 
                interface->button_font, reset_text, 
                  255, 255, 255);
}

void display_generate_button(int win_width, int win_height, 
                               Interface* interface) {
    int generate_button_x, generate_button_y;
    int generate_button_w, generate_button_h;
    char generate_text[RESET_GENERATE_TEXTBOX];
  
    generate_button_w = (win_width / TEXT_ED_WIDTH) / 2 + 1;
    generate_button_h = win_height / BUTTON_HEIGHT;
    generate_button_x = (win_width / TEXT_ED_WIDTH) / 2;
    generate_button_y = win_height - generate_button_h;

    make_rect(&interface->window, &interface->generate_button, 
                generate_button_x, generate_button_y, 
                generate_button_w, generate_button_h, 
                  241, 35, 65);

    text_align_central(generate_text, "Generate", RESET_GENERATE_TEXTBOX);
    make_text(&interface->window, &interface->generate_button.rect,
                interface->button_font, generate_text, 
                  255, 255, 255);
} 

void display_menu_button(int win_width, int win_height, 
                           Interface* interface, Mode mode) {
    int menu_button_x, menu_button_y, menu_button_w, menu_button_h;
    char challenge_text[CHALLENGE_MODE_TEXTBOX];
    char canvas_text[CANVAS_MODE_TEXTBOX];



    menu_button_x = 0;
    menu_button_y = 0;
    menu_button_h = interface->toolbar.rect.h - 1;

    if (mode == challenge_mode) {
        menu_button_w = interface->text_editor_panel.rect.w / 3;
    }
    else {
        menu_button_w = interface->text_editor_panel.rect.w / 2;
    }

    make_rect(&interface->window, &interface->menu_button, 
                menu_button_x, menu_button_y, menu_button_w, menu_button_h, 
                  240, 240, 240);

    if (mode == challenge_mode) {
        text_align_central(challenge_text, "Levels", CHALLENGE_MODE_TEXTBOX);
        make_text(&interface->window, &interface->menu_button.rect, 
                    interface->button_font, challenge_text, 
                      241, 35, 65);
    }
    else {
        text_align_central(canvas_text, "Menu", CANVAS_MODE_TEXTBOX);
        make_text(&interface->window, &interface->menu_button.rect, 
                    interface->button_font, canvas_text, 
                      241, 35, 65);
    }
}

void display_learn_button(int win_width, int win_height, Interface* interface) {
    int learn_button_x, learn_button_y, learn_button_w, learn_button_h;
    char learn_text[CHALLENGE_MODE_TEXTBOX];

    learn_button_x = interface->menu_button.rect.x + 
                       interface->menu_button.rect.w; 
    learn_button_y = 0;
    learn_button_w = interface->menu_button.rect.w;
    learn_button_h = interface->menu_button.rect.h;

    make_rect(&interface->window, &interface->learn_button, 
                learn_button_x, learn_button_y, learn_button_w, learn_button_h, 
                  240, 240, 240);

    text_align_central(learn_text, "Learn", CHALLENGE_MODE_TEXTBOX);
    make_text(&interface->window, &interface->learn_button.rect,
                interface->button_font, learn_text,  
                  241, 35, 65);
}

void display_help_button(int win_width, int win_height, 
                           Interface* interface, Mode mode) {
    int help_button_x, help_button_y, help_button_w, help_button_h;
    char help_text[CHALLENGE_MODE_TEXTBOX];
    char help_text_canvas[CANVAS_MODE_TEXTBOX];

    if (mode == challenge_mode) {
        help_button_x = interface->learn_button.rect.x + 
                          interface->learn_button.rect.w; 
    }
    else {
        help_button_x = interface->menu_button.rect.x + 
                          interface->menu_button.rect.w + 1;
    }

    help_button_y = 0;
    help_button_w = interface->menu_button.rect.w;
    help_button_h = interface->menu_button.rect.h;

    make_rect(&interface->window, &interface->help_button, 
                help_button_x, help_button_y, help_button_w, help_button_h, 
                  240, 240, 240);

    if (mode == challenge_mode){
        text_align_central(help_text, "Help", CHALLENGE_MODE_TEXTBOX);
        make_text(&interface->window, &interface->help_button.rect,
                    interface->button_font, help_text, 
                      241, 35, 65);
    }
    else {
        text_align_central(help_text_canvas, "Help", CANVAS_MODE_TEXTBOX);
        make_text(&interface->window, &interface->help_button.rect,
                    interface->button_font, help_text_canvas, 
                      241, 35, 65);
    }
}

void display_canvas(int win_width, int win_height, 
                      Interface* interface, Mode mode) {
    int canvas_x, canvas_y, canvas_w, canvas_h;

    canvas_x = win_width / TEXT_ED_WIDTH + 1;
    canvas_w = win_width - win_width / TEXT_ED_WIDTH;

    if (mode == challenge_mode) {
        canvas_y = interface->toolbar.rect.h;
        canvas_h = win_height - interface->toolbar.rect.h;
    }
    else {
        canvas_y = 0;
        canvas_h = win_height;
    }

    make_rect(&interface->window, &interface->canvas, 
                canvas_x, canvas_y, canvas_w, canvas_h, 
                  255, 255, 255);
}

void display_text_editor(int win_width, int win_height, Interface* interface) {
   int texted_x, texted_y, texted_w, texted_h;

    texted_x = 0;
    texted_y = interface->toolbar.rect.h;
    texted_w = win_width / TEXT_ED_WIDTH;
    texted_h = win_height - interface->toolbar.rect.h - 
                 interface->generate_button.rect.h;

    make_rect(&interface->window, &interface->text_editor_panel, 
                texted_x, texted_y, texted_w, texted_h, 
                  43, 43, 39);
}

void display_current_challenge(int win_width, int win_height, 
                                 Interface* interface) {
    int curr_chall_x, curr_chall_y, curr_chall_w, curr_chall_h;
    char centred_string[MAX_CHALLENGE_LEN];

    curr_chall_x = interface->previous_button.rect.x + 
                     interface->previous_button.rect.w;
    curr_chall_y = 0;
    curr_chall_w = win_width - (win_width / TEXT_ED_WIDTH) - 
                     (interface->previous_button.rect.w * 2);
    curr_chall_h = interface->menu_button.rect.h;

    make_rect(&interface->window, &interface->current_challenge, 
                curr_chall_x, curr_chall_y, curr_chall_w, curr_chall_h, 
                  240, 240, 240);

    make_rect(&interface->window, &interface->current_challenge_text, 
                curr_chall_x, curr_chall_y + curr_chall_h / 5, 
                curr_chall_w, CHALLENGE_FONT_SIZE * 1.45, 
                  240, 240, 240);

    text_align_central(centred_string, 
                         interface->challenges[interface->challenge_num], 
                           MAX_CHALLENGE_LEN);
    make_text(&interface->window, &interface->current_challenge_text.rect, 
                interface->challenge_font, centred_string, 
                  0, 0, 0); 
}

void display_previous_button(int win_width, int win_height, 
                               Interface* interface) {
    int previous_button_x, previous_button_y;
    int previous_button_w, previous_button_h;
    char prev_text[PREV_NEXT_TEXTBOX];

    previous_button_x = interface->text_editor_panel.rect.w + 1;
    previous_button_y = 0;
    previous_button_w = (win_width / TEXT_ED_WIDTH) / PREV_NEXT_BUTTON;
    previous_button_h = interface->menu_button.rect.h;

    make_rect(&interface->window, &interface->previous_button, 
                previous_button_x, previous_button_y, 
                previous_button_w, previous_button_h, 
                  241, 35, 65);

    text_align_central(prev_text, "PREV", PREV_NEXT_TEXTBOX);
    make_text(&interface->window, &interface->previous_button.rect,
                interface->button_font, prev_text, 
                  255, 255, 255);   
}

void display_next_button(int win_width, int win_height, Interface* interface) {
    int next_button_x, next_button_y, next_button_w, next_button_h;
    char next_text[PREV_NEXT_TEXTBOX];

    next_button_x = interface->current_challenge.rect.x + 
                      interface->current_challenge.rect.w;
    next_button_y = interface->current_challenge.rect.y;
    next_button_w = (win_width / TEXT_ED_WIDTH) / PREV_NEXT_BUTTON;
    next_button_h = interface->menu_button.rect.h;

    make_rect(&interface->window, &interface->next_button, 
                next_button_x, next_button_y, next_button_w, next_button_h, 
                  241, 35, 65);

    text_align_central(next_text, "NEXT", PREV_NEXT_TEXTBOX);
    make_text(&interface->window, &interface->next_button.rect,
                interface->button_font, next_text,  
                  255, 255, 255);   
}

void display_dividers(int win_width, int win_height, 
                        Interface* interface, Mode mode) {
    //bottom divider
    make_rect(&interface->window, &interface->toolbar_bottom_divider, 
                0, interface->toolbar.rect.h - 1, interface->toolbar.rect.w, 1, 
                  20, 20, 20);

    if (mode == challenge_mode) {
        //Menu/Learn divider
        make_rect(&interface->window, &interface->menu_learn_divider, 
                    interface->learn_button.rect.x - 1, 0, 
                    1, interface->menu_button.rect.h, 
                      20, 20, 20);
    }
    //menu/help divider
     make_rect(&interface->window, &interface->menu_help_divider, 
              interface->help_button.rect.x - 1, 0,
              1, interface->menu_button.rect.h, 
                    20, 20, 20);
    
    //Learn/Help divider OR menu/help divider
    make_rect(&interface->window, &interface->menu_help_divider, 
                interface->help_button.rect.x - 1, 0,
                1, interface->menu_button.rect.h, 
                      20, 20, 20);

    //Text Editor/Canvas divider
    make_rect(&interface->window, &interface->toolbar_bottom_divider, 
                interface->text_editor_panel.rect.w, 0, 1, win_height, 
                  20, 20, 20);
    //Generate/Reset divider
    make_rect(&interface->window, &interface->reset_generate_divider, 
                interface->generate_button.rect.x - 1, 
                interface->generate_button.rect.y, 
                1, interface->generate_button.rect.h, 
                  0, 0, 0);
    //Generate/Reset top border
    make_rect(&interface->window, &interface->reset_generate_top_border, 
                interface->reset_button.rect.x, interface->reset_button.rect.y, 
                interface->reset_button.rect.w * 2 + 1, 1, 
                  0, 0, 0);  
    //prev divider
    make_rect(&interface->window, &interface->prev_divider, 
                interface->previous_button.rect.x + 
                  interface->previous_button.rect.w - 1, 
                interface->previous_button.rect.y,  
                1, interface->previous_button.rect.h, 
                  20, 20, 20);
    //next divider
    make_rect(&interface->window, &interface->next_divider, 
                interface->next_button.rect.x - 1, 
                interface->next_button.rect.y, 
                1, interface->next_button.rect.h, 
                  20, 20, 20);
}

void display_error_message(Interface *interface) {
    Area box, text_box_top, text_box_bottom;
    char align_message_top[ERROR_TEXTBOX], align_message_bottom[ERROR_TEXTBOX];

    read_write_error(align_message_top, align_message_bottom);
 
    SDL_Event event; 
    do {
        make_rect(&interface->window, &box, 
                    0, 200, interface->text_editor_panel.rect.w, 100, 
                      255,255,255);
        make_rect(&interface->window, &text_box_top, 
                    0, box.rect.y + (box.rect.h / 4), 
                    interface->text_editor_panel.rect.w, 
                    CHALLENGE_FONT_SIZE*1.45, 
                      255,255,255);
        make_text(&interface->window, &text_box_top.rect, 
                    interface->challenge_font, align_message_top, 
                      241, 35, 65);
        make_rect(&interface->window, &text_box_bottom, 
                    0, text_box_top.rect.y + text_box_top.rect.h, 
                    interface->text_editor_panel.rect.w, 
                    CHALLENGE_FONT_SIZE*1.45, 
                      255,255,255);
        make_text(&interface->window, &text_box_bottom.rect, 
                    interface->challenge_font, align_message_bottom, 
                      241, 35, 65);
        render_update(interface->window);
        SDL_PollEvent(&event); 
    } while(event.type != SDL_MOUSEBUTTONDOWN && event.type != SDL_KEYDOWN);
}

void read_write_error(char* align_message_top, char* align_message_bottom) {
    char message_top[ERROR_TEXTBOX], message_bottom[ERROR_TEXTBOX];
    FILE *file = fopen("program_txt_files/error_message.txt", "r");
    int i = 0, j = 0;
    char c;

    for(int i=0; i<ERROR_TEXTBOX; i++) {
        message_top[i] = '\0';
        message_bottom[i] = '\0';
    }

    while((c=getc(file))!=EOF && i < (ERROR_TEXTBOX * 2) - 2) {
        if (i < ERROR_TEXTBOX - 1) {
            message_top[i] = c;
        }
        else {
            if (message_top[ERROR_TEXTBOX - 2] != ' ') {
                do {
                    i--;
                } while (message_top[i] != ' ');
                while (i < ERROR_TEXTBOX - 1) {
                    message_bottom[j++] = message_top[i+1];
                    message_top[i+1] = ' ';
                    i++;
                }
                i += j - 1;
            }    
            message_bottom[i- ERROR_TEXTBOX + 1] = c;
        }
        i++;
    }
    fclose(file); 

    message_top[ERROR_TEXTBOX - 1] = '\0';
    message_bottom[ERROR_TEXTBOX - 1] = '\0';

    text_align_central(align_message_top, message_top, ERROR_TEXTBOX);
    text_align_central(align_message_bottom, message_bottom, ERROR_TEXTBOX);
}

void text_align_central(char* centred_string, char* input_string, 
                          int textbox_width) {
    int length = strlen(input_string);
    if(length > textbox_width) {
        printf("%d\n", length);
        printf("%d\n", textbox_width);
        printf("String too long for the textbox!\n");
        return;
    }

    int c, i=0;
    int difference = textbox_width - length;

    for (c = 0; c <= difference/2; c++) {
        centred_string[c] = ' ';
    }
    for (c = difference/2; c < difference/2 + length; c++) {
        centred_string[c] = input_string[i++];
    }
    for (c = difference/2 + length; c < textbox_width; c++) {
        centred_string[c] = ' ';
    }
    centred_string[textbox_width - 1] = '\0';
}

void make_text(SDL_Win *win, SDL_Rect *location, TTF_Font *font, char* text, 
                 int r, int g, int b) {
    SDL_Color textcolour = {r,g,b,255};
    SDL_Surface* textsurface = TTF_RenderText_Blended(font, text, textcolour);
    SDL_Texture* texttexture = surface_to_texture(textsurface, win);
    SDL_RenderCopy(win->renderer, texttexture, NULL, location);
    SDL_DestroyTexture(texttexture);
}

void make_rect(SDL_Win *win, Area *area, int x, int y, int w, int h, 
                 int r, int g, int b) {
    area->rect.w = w;
    area->rect.h = h;
    area->rect.x = x;
    area->rect.y = y;

    area->col.r = r;
    area->col.g = g;
    area->col.b = b;

    SDL_SetRenderDrawColor(win->renderer, r, g, b, 255);

    SDL_RenderFillRect(win->renderer, &area->rect);
}
