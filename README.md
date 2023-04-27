# Mini-Shell
Supports the standard operations of the real Linux shell
"mini shell" is a basic command-line shell written in C that can execute user input commands. The program reads input commands from the user and separates them into an
array of strings. It then forks a child process and executes the command using the execvp() function. If the command is not recognized, the shell returns an error message. The program also features a method that frees the memory allocated for the array of strings. 
mini shell is a useful project for those who want to learn more about C programming and the basics of shell scriptin.
