#ifndef _INC_TIME_H_
#define _INC_TIME_H_

/*
   This header is to provide compatibility between the windows method
   GetTickCount() and the linux function gettimeofday()
*/

#include <sys/time.h>

// resolution:
// is the microseconds provided by gettimeofday accurate enough?
// if not, there is a function in <time.h> called clock_gettime()
// that will do nanosecond resolution, but returns the results in a long int
int GetTickCount()
{
    timeval t;
    gettimeofday( &t, NULL );

    return t.tv_usec;

}
#endif // _INC_TIME_H_
