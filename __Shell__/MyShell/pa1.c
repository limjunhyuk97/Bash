/**********************************************************************
 * Copyright (c) 2021
 *  Sang-Hoon Kim <sanghoonkim@ajou.ac.kr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#include <string.h>

#include "types.h"
#include "list_head.h"
#include "parser.h"

LIST_HEAD(history);

struct block {
    struct list_head list;
    char *command;
};


/***********************************************************************
 * run_command()
 *
 * DESCRIPTION
 *   Implement the specified shell features here using the parsed
 *   command tokens.
 *
 * RETURN VALUE
 *   Return 1 on successful command execution
 *   Return 0 when user inputs "exit"
 *   Return <0 on error
 */
static int run_command(int nr_tokens, char *tokens[])
{
    int stat, result = 0;
    pid_t waitPID, PID = fork();
    
    // parent process
    if(PID > 0) {
        
        // get exit code
        waitPID = wait(&stat);
        
        // error occured in child process + exit status
        if(stat > 0) fprintf(stderr, "Unable to execute %s\n", tokens[0]);
        
        // exit
        if(strcmp(tokens[0], "exit") == 0) waitPID = 0;
        
        // cd
        else if(strcmp(tokens[0], "cd") == 0){
            char *curloc = getenv("HOME");
            if(nr_tokens == 1) {
                result = chdir(curloc);
            }
            else {
                if(tokens[1][0] == '~'){
                    char *curdir = (char *)malloc(sizeof(char) * 200), *curloc = getenv("HOME");
                    strcpy(curdir, curloc);
                    int token_len = (int)strlen(tokens[1]);
                    for(int i=1; i<token_len; ++i) {
                        tokens[1][i-1] = tokens[1][i];
                    }
                    tokens[1][token_len-1] = '\0';
                    strcat(curdir, tokens[1]);
                    result = chdir(curdir);
                    free(curdir);
                }
                else {
                    result = chdir(tokens[1]);
                }
            }
        }
        
        // history
        else if(strcmp(tokens[0], "history") == 0) {
            int index = 0;
            if(!list_empty(&history)) {
                struct block * cur = list_last_entry(&history, struct block, list);
                while(&history != &cur->list) {
                    fprintf(stderr, "%2d: %s", index, cur->command);
                    index += 1;
                    cur = list_prev_entry(cur, list);
                }
            }
        }
        
        // !
        else if(strcmp(tokens[0], "!") == 0) {
            int target = atoi(tokens[1]), index = 0, result = -1;
            if(!list_empty(&history)) {
                struct block * cur = list_last_entry(&history, struct block, list);
                while(&history != &cur->list && index != target) {
                    index += 1;
                    cur = list_prev_entry(cur, list);
                }
                if(index == target) {
                    if (parse_command(cur->command, &nr_tokens, tokens) == 0) result = 1;
                    else return run_command(nr_tokens, tokens);
                }
            }
        }
        
        // error handling
        if(result < 0) fprintf(stderr, "Unable to execute commands\n");
        
        return waitPID;
    }
    
    // child process
    else if(PID == 0){
        
        // cd, exit, history, ! : chdir() 정상=0 / 에러=-1
        if(strcmp(tokens[0], "cd") == 0 || strcmp(tokens[0], "exit") == 0) result = 0;
        if(strcmp(tokens[0], "history") == 0 || strcmp(tokens[0], "!") == 0) result = 0;
        // execvp 에러=-1 / 정상>0
        else result = execvp(tokens[0], tokens);
        
        // exit 정상=0 / 에러=1
        if(result <0) exit(EXIT_FAILURE);
        else exit(EXIT_SUCCESS);
    }
    
    // other cases
    else{
        fprintf(stderr, "Process Execution Error");
        return ECHILD;
    }
    
}


/***********************************************************************
 * append_history()
 *
 * DESCRIPTION
 *   Append @command into the history. The appended command can be later
 *   recalled with "!" built-in command
 */
static void append_history(char * const command)
{
    // Constructing node
    struct block * node = (struct block *)malloc(sizeof(struct block));
    
    // Copying command
    node->command = (char *)malloc(sizeof(char) * MAX_COMMAND_LEN);
    strcpy(node->command, command);
    
    // initializing list
    INIT_LIST_HEAD(&(node->list));
    
    // Add node to history
    list_add(&(node->list), &history);
    
}


/***********************************************************************
 * initialize()
 *
 * DESCRIPTION
 *   Call-back function for your own initialization code. It is OK to
 *   leave blank if you don't need any initialization.
 *
 * RETURN VALUE
 *   Return 0 on successful initialization.
 *   Return other value on error, which leads the program to exit.
 */
static int initialize(int argc, char * const argv[])
{
	return 0;
}


/***********************************************************************
 * finalize()
 *
 * DESCRIPTION
 *   Callback function for finalizing your code. Like @initialize(),
 *   you may leave this function blank.
 */
static void finalize(int argc, char * const argv[])
{

}


/*====================================================================*/
/*          ****** DO NOT MODIFY ANYTHING BELOW THIS LINE ******      */
/*          ****** BUT YOU MAY CALL SOME IF YOU WANT TO.. ******      */
static int __process_command(char * command)
{
	char *tokens[MAX_NR_TOKENS] = { NULL };
	int nr_tokens = 0;

	if (parse_command(command, &nr_tokens, tokens) == 0)
		return 1;

	return run_command(nr_tokens, tokens);
}

static bool __verbose = true;
static const char *__color_start = "[0;31;40m";
static const char *__color_end = "[0m";

static void __print_prompt(void)
{
	char *prompt = "$";
	if (!__verbose) return;

	fprintf(stderr, "%s%s%s ", __color_start, prompt, __color_end);
}

/***********************************************************************
 * main() of this program.
 */
int main(int argc, char * const argv[])
{
	char command[MAX_COMMAND_LEN] = { '\0' };
	int ret = 0;
	int opt;

	while ((opt = getopt(argc, argv, "qm")) != -1) {
		switch (opt) {
		case 'q':
			__verbose = false;
			break;
		case 'm':
			__color_start = __color_end = "\0";
			break;
		}
	}

	if ((ret = initialize(argc, argv))) return EXIT_FAILURE;

	/**
	 * Make stdin unbuffered to prevent ghost (buffered) inputs during
	 * abnormal exit after fork()
	 */
	setvbuf(stdin, NULL, _IONBF, 0);

	while (true) {
		__print_prompt();

		if (!fgets(command, sizeof(command), stdin)) break;

		append_history(command);
		ret = __process_command(command);

		if (!ret) break;
	}

	finalize(argc, argv);

	return EXIT_SUCCESS;
}
