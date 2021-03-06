#include "interpreter.h"

void interpreter(Prog* program) {
    int i;
    int end;
    
    for(i = 0; i < MAX_ITERATIONS; i++) {
        program->interpreter_index = 0;
        end = FALSE;
        while(program->interpreter_index < NO_OF_INSTRUCTIONS && end == FALSE) {
            if(strings_match(program->interpreter[program->interpreter_index], 
                               "assign")) {
                program->interpreter_index += 1;
                assign_value(program, i);
            }
            else if(strings_match(
                               program->interpreter[program->interpreter_index], 
                                 "conditional")) {
                program->interpreter_index += 1;
                if(check_condition(program, i) != TRUE) {
                    search_for_end(program);
                }  
            }
            
            if(strings_match(program->interpreter[program->interpreter_index], 
                               "end")
                 && strings_match(
                           program->interpreter[program->interpreter_index + 1], 
                             "")) {
                end = TRUE;
            }
            program->interpreter_index += 1;
        }
    }
}

int check_condition(Prog* program, int iteration) {
    if(strings_match(program->interpreter[program->interpreter_index], 
                       "iterations")) {
        program->interpreter_index += 1;
        if(atoi(program->interpreter[program->interpreter_index])==iteration) {
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
    else {
        if(strings_match(program->interpreter[program->interpreter_index], 
                           "colour")) {
            program->interpreter_index += 1;
            if(strings_match(program->interpreter[program->interpreter_index], 
                               program->fractal->colour[iteration])) {
                return TRUE;
            }
        }
        return FALSE;
    }
            
}

void search_for_end(Prog* program) {
    while(!strings_match(program->interpreter[program->interpreter_index], 
            "end")) {
        program->interpreter_index += 1;
    }
}

void assign_value(Prog* program, int iteration) {
    int size;
    if(strings_match(program->interpreter[program->interpreter_index], 
                       "colour")) {
        program->interpreter_index += 1;
        program->fractal->colour[iteration] = 
          (char*)malloc(strlen(program->interpreter[program->interpreter_index])
                          *sizeof(char));
        strcpy(program->fractal->colour[iteration], 
                 program->interpreter[program->interpreter_index]);
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "shape")) {
        program->interpreter_index += 1;
        program->fractal->shape[iteration] = 
          (char*)malloc(strlen(program->interpreter[program->interpreter_index])
                          *sizeof(char));
        strcpy(program->fractal->shape[iteration], 
                 program->interpreter[program->interpreter_index]);
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "size")) {
        program->interpreter_index += 1;
        size = abs(atoi(program->interpreter[program->interpreter_index]));
        if(size == 0) {
            interpret_size_word(program, iteration);
        }
        else{
            program->fractal->size[iteration] = size;
        }
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
              "height")) {
        program->interpreter_index += 1;
        program->fractal->height[iteration] = 
                         atoi(program->interpreter[program->interpreter_index]);
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "startx")) {
        program->interpreter_index += 1;
        program->fractal->startx = 
                         atoi(program->interpreter[program->interpreter_index]);
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "starty")) {
        program->interpreter_index += 1;
        program->fractal->starty = 
                         atoi(program->interpreter[program->interpreter_index]);
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "endx")) {
        program->interpreter_index += 1;
        program->fractal->endx = 
                         atoi(program->interpreter[program->interpreter_index]);
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "endy")) {
        program->interpreter_index += 1;
        program->fractal->endy = 
                         atoi(program->interpreter[program->interpreter_index]);
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "type")) {
        program->interpreter_index += 1;
        program->fractal->type[iteration] = 
          (char*)malloc(strlen(program->interpreter[program->interpreter_index])
                          *sizeof(char));
        strcpy(program->fractal->type[iteration], 
                 program->interpreter[program->interpreter_index]);
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "iterations")) {
        program->interpreter_index += 1;
        program->fractal->iterations = 
                         atoi(program->interpreter[program->interpreter_index]);
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "linethickness")) {
        program->interpreter_index += 1;
        size = abs(atoi(program->interpreter[program->interpreter_index]));
        if( size == 0) {
            interpret_thick_word(program, iteration);
        }
        else{
            program->fractal->linethickness[iteration] = size;
        }
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "angle")) {
        program->interpreter_index += 1;
        program->fractal->angle = 
            (atoi(program->interpreter[program->interpreter_index])*M_PI)/180.0;
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "splits")) {
        program->interpreter_index += 1;
        program->fractal->splits[iteration] = 
                         atoi(program->interpreter[program->interpreter_index]);
    }
}

void interpret_size_word(Prog *program, int iteration) {

    if(strings_match(program->interpreter[program->interpreter_index], 
                       "small")) {
        program->fractal->size[iteration] = 100;
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "medium")) {
        program->fractal->size[iteration] = 200;
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "large")) {
        program->fractal->size[iteration] = 300;
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "micro")) {
        program->fractal->size[iteration] = 50;
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "tiddly")) {
        program->fractal->size[iteration] = 20;
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "gargantuan")) {
        program->fractal->size[iteration] = 500;
    }

    else{
        program->fractal->size[iteration] = 0;
    }
}

void interpret_thick_word(Prog *program, int iteration) {

    if(strings_match(program->interpreter[program->interpreter_index], 
                       "thin")) {
        program->fractal->linethickness[iteration] = 1;
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "thick")) {
        program->fractal->linethickness[iteration] = 5;
    }
    else if(strings_match(program->interpreter[program->interpreter_index], 
                            "sam")) {
        program->fractal->linethickness[iteration] = 15;
    }

    else {
        program->fractal->linethickness[iteration] = 0;
    }
}
