
#include "test_parser.h"

void test_parser(void){
    FILE *test_results;
    //int test_count= 0;
    printf("\nTEST FUNCTION!!!!\n");
    test_results = fopen("program_txt_files/testing/test_results.txt", "w");
    fprintf(test_results, "\nPARSER TEST\nBelow are the test results for this module\n");
    if (test_initialise_words(test_results) == PASSED){
        fprintf(test_results, "\nInitialise words array test PASSED.\n");
    }
    else{
        fprintf(test_results, "\nInitialise words array test FAILED.\n");
    } 
    
    if (test_initialise_interpreter(test_results) == PASSED){
        fprintf(test_results, "\nInitialise interpreter array test PASSED.\n");
    }
    else{
        fprintf(test_results, "\nInitialise interpreter array test FAILED.\n");
    } 
    
    if (test_validate(test_results) == PASSED){
        fprintf(test_results, "\nValidate tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nValidate tests FAILED.\n");
    } 
    
    
    if (test_funclist(test_results) == PASSED){
        fprintf(test_results, "\nFunclist tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nFunclist tests FAILED.\n");
    } 
    
    if (test_function(test_results) == PASSED){
        fprintf(test_results, "\nFunction tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nFunction tests FAILED.\n");
    } 
    
    if (test_check_action(test_results) == PASSED){
        fprintf(test_results, "\nCheck action tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nCheck action tests FAILED.\n");
    } 
    
    
    if (test_attribute(test_results) == PASSED){
        fprintf(test_results, "\nAttribute tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nAttribute tests FAILED.\n");
    } 
    
    
    if (test_check_if(test_results) == PASSED){
        fprintf(test_results, "\nCheck if tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nCheck if tests FAILED.\n");
    }
    
    
    if (test_statement(test_results) == PASSED){
        fprintf(test_results, "\nStatement tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nStatement tests FAILED.\n");
    }
    
    
    
    if (test_conditional(test_results) == PASSED){
        fprintf(test_results, "\nConditional tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nConditional tests FAILED.\n");
    }
    
    if (test_loop(test_results) == PASSED){
         fprintf(test_results, "\nLoop tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nLoop tests FAILED.\n");
    }
    
    if (test_for_loop(test_results) == PASSED){
         fprintf(test_results, "\nLoop tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nLoop tests FAILED.\n");
    }
    
    if(test_whole(test_results) == PASSED){
       fprintf(test_results, "\nFull parser tests PASSED.\n");
    }
    else{
        fprintf(test_results, "\nFull parser tests FAILED.\n");
    } 
    
    
    fclose(test_results);
    
}

int test_whole(FILE *test_results){
    Draw test_fractal;
    int pass_count = 0, no_of_tests = 0;
    
    no_of_tests += 1;
    //Test basic, correct, program test function should return TRUE
    if(parser(&test_fractal, "program_txt_files/testing/test_parser1.txt") == TRUE){
        fprintf(test_results, "\nWhole parser test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nWhole parser test 1: Failed");
    }
    
    no_of_tests += 1;
    //Tests a, correct, program containing a for loop. Function should return TRUE
    if(parser(&test_fractal, "program_txt_files/testing/test_parser2.txt") == TRUE){
        fprintf(test_results, "\nWhole parser test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nWhole parser test 2: Failed");
    }
    
    no_of_tests += 1;
    //Tests a, correct, program containing an if statement. Function should return TRUE
    if(parser(&test_fractal, "program_txt_files/testing/test_parser3.txt") == TRUE){
        fprintf(test_results, "\nWhole parser test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nWhole parser test 3: Failed");
    }
    
    no_of_tests += 1;
    //Tests an incorrect basic program containing an incorrect statement. Function should return FALSE
    if(parser(&test_fractal, "program_txt_files/testing/test_parser4.txt") == FALSE){
        fprintf(test_results, "\nWhole parser test 4: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nWhole parser test 4: Failed");
    }
    
    no_of_tests += 1;
    //Tests a program containing an incorrect for loop. Function should return FALSE
    if(parser(&test_fractal, "program_txt_files/testing/test_parser5.txt") == FALSE){
        fprintf(test_results, "\nWhole parser test 5: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nWhole parser test 5: Failed");
    }
    
    no_of_tests += 1;
    //Tests a program containing an incorrect if statement. Function should return FALSE
    if(parser(&test_fractal, "program_txt_files/testing/test_parser6.txt") == FALSE){
        fprintf(test_results, "\nWhole parser test 6: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nWhole parser test 6: Failed");
    }
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
}

