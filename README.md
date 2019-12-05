# QT-
基于QT、MySQL开发的酒店管理系统（c++课设）

   第一次使用qt+MySQL进行开发，上一个项目做的是java项目，
转过来写c++的时候有诸多不适，所以开发的时候很多地方写的不是很好。
   记录遇到的一些问题

   1.数据存储问题
   我的数据是存储在MySQL数据库中，所以每一次都要和数据库进行交互也就是curd(误)。
之前用java的时候有list能直接用，然后也是用mybaties直接封装成对象，
使用qt的时候不清楚c++有没有类似的插件或方法，所以只能手写query。
   手写query的时候遇到一个问题，就是如何存储对象数组。一开始想要使用c++list来存储，
后面发现操作数据太麻烦了，原本打算重写一个list，后面问了其他朋友，发现c++的容器vector
挺好用的。现在是使用vector进行临时存储数据。

   2.操作数据库时的一些细节
   由于java创建对象的时候就是指针(需要new对象)，如果没有成功创建返回的是null，而我刚开始写c++的时候
也想当然的直接创建一个对象(c++不需要new)，然后后面在遇到空值的时候就把我给搞晕了，
由于在写的时候直接return 一个对象，他调用了空构造来构造对象，此时对象的值都是无效值(我没有重新写空构造)
这时候判断返回值是否有效就变成了一个很麻烦的问题，虽然返回空对象一般都是初始化成0或空串，但是这样的程序并不安全。
所以下一次构造程序的时候应该考虑定义对象的时候应该定义成指针(typedef)。然后再判断是否为空。
   
   3.工具类的创建问题
   我写工具类的时候没有构思好，有的在方法内构造，有的在私有成员里面构造，不包含私有成员的工具类应该定义成类
的私有成员会更好，其实甚至没有私有成员的工具类里的方法定义成静态会更好。

   4.Qt工具类使用不熟悉
   由于算是第一次接触qt，很多窗口和空间的创建都不是很熟悉，有时明明系统提供了现成的QMessageBox,我还自己写了
一个Dialog来实现简单的确定取消按钮，浪费了很多开发时间。qt的qss也不熟悉，很多样式也做的不好看。