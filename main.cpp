#include <QCoreApplication>
#include "command_api.h"
#include <dlfcn.h>
#include "gas_cam.h"
#include <unistd.h>
#include <signal.h>

//insert to the command.c

static handler* my_handler;
static gazapi_t *p_gaz;
int is_active =1;
void sig_handler(int sig_no)
{
    printf("sigint recieved");
    p_gaz->stop_record(my_handler);
  is_active=0;
    exit(0);
}
int main(int argc, char *argv[])
{
    //signal(SIGINT, sig_handler);
    printf("kkkkkk");
    //exec_command_line();
    //function to load library
    void* libHandle= dlopen("/home/tamar/amazon_project/final/build-gaz_cam_api-Desktop-Debug/libgaz_cam_api.so.1.0.0",RTLD_LAZY);
    assert (libHandle);

    p_gaz = (gazapi_t*)dlsym(libHandle,"p_gaz_api");
    assert(p_gaz);
    //needs to be global for all
    void* handle=p_gaz->init();   //in startrecordcli
    my_handler=(handler*)(handle);
    //-------------------------------
    p_gaz->start_record(handle);
    //catch the sigint


    while(is_active)
    {
        //printf("n\n");
        sleep(1);
    }
   // QCoreApplication a(argc, argv);
    //return a.exec();
}



