/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Nov 2020 06:59:36 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include"test.h"
using namespace std;
int add(int a,int b){return a+b;}
TEST(TestFunc,add)
{
    EXPECT_EQ(add(2,3),5);
    EXPECT_EQ(add(1,3),4);
    EXPECT_EQ(add(2,2),3);
}
TEST(TestFunc,add2)
{
    EXPECT_EQ(add(2,0),2);
    EXPECT_EQ(add(1,3),4);
    EXPECT_EQ(add(2,2),4);
}
int main()
{
    return RUN_ALL_TESTS();
}
