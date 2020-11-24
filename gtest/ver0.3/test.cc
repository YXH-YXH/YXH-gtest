#include"test.h"
#include<cstdio>
#include<cstring>
int func_cnt=0;
int test_cnt,test_right;
Function func_arr[100];//存储测试函数

void add_function(TestFuncT func,const char*str){
    func_arr[func_cnt].func=func;
    func_arr[func_cnt].str=strdup(str);//string.h函数，开辟空间并复制内容
    func_cnt++;
}

int RUN_ALL_TESTS()
{
    for(int i=0; i<func_cnt; i++){
        printf(GREEN"[====RUN====]"NONE);
        test_cnt=0,test_right=0;
        printf(RED"RUN TEST:%s\n"NONE,func_arr[i].str);
        func_arr[i].func();
        printf("[%8.2lf%%  ]",test_right*100.0/test_cnt);
        printf("RUN_END");
        printf("Total %d success %d rate %.2lf%%\n",test_cnt,test_right,test_right*100.0/test_cnt);
    }
    printf("ALL_TEST_RUN_END\n");
    return 0;
}
