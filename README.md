# LogiG29_C-
G29_C + + development based on Logitech official SDK
# 一, 准备工作

## 1.开发环境和开发工具

开发环境：win10
开发工具：vs2015
方向盘型号:罗技G29

## 2.开发前需下载安装的东西
### (1).下载罗技方向盘SDK
https://www.logitechg.com.cn/zh-cn/innovation/developer-lab.html
文件中有相关的.h和.lib文件，以及三个mfc例程以及相关的说明文档

### (2).下载罗技游戏软件&罗技G hub
下载链接：https://support.logi.com/hc/zh-cn/articles/360025298053
下载链接：https://www.logitechg.com.cn/zh-cn/innovation/g-hub.html
目前只安装Ghub应该也可以。
## 3.运行demo检测方向盘是否正常工作
正常情况下，在方向盘上电并接入电脑后，方向盘会自动旋转校正，打开罗技游戏软件的时候也会有此操作，接好方向盘并且打开罗技游戏软件&g hub（最好设置为自启动），通过官方提供的demo来检测一下方向盘是否能够正常工作.

SDK\Samples路径下带有三个官方demo，直接用vs打开工程。==配置库文件(即配置IDE环境)==后运行即可。

![image-官方demo](C:\Users\haylion\AppData\Roaming\Typora\typora-user-images\image-20210223175730855.png)

运行第一个demo，点击init后，方向盘数据会被采集到。
==至此，硬件连通准备工作完成。==

## 4.配置IDE环境(C++,C#需配置cs文件)

A,添加工程的头文件目录:工程---属性-配置属性---c/c++---常规---附加包含目录:加上头文件存放目录.

B,添加文件引用的lib静态库路径:工程---属性---配置属性---链接器---常规---附加库目录:加上lib文件存放目录。

C然后添加工程引用的lib文件名:工程---属性---配置属性---链接器---输入---附加依赖项:加上lb文件名.
# 二,开发

## 1,工程创建
工程创建类型不限,试过C++空文件,window桌面应用程序等都能跑通.
## 2,api调用

### (1)api调用流程
需先调用LogiSteeringInitialize()
后每次采数前调用LogiUpdate()
更新后LogiGetState()即可返回一个采集的结构体 
#### ① 初始化函数:

```
LogiSteeringInitialize(CONST bool ignoreXInputControllers, HWND hwnd)
```
```
bool LogiSteeringInitialize(CONST bool ignoreXInputControllers) 
```
 详细参阅SDK\Doc中LogitechGamingSteeringWheelSDK.pdf文档.

#### ② update
```
LogiUpdate()
```
详细参阅SDK\Doc中LogitechGamingSteeringWheelSDK.pdf文档.
#### ③getstate
```
LogiGetState() 
```
详细参阅SDK\Doc中LogitechGamingSteeringWheelSDK.pdf文档.
## 3,eg
eg为最简单的基本调用例子。
更多函数用法请参阅LogitechGamingSteeringWheelSDK.pdf文档。

