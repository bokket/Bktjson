//
// Created by bokket on 2020/12/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bktjson.h"

static int main_ret=0;
static int test_cnt=0;
static int test_pass=0;


#define EXPECT_EQ_BASE(equality,expect,actual,format) \
    do{\
        test_cnt++;\
        if(equality)                                  \
            test_pass++;                              \
        else{                                         \
            fprintf(stderr,"%s:%d: expect: " format " actual: " format "\n",__FILE__,__LINE__,expect,actual);\
            main_ret = 1;\
            }\
    }while(0)


#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

static void test_parse_null()
{
    bktjson bkt;
    bkt_value v;
    v.type = LEPT_TRUE;
    EXPECT_EQ_INT(LEPT_PARSE_OK, bkt.bkt_parse(&v,"null"));
    EXPECT_EQ_INT(LEPT_NULL, bkt.bkt_get_type(&v));
}

/* ... */

static void test_parse()
{
    test_parse_null();
    /* ... */
}

int main()
{
    test_parse();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}