int test_initialise_words(FILE *test_results){
    Prog test_program;
    int i;
    initialise_words_array(&test_program);
    for(i = 0; i < MAX_WORDS; i++){
        if(test_program.words[i][0] != '\0'){
            
            return FAILED;
        }
    }
    return PASSED;
}



int test_initialise_interpreter(FILE *test_results){
    Prog test_program;
    int i;
    initialise_interpreter_array(&test_program);
    for(i = 0; i < NO_OF_INSTRUCTIONS; i++){
        if(test_program.interpreter[i][0] != '\0'){
            return FAILED;
        }
    }
    return PASSED;
}

int test_validate(FILE *test_results){
    Prog test_program;
    int pass_count = 0, no_of_tests = 0;
    initialise_arrays(&test_program);
    //passes an incorrect program start so should return FALSE
    
    no_of_tests += 1;
    test_program.current_word = 0;
    strcpy(test_program.words[0], "Hello");
    printf("\nFirst Validate");
    if (validate(&test_program) == FALSE){        
        fprintf(test_results, "\nValidate test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nValidate test 1: Failed");
    }
    
    //passes an incorrect program start so should return FALSE
    no_of_tests += 1;
    test_program.current_word = 0;
    strcpy(test_program.words[0], "run");
    strcpy(test_program.words[1], "program");
    if (validate(&test_program) == FALSE){
        fprintf(test_results, "\nValidate test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nValidate test 2: Failed");
    }
    
    //passes a correct program so should return TRUE
    no_of_tests += 1;
    test_program.current_word = 0;
    strcpy(test_program.words[0], "run");
    strcpy(test_program.words[1], "{");
    strcpy(test_program.words[2], "}");
    if (validate(&test_program) == TRUE){
        fprintf(test_results, "\nValidate test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nValidate test 3: Failed");
    }
   
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
}

int test_funclist(FILE *test_results){
    Prog test_program;
    int pass_count = 0, no_of_tests = 0;
    initialise_arrays(&test_program);
    
    
    //Passes a correct program end so should return TRUE
    no_of_tests += 1;
    test_program.current_word = 0;
    strcpy(test_program.words[0], "}");
    if (funclist(&test_program) == TRUE){        
        fprintf(test_results, "\nFunclist test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFunclist test 1: Failed");
    }
    
    //Passes the NULL character(representing the end of a program, should return FALSE
    no_of_tests += 1;
    test_program.current_word = 0;
    test_program.words[0][0] = '\0';
    
    if (funclist(&test_program) == FALSE){        
        fprintf(test_results, "\nFunclist test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFunclist test 2: Failed");
    }
    
    //Passes a basic correct program so should return TRUE
    no_of_tests += 1;
    test_program.current_word = 0;
    strcpy(test_program.words[0], "colour");
    strcpy(test_program.words[1], "blue");
    strcpy(test_program.words[2], "}");
    if (funclist(&test_program) == TRUE){        
        fprintf(test_results, "\nFunclist test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFunclist test 3: Failed");
    }
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
    
}

