#include <iostream>
#include <fstream>
#include <json/json.h>

void processJsonFile(const std::string& jsonFilePath)
{
	// 检查文件是否存在
	if (!std::ifstream(jsonFilePath))
	{
		std::cerr << "Error: File not found: " << jsonFilePath << std::endl;
		return;
	}

	std::ifstream jsonFile(jsonFilePath); // 打开 JSON 文件
	Json::Value jsonData; // 用于存储 JSON 数据的变量

	try
	{
		jsonFile >> jsonData; // 从文件中读取 JSON 数据
	}
	catch (const Json::Exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return;
	}

	// 遍历 JSON 对象的第一层
	for (auto it = jsonData.begin(); it != jsonData.end(); ++it)
	{
		std::string key = it.key().asString();
		if (key == "TextStyles") // 跳过 "TextStyles" 对象
			continue;

		Json::Value& item = *it;
		if (item.isObject()) // 如果当前元素是一个对象
		{
			// 检查 "Font" 字段是否为空
			if (item["Font"].asString().empty())
			{
				item["Font"] = "C_23435_20307_DTTF"; // 设置 "Font" 字段的值
			}
		}
	}

	std::ofstream jsonFileOut(jsonFilePath); // 打开 JSON 文件以写入更改后的数据
	jsonFileOut << jsonData; // 将更改后的 JSON 数据写回文件
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <json_file_path>" << std::endl;
		return -1;
	}

	std::string jsonFilePath = argv[1]; // 从命令行中获取 JSON 文件的路径

	int option = 0;
	std::cout << "----------------" << std::endl;
	std::cout << "1.修复Font" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "输入选项: " << std::endl;
	std::cin >> option;

	if (option == 1)
	{
		processJsonFile(jsonFilePath);
	}
	else if (option == 2)
	{
		// 其他功能...
	}
	else if (option == 3)
	{
		// 其他功能...
	}
	else if (option == 4)
	{
		// 其他功能...
	}

	return 0;
}
