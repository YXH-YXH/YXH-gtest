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
double add2(double a,double b){return a+b;}
TEST(TestFunc,add)
{
    EXPECT_EQ(add(2,3),5);
    EXPECT_EQ(add(1,3),4);
    EXPECT_EQ(add(2,2),3);

    EXPECT_NE(add(2,2),3);
    EXPECT_LT(add(2,2),3);
    EXPECT_LE(add(2,2),3);
    EXPECT_GT(add(2,2),3);
    EXPECT_GE(add(2,2),3);
}
TEST(TestFunc,add2)
{
    EXPECT_EQ(add2(2.5,0.5),2.0);
    EXPECT_EQ(add2(1.5,3.4),4.5);
    EXPECT_EQ(add2(2.1,2.7),4);
    
    EXPECT_NE(add2(2.1,2.7),4.0);
    EXPECT_LT(add2(2.1,2.7),4.0);
    EXPECT_LE(add2(2.1,2.7),4.0);
    EXPECT_GT(add2(2.1,2.7),4.0);
    EXPECT_GE(add2(2.1,2.7),4.0);
}
int main()
{
    return RUN_ALL_TESTS();
}
