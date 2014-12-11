#include "parser.h"

int parse(Interface interface, Draw **fractal) {
   //test_parser(interface); //Test will create its own fractals and test the functions in this module
	char input[NO_WORDS][MAX_LENGTH];
	action actions[FIRST_WORD_SIZE];
	printf("\nstart");
	create_struct_array(actions);	//Creates an array of structures containing the actions and relevant attributes of #defined arrays above 
	make_default(interface, fractal);
	get_input(actions, input, fractal);  //Takes values from file and puts them in the fractal structure	
/*    if(strcmp(fractal.type, "triangle") == 0){
        triangle(&fractal, sw, interface);
    }
    else{
        Draw_sdl(&fractal, sw, interface);
	}*/
	printf("\nIn main:");
	printf("\nType: %s", fractal->type);
	printf("\nColour: %s", fractal->colour);
    printf("\nColour: %s", fractal->colour);
	printf("\nshape: %s", fractal->shape);
	
	return 0;
}



void make_default(Interface interface, Draw ***fractal){
    //Call function and check it changes what it should
  printf("\ndefault");
  fractal->colour = (char*)malloc(4*sizeof(char));
	strcpy(fractal->colour, "red"); 
	fractal->move = (char*)malloc(3*sizeof(char));
	strcpy(fractal->move, "up");
	fractal->size = 10;
	fractal->shape = (char*)malloc(7*sizeof(char));
	strcpy(fractal->shape, "square");
	fractal->startx = interface.canvas.rect.x + (interface.canvas.rect.w/2) - size;
	fractal->starty = interface.canvas.rect.y + (interface.canvas.rect.h/2) - size;
	fractal->endx = WIN_WIDTH/2 + 10;
	fractal->endy = WIN_HEIGHT/2 + 10; 
    //strdup(fractal->type, "triangle");
	fractal->type = (char*)malloc(9*sizeof(char));
	strcpy(fractal->type, "tree");
	printf("\nType: %s", fractal->type);
    fractal->iterations = 1;
}

int get_input(action *actions, char input[NO_WORDS][MAX_LENGTH], Draw *fractal) {
	
	//char *first_word[] = FIRST_WORD;
	//char *second_word[] = SECOND_WORD;
	printf("\ninput");
	char c = 'f';
	FILE *fp;
	if((fp = fopen("instruction.txt", "r")) == NULL)
	{
		fprintf(stderr, "\nCouldn't open file!\n");
		return NO;
	}
	while(c != EOF){
		if(read_file_line(fp, actions, input) == YES){
			update_values(fractal, input);
	
		}
		c = getc(fp);
		
			//clear_buffer();
	} 
	fclose(fp);
	return YES;
}

