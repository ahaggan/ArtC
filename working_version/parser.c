//  This module tests the users program for gramatical accuracy. It will return an error if the input file(containing a program) is incorrect. 
//
//  As the program is tested, the correct attributes are assigned to an interpreter array. If the program is written correctly
//  this array is passed to the intereter module which will assign values from the user to the given fractal.
//  This fractal is then passed back to the interface.

#include "parser.h"
//int main(Draw *fractal, char *file_name) {     //Use this to pass a file name to the parser function.
int parser(Draw *fractal, char *file_name) {
    
    //test_parser();
    int i = 0;//Used to count through number of words in a program
    FILE *file_pointer;
    Prog program;
       
    program.fractal = fractal;
    
    initialise_arrays(&program);
    
    if((file_pointer = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "\nCannot open file\n");
        fclose(program.error);
        return FALSE;
    }
    
    while(fscanf(file_pointer, "%s", program.words[i]) == 1 
                   && i < MAX_WORDS && program.words[i] != NULL) {
        i++;
    }
    
    if(validate(&program) == FALSE) {
        fclose(program.error);
        return FALSE;
    }
    
    interpreter(&program);
    fclose(program.error);
    return TRUE;
}

void initialise_arrays(Prog *program) {
    initialise_words_array(program);
    
    create_struct_array(program->actions);
    
    initialise_interpreter_array(program);
}

void initialise_words_array(Prog *program) {

    int i;
    program->error = fopen("program_txt_files/error_message.txt", "w");
    program->current_word = 0;
    for(i = 0; i < MAX_WORDS; i++) {
        program->words[i][0] = '\0';
    }
}

void initialise_interpreter_array(Prog *program) {
    int i;
    program->interpreter_index = 0;
    for(i = 0; i < NO_OF_INSTRUCTIONS; i++) {
        program->interpreter[i][0] = '\0';
    }
}

void create_struct_array(Action *actions) {
    
	int i, j, k, l, cnt = 0, array_cnt = 0;
	char *first_word[ACTION_SIZE]= ACTION;
	char *second_word[ATTRIBUTE_SIZE]= ATTRIBUTE;
	
	for(i = 0; i < ACTION_SIZE && array_cnt < ATTRIBUTE_SIZE; i++) {
		actions[i].name = (char*)malloc(sizeof(char[strlen(first_word[i])]));
		actions[i].name = first_word[i];
	
		for(j = array_cnt; strcmp(second_word[j], "NEXT") != 0; j++) {
				
				cnt += 1;
		}
		array_cnt += cnt;
		
		actions[i].instruction = (char**)malloc(cnt * sizeof(char*));
		
		for(k = array_cnt - cnt, l = 0; k < array_cnt; k++, l++) {
			
			actions[i].instruction[l] = (char*)malloc(strlen(second_word[k])
                                                        *sizeof(char));
			strcpy(actions[i].instruction[l], second_word[k]);
		}
		cnt = 0;
		array_cnt += 1;
	}
}

int validate(Prog *program) {
    
    if(!strings_match(program->words[program->current_word], "run") 
           || program->words[program->current_word][0] == '\0') {
        printf("\nInside validate if\n");
        printf("\nWord: %s\n", program->words[program->current_word]);
        fprintf(program->error, "Program needs to start with 'run {'");
        return FALSE;
    }
    program->current_word += 1;
    if(!strings_match(program->words[program->current_word], "{") 
           || program->words[program->current_word] == NULL) {
        fprintf(program->error, "Program needs to start with 'run {'");
        return FALSE;
    }
    program->current_word += 1;
    if(funclist(program) == TRUE) {
        return TRUE;
    }
    return FALSE;
    
}

