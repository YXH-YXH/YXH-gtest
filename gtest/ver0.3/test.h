/*************************************************************************
    > File Name: test.h
    > Author: 
    > Mail: 
    > Created Time: Wed 04 Nov 2020 06:54:27 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define NONE "\e[0m"

typedef void (*TestFuncT)();    //定义一个指针变量
struct Function{
    TestFuncT func;
    const char *str;
};
void add_function(TestFuncT,const char*);
extern int test_cnt,test_right;
#define TEST(a,b)\
    void a##_##b();\
    __attribute__((constructor))\
    void add_function_##a##_##b(){\
        add_function(a##_##b,#a"_"#b);\
    }\
    void a##_##b()

#define EXPECT(a,b,cmp){\
    if( (a) cmp (b) )\
        printf(GREEN"[-----------]"NONE),test_right++;\
    else\
        printf(RED"[-----------]"NONE);\
    printf(" %s %s %s ? %s\n",#a,#cmp,#b,((a) cmp (b)? GREEN"True"NONE : RED"FALSE"NONE));\
    test_cnt++;\
}

#define EXPECT_EQ(a,b) EXPECT(a,b,==)
#define EXPECT_NE(a,b) EXPECT(a,b,!=)
#define EXPECT_LT(a,b) EXPECT(a,b,<)
#define EXPECT_LE(a,b) EXPECT(a,b,<=)
#define EXPECT_GT(a,b) EXPECT(a,b,>)
#define EXPECT_GE(a,b) EXPECT(a,b,>=)
//#define EXPECT_EQ(a,b)\
    if((a)==(b))\
        printf(GREEN"[-----------]"NONE);\
    else\
        printf(RED"[-----------]"NONE);\
    printf(" %s == %s ? ",#a,#b);\
    if((a)==(b))\
        printf(GREEN"TRUE"NONE),test_right++;\
    else\
        printf(RED"FALSE"NONE);\
    printf("\n");\
    test_cnt++;
//    printf((a)==(b)?GREEN:RED,"[----------]",NONE," %s == %s ? ",(a)==(b)?GREEN:RED,"%s",NONE,"\n",#a,#b,(a)==(b)?"TRUE":"FALSE");
int RUN_ALL_TESTS();
#endif
