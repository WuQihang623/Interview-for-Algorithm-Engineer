# 四数相加

![Alt text](image-3.png)

可以定义一个unordered_map，key中存放a+b,value存放a+b出现的次数；
再遍历C,D; 去find map中 key为 0-c-d的key。