int funclist(Prog *program) {
    if(strings_match(program->words[program->current_word], "}")) {
        strcpy(program->interpreter[program->interpreter_index], "end" );
        program->interpreter_index += 1;
        return TRUE;
    }
    else if(program->words[program->current_word][0] == '\0') {      
                        //Should this be something else, EOF?
        fprintf(program->error, "Program needs to end with '}'");
        return FALSE;
    }
    if(function(program) == TRUE) {
        program->current_word += 1;
        return funclist(program);
    }
    return FALSE;
}

int function(Prog *program) {
    if(strings_match(program->words[program->current_word], "if")) {
        strcpy(program->interpreter[program->interpreter_index], "conditional");
            program->current_word += 1;
        if(check_if(program->words[program->current_word]) == TRUE) {
            if (!statement(program)) {
                return FALSE;
            } 
            program->current_word -= 1;
            program->interpreter_index += 1;
            strcpy(program->interpreter[program->interpreter_index], 
                     program->words[program->current_word]);
            program->interpreter_index += 1;
            program->current_word += 1;
            strcpy(program->interpreter[program->interpreter_index], 
                     program->words[program->current_word]);
            program->interpreter_index += 1;
            return conditional(program);
        }
        else {
            fprintf(program->error, 
                  "The action %s is not a valid condition for an if statement.",
                    program->words[program->current_word]);
        return FALSE;
        }
        
    }
    else if(strings_match(program->words[program->current_word], "for")) {
        program->current_word += 1;
        return loop(program);
    }
    else {
        return statement(program);
    }
}

int loop(Prog *program) {  
    int start_iteration, end_iteration;
    if(!strings_match(program->words[program->current_word], "iterations")) {
            fprintf(program->error, "For loop only works with iterations");
            return FALSE;
    }
    
    if (statement(program) == FALSE) {
        return FALSE;
    }
    
    start_iteration = atoi(program->words[program->current_word]);
    program->current_word += 1;
    if(!strings_match(program->words[program->current_word], "to")) {
            fprintf(program->error, 
              "For loop needs the word 'to' between the two conditions");
            return FALSE;
    }
    program->current_word += 1;
    if(!strings_match(program->words[program->current_word], "iterations")) {
            fprintf(program->error, "For loop only works with iterations");
            return FALSE;
    }
    statement(program);
    end_iteration = atoi(program->words[program->current_word]);
    program->current_word += 1;
    if(!strings_match(program->words[program->current_word], "{")) {
            fprintf(program->error, "For loop must start with '{'");
            return FALSE;
    }
    program->current_word += 1;
    if(start_iteration > end_iteration) {
        fprintf(program->error, "Start iteration must be less than than the ");
        fprintf(program->error, "end iteration in a for loop");
        return FALSE;
    }
    
    
    return for_loop(program, start_iteration, end_iteration);
}

int for_loop(Prog *program, int start, int end) {
    int start_counter = program->current_word;
    int i;
    for(i = start; i <= end; i++) {
        program->current_word = start_counter;
        strcpy(program->interpreter[program->interpreter_index], "conditional");
        program->interpreter_index += 1;
        strcpy(program->interpreter[program->interpreter_index], "iterations");
        program->interpreter_index += 1;
        sprintf(program->interpreter[program->interpreter_index], "%d", i);
        
        program->interpreter_index += 1;
        if (funclist(program) == FALSE) {
            return FALSE;
        }
    }
    return TRUE;
}
       
        
int conditional(Prog *program) {  //checks the if function after the statement
    program->current_word += 1;
    if(!strings_match(program->words[program->current_word], "then")) {
        fprintf(program->error, "If condition must be followed with 'then {'");
        return FALSE;
    }
    program->current_word += 1;
    if(!strings_match(program->words[program->current_word], "{")) {
        fprintf(program->error, "If condition must be followed with 'then {'");
        return FALSE;
    }
    program->current_word += 1;
    return funclist(program);
    
}

