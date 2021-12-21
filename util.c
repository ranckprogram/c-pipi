
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <float.h>

#include "util.h"



/* Return true if the specified path is just a file basename without any
 * relative or absolute path. This function just checks that no / or \
 * character exists inside the specified path, that's enough in the
 * environments where Redis runs. */
int pathIsBaseName(char *path) {
    return strchr(path,'/') == NULL && strchr(path,'\\') == NULL;
}

#ifdef UTIL_TEST_MAIN
#include <assert.h>

void test_string2ll(void) {
    char buf[32];
    long long v;

    /* May not start with +. */
    strcpy(buf,"+1");
    assert(string2ll(buf,strlen(buf),&v) == 0);

    /* Leading space. */
    strcpy(buf," 1");
    assert(string2ll(buf,strlen(buf),&v) == 0);

    /* Trailing space. */
    strcpy(buf,"1 ");
    assert(string2ll(buf,strlen(buf),&v) == 0);

    /* May not start with 0. */
    strcpy(buf,"01");
    assert(string2ll(buf,strlen(buf),&v) == 0);

    strcpy(buf,"-1");
    assert(string2ll(buf,strlen(buf),&v) == 1);
    assert(v == -1);

    strcpy(buf,"0");
    assert(string2ll(buf,strlen(buf),&v) == 1);
    assert(v == 0);

    strcpy(buf,"1");
    assert(string2ll(buf,strlen(buf),&v) == 1);
    assert(v == 1);

    strcpy(buf,"99");
    assert(string2ll(buf,strlen(buf),&v) == 1);
    assert(v == 99);

    strcpy(buf,"-99");
    assert(string2ll(buf,strlen(buf),&v) == 1);
    assert(v == -99);

    strcpy(buf,"-9223372036854775808");
    assert(string2ll(buf,strlen(buf),&v) == 1);
    assert(v == LLONG_MIN);

    strcpy(buf,"-9223372036854775809"); /* overflow */
    assert(string2ll(buf,strlen(buf),&v) == 0);

    strcpy(buf,"9223372036854775807");
    assert(string2ll(buf,strlen(buf),&v) == 1);
    assert(v == LLONG_MAX);

    strcpy(buf,"9223372036854775808"); /* overflow */
    assert(string2ll(buf,strlen(buf),&v) == 0);
}

void test_string2l(void) {
    char buf[32];
    long v;

    /* May not start with +. */
    strcpy(buf,"+1");
    assert(string2l(buf,strlen(buf),&v) == 0);

    /* May not start with 0. */
    strcpy(buf,"01");
    assert(string2l(buf,strlen(buf),&v) == 0);

    strcpy(buf,"-1");
    assert(string2l(buf,strlen(buf),&v) == 1);
    assert(v == -1);

    strcpy(buf,"0");
    assert(string2l(buf,strlen(buf),&v) == 1);
    assert(v == 0);

    strcpy(buf,"1");
    assert(string2l(buf,strlen(buf),&v) == 1);
    assert(v == 1);

    strcpy(buf,"99");
    assert(string2l(buf,strlen(buf),&v) == 1);
    assert(v == 99);

    strcpy(buf,"-99");
    assert(string2l(buf,strlen(buf),&v) == 1);
    assert(v == -99);

#if LONG_MAX != LLONG_MAX
    strcpy(buf,"-2147483648");
    assert(string2l(buf,strlen(buf),&v) == 1);
    assert(v == LONG_MIN);

    strcpy(buf,"-2147483649"); /* overflow */
    assert(string2l(buf,strlen(buf),&v) == 0);

    strcpy(buf,"2147483647");
    assert(string2l(buf,strlen(buf),&v) == 1);
    assert(v == LONG_MAX);

    strcpy(buf,"2147483648"); /* overflow */
    assert(string2l(buf,strlen(buf),&v) == 0);
#endif
}

int main(int argc, char **argv) {
    test_string2ll();
    test_string2l();
    return 0;
}
#endif