int test_function(FILE *test_results){
    Prog test_program;
    int pass_count = 0, no_of_tests = 0;
    initialise_arrays(&test_program);
    
    no_of_tests += 1;
    //Send a correct statement should return TRUE
    test_program.current_word = 0;
    strcpy(test_program.words[0], "shape");
    strcpy(test_program.words[1], "square");
    if (function(&test_program) == TRUE){        
        fprintf(test_results, "\nFunction test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFunction test 1: Failed");
    }
    
    no_of_tests += 1;
    //Send a correct if statement should return TRUE
    test_program.current_word = 0;
    strcpy(test_program.words[0], "if");
    strcpy(test_program.words[1], "colour");
    strcpy(test_program.words[2], "lime");
    strcpy(test_program.words[3], "then");
    strcpy(test_program.words[4], "{");
    strcpy(test_program.words[5], "}");
    if (function(&test_program) == TRUE){        
        fprintf(test_results, "\nFunction test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFunction test 2: Failed");
    }
    
    no_of_tests += 1;
    //Send a correct for statement should return TRUE
    test_program.current_word = 0;
    strcpy(test_program.words[0], "for");
    strcpy(test_program.words[1], "iterations");
    strcpy(test_program.words[2], "5");
    strcpy(test_program.words[3], "to");
    strcpy(test_program.words[4], "iterations");
    strcpy(test_program.words[5], "6");
    strcpy(test_program.words[6], "{");
    strcpy(test_program.words[7], "}");
    if (function(&test_program) == TRUE){        
        fprintf(test_results, "\nFunction test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFunction test 3: Failed");
    }
    
    no_of_tests += 1;
    //Send an incorrect statement should return FALSE
    test_program.current_word = 0;
    strcpy(test_program.words[0], "shape");
    strcpy(test_program.words[1], "blue");
    if (function(&test_program) == FALSE){        
        fprintf(test_results, "\nFunction test 4: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFunction test 4: Failed");
    }
    
    no_of_tests += 1;
    //Send an incorrect if statement should return FALSE
    test_program.current_word = 0;
    strcpy(test_program.words[0], "if");
    strcpy(test_program.words[1], "colour");
    strcpy(test_program.words[2], "lime");
    strcpy(test_program.words[3], "{");
    strcpy(test_program.words[4], "}");
    if (function(&test_program) == FALSE){        
        fprintf(test_results, "\nFunction test 5: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFunction test 5: Failed");
    }
    
    no_of_tests += 1;
    //Send an incorrect for statement should return FALSE
    test_program.current_word = 0;
    strcpy(test_program.words[0], "for");
    strcpy(test_program.words[1], "iterations");
    strcpy(test_program.words[2], "5");
    strcpy(test_program.words[3], "iterations");
    strcpy(test_program.words[4], "6");
    strcpy(test_program.words[5], "{");
    
    if (function(&test_program) == FALSE){        
        fprintf(test_results, "\nFunction test 6: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFunction test 6: Failed");
    }
    
     if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
}

int test_check_action(FILE *test_results){
    char test_word[WORD_LENGTH];
    
    int pass_count = 0, no_of_tests = 0;
    no_of_tests += 1;
    strcpy(test_word, "Hello");
    //Function should return FALSE
    if (check_action(test_word) == FALSE){        
        fprintf(test_results, "\nCheck action test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nCheck action test 1: Failed");
    }
    
    no_of_tests += 1;
    strcpy(test_word, "colour");
    //Function should return TRUE
    if (check_action(test_word) == TRUE){        
        fprintf(test_results, "\nCheck action test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nCheck action test 2: Failed");
    }
    
    no_of_tests += 1;
    strcpy(test_word, "Colour");
    //Function should return FALSE, capital not allowed
    if (check_action(test_word) == FALSE){        
        fprintf(test_results, "\nCheck action test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nCheck action test 3: Failed");
    }
    
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
}

int test_statement(FILE *test_results){
    Prog test_program;
    int pass_count = 0, no_of_tests = 0;
    initialise_arrays(&test_program);
    
    no_of_tests += 1;
    test_program.current_word = 1;
    strcpy(test_program.words[0], "Hello"); //Arbitrary, needs to be there for function test.
    strcpy(test_program.words[1], "colour");
    strcpy(test_program.words[2], "blue");
    //Correct statement, should return TRUE
    if (statement(&test_program) == TRUE){        
        fprintf(test_results, "\nStatement test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nStatement test 1: Failed");
    }
    
    no_of_tests += 1;
    test_program.current_word = 1;
    strcpy(test_program.words[0], "Hello"); //Arbitrary, needs to be there for function test.
    strcpy(test_program.words[1], "colour");
    strcpy(test_program.words[2], "square");
    //Incorrect statement, should return FALSE
    if (statement(&test_program) == FALSE){        
        fprintf(test_results, "\nStatement test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nStatement test 2: Failed");
    }
    
    no_of_tests += 1;
    test_program.current_word = 1;
    strcpy(test_program.words[0], "Hello"); //Arbitrary, needs to be there for function test.
    strcpy(test_program.words[1], "colou");
    strcpy(test_program.words[2], "blue");
    //Incorrect statement, should return FALSE
    if (statement(&test_program) == FALSE){        
        fprintf(test_results, "\nStatement test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nStatement test 3: Failed");
    }
    
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
}

