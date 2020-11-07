# 什么是GoogleTest（谷歌测试框架）

谷歌开发的针对C++开发的测试

# 安装

基本过程为下载源码并使用make编译

https://www.cnblogs.com/helloworldcode/p/9606838.html

编译之前先创建一个编译目录googletest-build，这样避免在源码目录进行编译造成污染问题。

创建文件夹

```
mkdir googletest-build
	//googletest和googletest-build为同级目录
cd googletest-build
```

编译

```
cmake ../googletest
	//后面的选项为源代码的目录
//cmake CMakeLists.txt
	如果是在源码目录进行
make	//编译
make install
	//安装
```

最后一步出问题的话，也可以手动拷贝一些问题到系统目录(/usr)中

```
sudo cp libgtest*.a /usr/lib
		//静态链接库，make编译后产生，在lib目录中
sudo cp –a include/gtest /usr/include
	//include的位置
	//make前在/googletest/googletest/目录
	//make后_install目录下
```



或者也可以自己手动进行编译

先将测试生成可链接对象```g++ -std=c++11 -c test.cpp```（注意c++11）

然后手动链接之前编译生成的静态链接库```g++  test.o -L./lib -lgtest```（-L表示临时添加./lib目录为系统目录，-l表示添加gtest静态链接）

## 测试安装是否出问题

测试代码：（保存为test.cpp）

```
#include<gtest/gtest.h>
int add(int a,int b){
    return a+b;
}
TEST(testCase,test0){
    EXPECT_EQ(add(2,3),5);
}
int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
```

编译命令：

```
g++ test.cpp -std=c++11 -lgtest -lpthread
```

运行：

```
./a.out
```

效果：

![在这里插入图片描述](GoogleTest.assets/20201016125818960.png)

## 其它问题：

### 在make时报错

在安装包的googletest文件夹下(~/googletest/CMakeList.txt)找到CmakeLists.txt， 在其最上面添加如下语句：

```
SET(CMAKE_CXX_FLAGS "-std=c++0x")
```

### g++时出错

```
g++ test.cpp -lgtest -lpthread

g++ test.cpp -std=c++11 -lgtest -lpthread
在编译时出现这种错误，请用第二条命令编译
```



参考

https://www.cnblogs.com/helloworldcode/p/9606838.html



https://blog.csdn.net/sevenjoin/article/details/89953950

https://blog.csdn.net/sevenjoin/article/details/89962344