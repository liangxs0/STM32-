添加对于LCD屏（ILI9486 320*480）和六轴陀螺仪的初始化和部分测试代码。
具体实现为图片在屏幕上的移动的速度和方向，用陀螺仪测得的数据实现。
添加24C04，24C04系统掉电可保存内容，内存空间大小为4K
注意：因为在目前开发板上MPU6050和24C04的数据总线被接在相同的GPIO上，时钟总线，I2C在起始时SDA 低电平 SCL 高电平，所以没有在24C04的初始化中重复初始化时钟总线，
添加独立看门狗，用于检测硬件异常