int test_attribute(FILE *test_results){
    
    Prog test_program;
    
    int pass_count = 0, no_of_tests = 0;
    initialise_arrays(&test_program);
    test_program.current_word = 2;
    no_of_tests += 1;
    strcpy(test_program.words[0], "arbitrary"); //Just needs to be a word other than if, for or to.
    
    strcpy(test_program.words[1], "colour");
    strcpy(test_program.words[2], "blue");
    //correct input, should return TRUE
    if (attribute(&test_program) == TRUE){        
        fprintf(test_results, "\nAttribute test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nAttribute test 1: Failed");
    }
    
    test_program.current_word = 2;
    no_of_tests += 1;
    strcpy(test_program.words[0], "arbitrary");
    strcpy(test_program.words[1], "colour");
    strcpy(test_program.words[2], "Hello");
    //correct input, should return FALSE
    if (attribute(&test_program) == FALSE){        
        fprintf(test_results, "\nAttribute test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nAttribute test 2: Failed");
    }
    
    test_program.current_word = 2;
    no_of_tests += 1;
    strcpy(test_program.words[0], "arbitrary");
    strcpy(test_program.words[1], "colour");
    strcpy(test_program.words[2], "");
    //correct input, should return FALSE
    if (attribute(&test_program) == FALSE){        
        fprintf(test_results, "\nAttribute test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nAttribute test 3: Failed");
    }
    
    test_program.current_word = 2;
    no_of_tests += 1;
    strcpy(test_program.words[0], "arbitrary");
    strcpy(test_program.words[1], "size");
    strcpy(test_program.words[2], "10");
    //correct input, should return TRUE
    if (attribute(&test_program) == TRUE){        
        fprintf(test_results, "\nAttribute test 4: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nAttribute test 4: Failed");
    }
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
}

int test_check_if(FILE *test_results){
    char test_word[WORD_LENGTH];
    
    int pass_count = 0, no_of_tests = 0;
    no_of_tests += 1;
    strcpy(test_word, "Hello");
    //Function should return FALSE
    if (check_if(test_word) == FALSE){        
        fprintf(test_results, "\nCheck if test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nCheck if test 1: Failed");
    }
    
    no_of_tests += 1;
    strcpy(test_word, "iterations");
    //Function should return TRUE
    if (check_if(test_word) == TRUE){        
        fprintf(test_results, "\nCheck if test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nCheck if test 2: Failed");
    }
    
    no_of_tests += 1;
    strcpy(test_word, "colour");
    //Function should return TRUE
    if (check_if(test_word) == TRUE){        
        fprintf(test_results, "\nCheck if test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nCheck if test 3: Failed");
    }
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
}

int test_conditional(FILE *test_results){
    printf("\nStart of conditional");
    Prog test_program;
    int pass_count = 0, no_of_tests = 0;
    initialise_arrays(&test_program);
    //Tests empty if statements so that the interpreter array doesn't need to be initiated - the test is just to 
    
    //Passes an incorrect(empty) if statement, should return FALSE 
    no_of_tests += 1;
    test_program.current_word = 0;
    //Function increases current word before anything else
    
    strcpy(test_program.words[0], "Hello");
    strcpy(test_program.words[1], "Hello");
    strcpy(test_program.words[2], "{");
    strcpy(test_program.words[3], "}");
    
    if (conditional(&test_program) == FALSE){        
        fprintf(test_results, "\nConditional test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nConditional test 1: Failed");
    }
    
    //Passes an correct(empty) if statement, should return TRUE 
    no_of_tests += 1;
    test_program.current_word = 0;
    //Function increases current word before anything else
    
    strcpy(test_program.words[0], "Hello"); //arbitrary word
    strcpy(test_program.words[1], "then");
    strcpy(test_program.words[2], "{");
    strcpy(test_program.words[3], "}");
    
    if (conditional(&test_program) == TRUE){        
        fprintf(test_results, "\nConditional test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nConditional test 2: Failed");
    }
    
    //Passes an incorrect(empty) if statement, should return FALSE 
    no_of_tests += 1;
    test_program.current_word = 0;
    //Function increases current word before anything else
    
    strcpy(test_program.words[0], "Hello");
    strcpy(test_program.words[1], "then");
    strcpy(test_program.words[2], "Hello");
    strcpy(test_program.words[3], "}");
    
    if (conditional(&test_program) == FALSE){        
        fprintf(test_results, "\nConditional test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nConditional test 3: Failed");
    }
    
    //Passes an incorrect if statement, should return FALSE 
    no_of_tests += 1;
    test_program.current_word = 0;
    //Function increases current word before anything else
    
    strcpy(test_program.words[0], "Hello");
    strcpy(test_program.words[1], "then");
    strcpy(test_program.words[2], "{");
    strcpy(test_program.words[3], "green");
    
    if (conditional(&test_program) == FALSE){        
        fprintf(test_results, "\nConditional test 4: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nConditional test 4: Failed");
    }
    
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
}

