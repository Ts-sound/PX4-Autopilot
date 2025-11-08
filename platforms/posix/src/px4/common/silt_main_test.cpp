#include <unistd.h>
#include <iostream>

#ifdef __PX4_SITL_MAIN_OVERRIDE
extern "C" {
int SITL_MAIN(int argc, char **argv);
}

#endif


int main(int argc, char **argv){

#ifdef __PX4_SITL_MAIN_OVERRIDE

printf("start SITL_MAIN");

return SITL_MAIN(argc,argv);

#endif

return 0;

}
