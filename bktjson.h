//
// Created by bokket on 2020/12/10.
//

#ifndef BKTJSON_BKTJSON_H
#define BKTJSON_BKTJSON_H

#include <cassert>

/**
 *  null: 表示为 null
    boolean: 表示为 true 或 false
    number: 一般的浮点数表示方式
    string: 表示为 "..."
    array: 表示为 [ ... ]
    object: 表示为 { ... }
 */
typedef enum
{
    BKT_NULL,
    BKT_FALSE,
    BKT_TRUE,
    BKT_NUMBER,
    BKT_STRING,
    BKT_ARRAY,
    BKT_OBJECT
}bkt_type;

/**
 * 若一个 JSON 只含有空白，传回 BKT_PARSE_EXPECT_VALUE。
   若一个值之后，在空白之后还有其他字符，传回 BKT_PARSE_ROOT_NOT_SINGULAR。
   若值不是那三种字面值，传回 BKT_PARSE_INVALID_VALUE。
 */
enum
{
    BKT_PARSE_OK=0,
    BKT_PARSE_EXPECT_VALUE,
    BKT_PARSE_INVALID_VALUE,
    BKT_PARSE_ROOT_NOT_SINGULAR
};

typedef struct
{
    bkt_type type;
}bkt_value;

typedef struct
{
    const char* json_;
}bkt_context;

class bktjson
{
public:
    bktjson();
    ~bktjson();
    int bkt_parse(bkt_value* v,const char* json);
    bkt_type bkt_get_type(const bkt_value* v);

    static void bkt_parse_whitespace(bkt_context* c);
    static int bkt_parse_null(bkt_context* c,bkt_value* v);
    static int bkt_parse_true(bkt_context* c, bkt_value *v);
    static int bkt_parse_false(bkt_context* c, bkt_value *v);

    static int bkt_parse_value(bkt_context* c,bkt_value* v);
};

#endif //BKTJSON_BKTJSON_H