int statement(Prog *program) {
    if (check_action(program->words[program->current_word]) == TRUE) {
        program->current_word += 1;
        if(attribute(program)) {
            return TRUE;
        }
        else {
            fprintf(program->error, 
                      "Attribute word %s is not valid with action %s", 
                        program->words[program->current_word],
                        program->words[program->current_word-1] );
            return FALSE;
        }
    }
    else {
        fprintf(program->error, "Action word %s is not valid", 
                  program->words[program->current_word]);
        return FALSE;
    }
}

int check_action(char *word) {
    char *actions[ACTION_SIZE] = ACTION;
    int i;
    for(i = 0; i < ACTION_SIZE; i++) {
        if(strings_match(actions[i], word)) {
            return TRUE;
        }
    } 
    return FALSE; 
}

int attribute(Prog *program) {
    int i, j;
    int number = atoi(program->words[program->current_word]);
    for(i = 0; i < ACTION_SIZE; i++) {
        if(strings_match(program->actions[i].name, 
                           program->words[program->current_word-1])) {
            for(j = 0; 
                  !(strings_match(program->actions[i].instruction[j], "STOP")); 
                  j++) {
                if(strings_match(program->words[program->current_word], 
                                   program->actions[i].instruction[j])) {
                    if(strings_match(program->words[program->current_word-2], 
                                       "if")) {
                    }
                    else if(strings_match(
                                        program->words[program->current_word-2],
                                        "for")) {
                    }
                    else if(strings_match(
                                        program->words[program->current_word-2],
                                        "to")) {
                    }
                    else {
                        strcpy(program->interpreter[program->interpreter_index], 
                                 "assign");
                        program->interpreter_index += 1;
                        strcpy(program->interpreter[program->interpreter_index],
                                 program->words[program->current_word-1]);
                        program->interpreter_index += 1;
                        strcpy(program->interpreter[program->interpreter_index],
                                 program->words[program->current_word]);
                         program->interpreter_index += 1;
                        //assign_value(program, i);
                    }
                    return TRUE;
                }
                else if(number != 0) {  //MEANS YOU CAN ENTER A NUMERIC VALUE FOR ANY ACTION!
                    if(strings_match(program->words[program->current_word-1], 
                                       "iterations") 
                           && (number > 10)) {
                        fprintf(program->error, "Iterations error: ");
                        return FALSE;
                    }
                    else if(strings_match(
                                        program->words[program->current_word-1],
                                        "linethickness")
                                && (number > 1000)) {
                        fprintf(program->error, "Line thickness error: ");
                        return FALSE;
                    }
                    else if(strings_match(
                                        program->words[program->current_word-1],
                                        "size")
                                && (number > 2500)) {
                        fprintf(program->error, "Size error: ");
                        return FALSE;
                    }
                    else if(strings_match(
                                        program->words[program->current_word-1],
                                        "angle") 
                              && (number > 360)) {
                        fprintf(program->error, "Angle error: ");
                        return FALSE;
                    }
                    if(strings_match(program->words[program->current_word-2], 
                                     "if")) {
                    }
                    else if(strings_match(
                                        program->words[program->current_word-2],
                                        "for")) {
                    }
                    else if(strings_match(
                                        program->words[program->current_word-2], 
                                        "to")) {
                    }
                    else {
                        strcpy(program->interpreter[program->interpreter_index], 
                                 "assign");
                        program->interpreter_index += 1;
                        strcpy(program->interpreter[program->interpreter_index],
                                 program->words[program->current_word-1]);
                        program->interpreter_index += 1;
                        strcpy(program->interpreter[program->interpreter_index],
                                 program->words[program->current_word]);
                        program->interpreter_index += 1;
                        //assign_value(program, i);
                    } 
                    return TRUE;
                }
            }
        }
        
    }
    return FALSE;
}

int check_if(char *word) {
    
    if(strings_match(word, "iterations")) {
        return TRUE;
    }
    else if(strings_match(word, "colour")) {
        return TRUE;
    }
    return FALSE;
}


