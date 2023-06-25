# FixFunc

此项目是工作上用来处理json文件，后续功能用到再开发，目前只用到一个功能

# 功能

1.对json文件中某个字段为空时，则给这个字段赋值，在此项目中是查找Font字段无值并填充，Font字段中无值的情况，统一设置为值"C_23435_20307_DTTF"，也就是宋体，其他字段也类似

# 使用方法

注意，第一此项目需要用到jsoncpp库，第二我放了个test.json可以拿来测试

将exe拉入到cmd中，空格，再拉入要处理的json文件，输入功能选项即可

比如1是修复Font

# 跳过某些对象

比如我json文件是这样的

```json
{
    "TextStyles": {
        "Items": [
            "123123"
            "123123"
            "324234"
        ]
    },
    "test1": {
        "Id": 22,
        "Font": "C_423423",
        "Name": "测试1",
    },
    "test2": {
        "Id": 23,
        "Font": "C_423423",
        "Name": "测试2",
    },
    "test3": {
        "Id": 63,
        "Font": "",
        "Name": "测试3",
    }
}
```

那么我就要跳过TextStyles对象，也就是代码里这行代码，跳过其他对象也类似

```cpp
if (key == "TextStyles") // 跳过 "TextStyles" 对象
			continue;
```

其中

```json
"test3": {
        "Id": 63,
        "Font": "",
        "Name": "测试3",
    }
```

就是我们代码会执行的，因为判断出Font为空，所以会插入

# 下载

[点击下载](https://github.com/qingfenglan/FixFunc/releases/tag/v1.0.0)
