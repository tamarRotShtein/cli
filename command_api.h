#ifndef COMMAND_API_H
#define COMMAND_API_H

//in order to add function you need:
//1.add signature
//2.implemnt it in file command_api.cpp
//3.register to the list of all functions

//struct for function
typedef struct function{   
    char * function_name;
    void (* function)(char *);
    struct function* next;
}function;

//function signatures
void calculate(int a,int b);
void calculate_cli(char* params);
void print_name(char* name);
void print_name_cli(char* params);
void say_hello();
void say_hello_cli(char* strParameters);
void start_record_cli(char * params);

//function to split the parameters from the line
char ** split_params(char * line);
//function to register new function
void register_func(char* ,void(*func)(char*));
//function to init the functions array
void init_functions();
//function to exec the command string
void exec_function(char *);
//function to exec the command line
void exec_command_line();


#endif // COMMAND_API_H
