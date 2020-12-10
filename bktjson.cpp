//
// Created by bokket on 2020/12/10.
//

#include "bktjson.h"
int bktjson::bkt_parse(bkt_value *v, const char *json)
{
    bkt_context c;
    assert(v!=NULL);
    c.json_=json;
    v->type=BKT_NULL;
    bkt_parse_whitespcae(&c);

    if(bkt_parse_value(&c,v)==BKT_PARSE_OK)
    {
        bkt_parse_whitespace(&c);
        if(c.json_ !='\0' )
            ret=BKT_PARSE_ROOT_NOT_SINGULAR;
    }
    return ret;
}

void bktjson::bkt_parse_whitespace(bkt_context *c)
{
    const char* p=c->json_;
    while(*p==' ' || *p=='\t' || *p=='\n' || *p=='\r')
        p++;
    c->json_=p;
}


/* null  = "null" */
int bktjson::bkt_parse_null(bkt_context* c, bkt_value *v)
{
    EXPECT(c,'n');
    if(c->json_[0]!='u' || c->json_[1]!='l' || c->json_[2]!='l')
        return BKT_PARSE_INVALID_VALUE;
    c->json_+=3;
    v->type=BKT_NULL;
    return BKT_PARSE_OK;
}

int bktjson::bkt_parse_true(bkt_context *c, bkt_value *v)
{
    EXPECT(c,'t');
    if(c->json_[0]!='r' || c->json_[1]!='u' || c->json_[2]!='e')
        return BKT_PARSE_INVALID_VALUE;
    c->json_+=3;
    v->type=BKT_TRUE;
    return BKT_PARSE_OK;
}

int bktjson::bkt_parse_false(bkt_context *c, bkt_value *v)
{
    EXPECT(c,'f');
    if(c->json_[0]!='a' || c->json_[1]!='l' || c->json_[2]!='s' || c->json_[3]!='e')
        return BKT_PARSE_INVALID_VALUE;
    c->json_+=4;
    v->type=BKT_FALSE;
    return BKT_PARSE_OK;
}

int bktjson::bkt_parse_value(bkt_context *c, bkt_value *v)
{
    switch (*c->json_)
    {
        case 't':
            return bkt_parse_true(c,v);
        case 'f':
            return bkt_parse_false(c,v);
        case 'n':
            return bkt_parse_null(c,v);
        case '\0':
            return BKT_PARSE_EXPECT_VALUE;
        default:
            return BKT_PARSE_INVALID_VALUE;
    }
}