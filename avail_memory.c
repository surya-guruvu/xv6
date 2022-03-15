#include "types.h"
#include "date.h"
#include "user.h"

int 
main(int argc,char *argv[]) 
{
	int n=memtop();
    printf(1, "available memory: %d\n", n);
    exit();
} 
