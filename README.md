# card-swiper

刷卡器固件

## Todo List

- [x] 能刷卡并读取卡的UID
- [x] 能够联网
- [x] 能驱动蜂鸣器
- [x] 能点亮LED
- [x] 能点亮OLED屏幕
- [ ] OLED的显示界面
- [ ] 完善get请求协议
- [ ] 3D打印外壳
- [ ] 硬件电路优化

## How to use

1. 重命名`/src/NetConfig.hpp.example` -> `/src/NetConfig.hpp`
2. 修改里面的条目
3. 编译并烧录到esp32中
