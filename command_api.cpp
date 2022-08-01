#include "command_api.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<stdarg.h>
#define MAX_CHARS 100

static function*functions=NULL;


void print_name_cli(char* str_parameters)
{
    char** parameters=split_params(str_parameters);
    char * name;
    parameters!=NULL?name=parameters[0]:name="";
    print_name(name);
}
void print_name(char* name)
{
    fprintf(stderr,"%s\n",name);
}
void say_hello_cli(char* str_parameters)
{
   say_hello();
}
void say_hello()
{
    fprintf(stderr,"%s\n","hello");
}
void calculate(int a,int b)
{
    fprintf(stderr,"%d\n",a+b);
}
void calculate_cli(char* params)
{
    int x=0,y=0;
    char** parameters=split_params(params);
    x=atoi(parameters[0]);
    y=atoi(parameters[1]);
    calculate(x,y);
}
void start_record_cli(char * params)
{

}


char ** split_params(char * line)
{
  char ** params=NULL;
  int num_params=0;
  while(*line!='\0')
  {
      int index=strcspn(line," ");
      char * current_param=NULL;
      if(index!=strlen(line))
      {
          current_param=strndup(line,index);
          line+=index;
              while(*line==' ')
          {
             line++;
          }
      }
      else
      {
          current_param=line;
          line+=index;
      }
      params=(char **)realloc(params,sizeof(char*)*(num_params+1));
      params[num_params++]=current_param;
  }
  return params;
}

void register_func(char* name,void(*func)(char*))
{
    function* f1=(function*)malloc(sizeof(function));
    f1->function_name=name;
    f1->function=func;
    if(functions==NULL)
    {
        functions=f1;
        functions->next=NULL;
    }
    else
    {
       f1->next=functions;
       functions=f1;
    }
}
void init_functions()
{
    register_func("print_name\0",print_name_cli);
    register_func("say_hello\0",say_hello_cli);
    register_func("calculate\0",calculate_cli);
}

void exec_function(char * line)
{
  //cut the function name from the string
    while(*line==' ')
       {
           line++;
       }
       int index=strcspn(line," ");
       char * function_name=strndup(line,index);
       line+=index;
       while(*line==' ')
       {
              line++;
       }
  //find the suitable function
  function* f=functions;
      while(f!=NULL)
      {
          if(strcmp(f->function_name,function_name)==0)
          {
              f->function(line);
              break;
          }
          f=f->next;
      }
  //if there wasn't found suitable function
  if(f==NULL)
      fprintf(stderr,"command not found\n");
  free(function_name);
}
void exec_command_line()
{
    init_functions();
    while(1)
    {
        char  str[MAX_CHARS];
        fgets(str,MAX_CHARS,stdin);
        int index=strcspn(str,"\n");
        str[index]='\0';
        exec_function(str);

    }
}

