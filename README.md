# QQ游戏连连看外挂 (Windows C++/MFC）

大学时的娱乐作品，QQ连连看游戏辅助

[/output/QQ连连看外挂.exe][wg]为编译好的程序，Windows下可直接运行

[/output/QQ连连看模拟器.exe][mnq]为连连看模拟器，没有安装QQ连连看游侠又想看效果的打开这个就可以测试了

## 支持功能
 
 * 可消方块高亮提示与自动消除
 * 全部方块瞬间消除(真的是瞬间哦)
 * 鼠标操作效果模拟(开启鼠标模拟，全部消除时的效果很萌哦)

## 效果截图

* 后台运行及快捷键提示
 ![后台提示](https://raw.github.com/gyk001/QQ_LLK_Cheat/master/raw/llk_popup.png)
 
* 刷新地图：软件会分析当前地图并渲染到自己界面上
 ![刷新地图](https://raw.github.com/gyk001/QQ_LLK_Cheat/master/raw/flash_map.png)
 
* 消除一组：
 ![刷新地图](https://raw.github.com/gyk001/QQ_LLK_Cheat/master/raw/find.png)
  

## 原理分析
  
  1. 抓取QQ连连看的屏幕图像
  2. 分析图像特征码提取计算地图布局
  3. 通过算法查找可以消除的方块
  4. 模拟发送鼠标点击事件触发消块

#  QQ连连看模拟器

因写外挂时意外断网，不能用真正的QQ连连看进行测试，

所以写了这个程序模拟QQ连连看，该程序并没有真正实现连连看的功能，

只是模拟了点击方块，方块即消失或重现，因为这足以测试外挂。
	![模拟器截图](https://raw.github.com/gyk001/QQ_LLK_Cheat/master/raw/llk_demo.png)
 
如果需要真正连连看程序，请移步

https://github.com/gyk001/LLK

# 同时期的其他小游戏

* [推箱子和地图编辑器](https://github.com/gyk001/BoxMan)
* [连连看](https://github.com/gyk001/LLK)
* [QQ连连看外挂和模拟器](https://github.com/gyk001/QQ_LLK_Cheat)
* [数据结构图算法演示](https://github.com/gyk001/graph)
* [节日时钟桌面堆雪](https://github.com/gyk001/DeskSnow)
* [日语单词学习机](https://github.com/gyk001/JPWord)

[wg]: https://github.com/gyk001/QQ_LLK_Cheat/raw/master/output/QQ连连看外挂.exe

[mnq]: https://github.com/gyk001/QQ_LLK_Cheat/raw/master/output/QQ连连看模拟器.exe