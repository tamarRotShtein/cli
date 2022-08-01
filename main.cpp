#include <QCoreApplication>
#include "command_api.h"
#include <dlfcn.h>
#include "gaz_cam.h"
#include <unistd.h>


int main(int argc, char *argv[])
{   
   //exec_command_line();
    void* libHandle= dlopen("/home/tamar/amazon_project/final/build-gaz_cam_api-Desktop-Debug/libgaz_cam_api.so.1.0.0",RTLD_LAZY);
    assert (libHandle);
    gazapi_t *p_gaz;
    p_gaz = (gazapi_t*)dlsym(libHandle,"p_gaz_api");
    assert(p_gaz);
    void* handle=p_gaz->init();
    handler* h=(handler*)(handle);
    p_gaz->start_record(handle);
    while(1)
    {
        printf("n\n");
        sleep(20);
    }
    QCoreApplication a(argc, argv);
    return a.exec();
}



