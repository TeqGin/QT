# QT
基于QT、MySQL开发的酒店管理系统（c++课设）
=====

   >第一次使用qt+MySQL进行开发，上一个项目做的是java项目，
转过来写c++的时候有诸多不适，所以开发的时候很多地方写的不是很好。
   # 项目环境
   >
1.QT:               QT creator4.9.0(Qt 5.12.2 (MSVC 2017, 32 bit))（需要添加MySQL 32位驱动）<br>
2.MySQL:            MySQL-8.0.11-winx64<br>
3.数据库图形化界面: navicat for mysql 12.1.20(64位)<br>
3.编译方式：        QT 5.12.3 MinGW 64-bit release编译完以后需要在项目release目录下加入MySQL64位驱动  <br>
4.配置环境变量path：...\5.12.3\mingw73_64\bin;<br>
   # 记录遇到的一些问题 -

   ### 1.数据存储问题
   
> 我的数据是存储在MySQL数据库中，所以每一次都要和数据库进行交互也就是crud(误)。
之前用java的时候有list能直接用，然后也是用mybaties直接封装成对象，
使用qt的时候不清楚c++有没有类似的插件或方法，所以只能手写query。<br>
 手写query的时候遇到一个问题，就是如何存储对象数组。一开始想要使用c++list来存储，
后面发现操作数据太麻烦了，原本打算重写一个list，后面问了其他朋友，发现c++的容器vector
挺好用的。现在是使用vector进行临时存储数据。

  ### 2.操作数据库时的一些细节
  
>由于java创建对象的时候就是指针(需要new对象)，如果没有成功创建返回的是null，而我刚开始写c++的时候
也想当然的直接创建一个对象(c++不需要new)，然后后面在遇到空值的时候就把我给搞晕了，<br>
由于在写的时候直接return 一个对象，他调用了空构造来构造对象，此时对象的值都是无效值(我没有重新写空构造)
这时候判断返回值是否有效就变成了一个很麻烦的问题，虽然返回空对象一般都是初始化成0或空串，但是这样的程序并不安全。
所以下一次构造程序的时候应该考虑定义对象的时候应该定义成`指针`(typedef)。然后再判断是否为空。
   
   ### 3.工具类的创建问题
 
   >我写工具类的时候没有构思好，有的在方法内构造，有的在私有成员里面构造，不包含私有成员的工具类应该定义成类
的私有成员会更好，其实甚至没有私有成员的工具类里的方法定义成`静态`会更好。

  ### 4.Qt工具类使用不熟悉
   
   >由于算是第一次接触qt，很多窗口和空间的创建都不是很熟悉，有时明明系统提供了现成的QMessageBox,我还自己写了
一个Dialog来实现简单的确定取消按钮，浪费了很多开发时间。qt的qss也不熟悉，很多样式也做的不好看。

  ### 5.关于连接数据的问题
  > 我使用的数据库是`MySQL`，但是在连接数据库的时候一直连接失败，调试了很久才发现原来是因为我的数据库版本是64bit，
但是我的QT版本是32bit，而我64bit的数据库自带的驱动是64bit，这就导致32bit的qt一直无法连接上64bit的MySQL，后来我去找了一
个32bit的数据库连接驱动就成功了。

### 6.发布以后的程序连接数据库问题
>我的数据库连接驱动用的是32bit的，但是release是使用64位的方式来处理的，这样就导致发布的程序变成64bit（太迷了）<br>
64bit的程序又无法通过32bit的驱动来连接数据库,所以在发布的程序同级目录下需要加入64bit的数据库连接驱动才能正常访问数据库。
我自己电脑配置好的版本是64位的连接，如果release使用32位的话就会无法启动，但是我打包的时候用的又是32bit的打包工具（大迷），刚刚试了一下64bit的打包工具也能正常运行。感觉QT为了兼容多平台反而把操作弄得乱七八糟的,也可能是因为我使用的是32bit的QT吧.

### 7.静态资源问题
>今天下午在调试背景图片，出的问题是添加背景图片时的url问题。一开始使用的是相对路径，但是相对路径里使用(./)无法找到对应的资源，
后来Google了很久，发现应该先把资源加入到静态资源中，然后使用(:/)来访问静态资源，路径是静态资源的前缀+文件名。<br>
还遇到一个问题是资源删除以后源文件编译的时候找不到资源（但是这个是本来就用不到并且从文件目录下remove掉了），如何使用静态资源来统一管理应该不会出这个
问题，现在只能先把资源放在文件目录下保证编译通过，具体解决方案目前还没有发现。
