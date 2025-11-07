#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  int running_flag = 1;
  char *valid_commands[] = {"echo", "type", "exit"};
  int valid_commands_size = 3;

  while(running_flag){
    // Flush after every printf
    setbuf(stdout, NULL);
    
    // TODO: Uncomment the code below to pass the first stage
    printf("$ ");
    char command[1024];
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0'; // Remove the last new line character after user inputs ENTER

    //print error for invalid messages
    if(!strncmp(command, "exit 0", 6) || !strncmp(command, "exit 1", 6)){ //strncmp returns 0 if strings are equal
      running_flag = 0;
    }
    else if(!(strncmp(command, "echo ", 5))){
      char echoed_string[1019];
      strncpy(echoed_string, command + 5, 1019);
      printf("%s\n", echoed_string);
    }
    else if(!(strncmp(command, "type ", 5))){
      char argument[1019];
      strncpy(argument, command + 5, 1019);
      int match_found = 0;
      for(int i = 0; i < valid_commands_size; i++){
        if(!strcmp(argument, valid_commands[i])){
          match_found = 1;
        }
      }
      if(match_found){
        printf("%s is a shell builtin\n", argument);
      }
      else{
        printf("%s: not found\n", argument);
      }
    }
    else{
      printf("%s: command not found\n", command);
    }
  }
  
  return 0;
}