int test_loop(FILE *test_results){
    Prog test_program;
    int pass_count = 0, no_of_tests = 0;
    initialise_arrays(&test_program);
   
    no_of_tests += 1;
    //Tests an empty for loop, correct syntax so should return TRUE
    test_program.current_word = 0;
    
    strcpy(test_program.words[0], "iterations");
    strcpy(test_program.words[1], "5");
    strcpy(test_program.words[2], "to");
    strcpy(test_program.words[3], "iterations");
    strcpy(test_program.words[4], "10");
    strcpy(test_program.words[5], "{");
    strcpy(test_program.words[6], "}");
    
    if (loop(&test_program) == TRUE){        
        fprintf(test_results, "\nLoop test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nLoop test 1: Failed");
    }
    
    no_of_tests += 1;
    //Tests an empty for loop, incorrect syntax so should return FALSE
    test_program.current_word = 0;
    
    strcpy(test_program.words[0], "iterations");
    strcpy(test_program.words[1], "5");
    strcpy(test_program.words[2], "to");
    strcpy(test_program.words[3], "iterations");
    strcpy(test_program.words[4], "10");
    strcpy(test_program.words[5], "{");
    strcpy(test_program.words[6], "NOT_FINISHED");
    
    if (loop(&test_program) == FALSE){        
        fprintf(test_results, "\nLoop test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nLoop test 2: Failed");
    }
    
    no_of_tests += 1;
    //Tests an empty for loop, incorrect variable used so should return FALSE
    test_program.current_word = 0;
    
    strcpy(test_program.words[0], "colour");
    strcpy(test_program.words[1], "blue");
    strcpy(test_program.words[2], "to");
    strcpy(test_program.words[3], "colour");
    strcpy(test_program.words[4], "red");
    strcpy(test_program.words[5], "{");
    strcpy(test_program.words[6], "}");
    
    if (loop(&test_program) == FALSE){        
        fprintf(test_results, "\nLoop test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nLoop test 3: Failed");
    }
    
    no_of_tests += 1;
    //Tests an empty for loop, start is greater than end so should return FALSE
    test_program.current_word = 0;
    
    strcpy(test_program.words[0], "iterations");
    strcpy(test_program.words[1], "5");
    strcpy(test_program.words[2], "to");
    strcpy(test_program.words[3], "iterations");
    strcpy(test_program.words[4], "4");
    strcpy(test_program.words[5], "{");
    strcpy(test_program.words[6], "}");
    
    if (loop(&test_program) == FALSE){        
        fprintf(test_results, "\nLoop test 4: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nLoop test 4: Failed");
    }
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
    
}

int test_for_loop(FILE *test_results){
    Prog test_program;
    int pass_count = 0, no_of_tests = 0, start, end;
    initialise_arrays(&test_program);
    //Need to pass the program and a start and end value for the loop.
    //Function is passed the code that would be inside the loop.
    //So a combination of correct statements.
    no_of_tests += 1;
    //Tests an empty for loop, correct syntax so should return TRUE
    test_program.current_word = 0;
    
    strcpy(test_program.words[0], "colour");
    strcpy(test_program.words[1], "blue");
    strcpy(test_program.words[2], "shape");
    strcpy(test_program.words[3], "line");
    strcpy(test_program.words[4], "}");
    start = 1;
    end = 3;
    if (for_loop(&test_program, start, end) == TRUE){        
        fprintf(test_results, "\nFor loop test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFor Loop test 1: Failed");
    }
    
    no_of_tests += 1;
    //Tests an empty for loop, incorrect syntax so should return FALSE
    test_program.current_word = 0;
    
    strcpy(test_program.words[0], "colour");
    strcpy(test_program.words[1], "blue");
    strcpy(test_program.words[2], "colour");
    strcpy(test_program.words[3], "line");
    strcpy(test_program.words[4], "}");
    
    start = 1;
    end = 3;
    if (for_loop(&test_program, start, end) == FALSE){        
        fprintf(test_results, "\nFor loop test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_results, "\nFor Loop test 2: Failed");
    }
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return FAILED;
}
 
