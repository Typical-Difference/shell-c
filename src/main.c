#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int running_flag = 1;

  while(running_flag){
    // Flush after every printf
    setbuf(stdout, NULL);
    
    // TODO: Uncomment the code below to pass the first stage
    printf("$ ");
    char command[1024];
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0'; // Remove the last new line character after user inputs ENTER

    //print error for invalid messages
    if(strncmp("exit", command, 4) && isdigit(command[4] - ' ')){
      running_flag = 0;
    }
    else{
      printf("%s: command not found", command);
    }
  }
  
  return 0;
}