int read_file_line(FILE *fp, action *actions, char input[NO_WORDS][MAX_LENGTH]){
	int found_first = NO;
	int found_second = NO;
	int which_action = 0;
	int counter = 0;
	int i = 0, j = 0;
	char tmp_char;
	printf("\nfile line");
	memset(input[0], '\0', MAX_LENGTH);
	memset(input[1], '\0', MAX_LENGTH);
	while ((tmp_char = getc(fp)) != ';') {
	    if(tmp_char == EOF){
	        printf("\nEnd of file reached");
	        return NO;
	    }
	    
        if(tmp_char == ' ' || tmp_char == '\n'){
          if(tmp_char == ' ') {
	        i++;
	        j = 0;
	        counter++;
	        printf("\nFirst word: '%s'", input[0]);
          }
          if(tmp_char == '\n') {
          }
	    }        
	    else{
	       input[i][j] = tmp_char;
	       j++;
	    }
	}
	printf("\nSecond word: %s", input[1]);
	counter++;
	/*	if(j != -1){
			printf("\nYou have entered %d instructions, you need 2.\n", j);
			return NO;
		}
		printf("\nReached end of file.\n");
	    return YES;*/
    if(counter == 2){
		for(i = 0, found_first = NO; i<FIRST_WORD_SIZE && found_first == NO; i++){
			if (strcmp(input[0], actions[i].name) == 0 ) {
				found_first = YES;
				which_action = i;
			}
		}
	
		if(found_first == NO){
			printf("Your first word is not a valid function\n");
			return NO;
		}
	    for(i = 0, found_second = NO; strcmp(actions[which_action].instruction[i], "STOP") != 0 && found_second == NO && found_first == YES; i++){
		    if (strcmp(input[1], actions[which_action].instruction[i]) == 0 ) {
				found_second = YES;
			}
		    else if (atoi(input[1]) != 0){       //Will allow user to enter any integer, for any attribute that would be an integer
		        found_second = YES;
		    }
			
		}
		if(found_first == YES && found_second == NO){
			printf("Your second word is not valid with your chosen action\n");
			return NO;
		}
		return YES;
    }
    
    if(counter > 2){	
    return NO;
}

void update_values(Draw *fractal, char input[NO_WORDS][MAX_LENGTH]){
	int i;
	char *first_word[FIRST_WORD_SIZE]= FIRST_WORD;
	printf("\nupdate");
	for(i = 0; i < FIRST_WORD_SIZE; i++){
		if(strcmp(first_word[i], input[0]) == 0){
			printf("\nStrings match.\n");
			assign_value(fractal, i, input[1]);
		}	
	}
}

void assign_value(Draw *fractal, action_word i, char *input){
	printf("\nIn assign\n");
	switch(i){
		case colour:
			printf("\nFound colour: %s\n", input);
			fractal->colour = (char*)malloc(strlen(input)*sizeof(char));
			strcpy(fractal->colour, input);
			break;
		case move:
			fractal->move = (char*)malloc(strlen(input)*sizeof(char));
			strcpy(fractal->move, input);
			break;
		case size:
			fractal->size = atoi(input);
        	fractal->startx -= (size/2);
	        fractal->starty -= (size/2);
            // In order to centre the image properly.
//   HAVE NOT GOT TIME TO MAKE WORK PROPERLY RIGHT NOW WILL FIX LATER PROBABLY.
			break;
		case shape:
			fractal->shape = (char*)malloc(strlen(input)*sizeof(char));
			strcpy(fractal->shape, input);
			break;
		case startx:
		    fractal->startx = atoi(input);
		    break;
		case starty:
		    fractal->starty = atoi(input);
		    break; 
		case endx:
		    fractal->endx = atoi(input);
		    break; 
		case endy:
		    fractal->endy = atoi(input);
		    break;  
		case type:
		    printf("\nIn case type");
		    fractal->type = (char*)malloc(strlen(input)*sizeof(char));
			strcpy(fractal->type, input);
			break;		
        case iterations:
            fractal->iterations = atoi(input);
            break;
	}
	printf("\nEnd assign\n");
}

void clear_buffer(void){

	while (getchar() != '\n'){
	}
	
}

void create_struct_array(action *actions)
{
    printf("\ncreate");
	int i, j, k, l, cnt = 0, array_cnt = 0;
	char *first_word[FIRST_WORD_SIZE]= FIRST_WORD;
	char *second_word[SECOND_WORD_SIZE]= SECOND_WORD;
	
	for(i = 0; i < FIRST_WORD_SIZE && array_cnt < SECOND_WORD_SIZE; i++){
		actions[i].name = (char*)malloc(1 * sizeof(char[strlen(first_word[i])]));
		actions[i].name = first_word[i];
	
		for(j = array_cnt; strcmp(second_word[j], "NEXT") != 0; j++){
				
				cnt += 1;
		}
		array_cnt += cnt;
		
		actions[i].instruction = (char**)malloc(cnt * sizeof(char*));
		
		for(k = array_cnt - cnt, l = 0; k < array_cnt; k++, l++){
			
			actions[i].instruction[l] = (char*)malloc(strlen(second_word[k]) * sizeof(char));
			strcpy(actions[i].instruction[l], second_word[k]);
			/*for(l = 0; l < strlen(second_word[k]); l++){
				actions[i].instruction[k][l] = second_word[k][l];
			}*/
			//printf("\nFirst word: %s\n", actions[i].name);
			//printf("\nSecond word: %s\n", actions[i].instruction[l]);
		}
		cnt = 0;
		array_cnt += 1;
	}	
	printf("\nend ");
}

