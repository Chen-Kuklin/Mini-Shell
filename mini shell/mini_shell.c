
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX 510
//a method that frees the allocations
void freeAllocation(char** str)
{
	for (int i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	free(str);
}
char** sepArrWords(char *c)
{
int i = 0, count = 0, flag = 0;
while (1)
{
while (c[i] != ' ')//go through the word until you get to a space
{

if (c[i] == '\0') //got to the end of the string
break;
flag = 1;//a sign to count a word
i++;
}
if (flag == 1) {
count++;
flag = 0;
}
if (c[i] == '\0')//got to the end of the string
break;
i++;
}
char token[MAX];
strcpy(token, c);//make a copy of the string
char* ptr = strtok(token, " ");//recuse the words
char** newArr = (char**)malloc(sizeof(char*) * (count + 1));
if (newArr == NULL)
{
printf("error");
exit(1);
}
i = 0;
while (ptr != NULL)//until after the last word
{
newArr[i] = (char*)malloc(sizeof(char)*(strlen(ptr)+1));
if (newArr[i] == NULL)
{
printf("error");
exit(1);
}
strcpy(newArr[i], ptr); //inserts the new words into the array
ptr = strtok(NULL, " ");//moves on to the next word
i++;
}

newArr[i] = NULL;
return newArr;

}

int main()
{
  char hostname[128];
char * login;
 

gethostname(hostname, sizeof hostname);        
login=getlogin();

int x;
    char str[MAX];
      __pid_t son;


 while(1)//go until the input is exit
  {
    printf("%s@%s$",login,hostname);  
    fgets(str, MAX, stdin);
     if(strcmp(str,"exit\n")==0)
       exit(1);//if the input is exit the program will exit without error massage
    str[strlen(str)-1]='\0';//delete the /n so the command will be recognized
    
    char**mat=sepArrWords(str);//send to the method that seperates the words
    son = fork();//create a process son
    if(son==-1){
      printf("error");
      exit(1);
    }
      
    if(son==0)
    {
      x=execvp(mat[0],mat);//the son goes to a different program
    if(x==-1)//if the execvp failed
    {
        printf("%s:command not found\n",mat[0]);
        freeAllocation(mat);
        exit(0);
    }
freeAllocation(mat);//free the memory
    }
   if(son>0)
       wait(NULL);//wait until son process is done
       

    }

 
return 0;
}
 
