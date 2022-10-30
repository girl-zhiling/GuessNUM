#include "ZhilingPack.h" // 可以在 https://raw.githubusercontent.com/girl-zhiling/ZhilingPack/main/ZhilingPack.h 获取

int main(){
loop:srand_set(); // 设定随机数种
    SetConsoleTitleA("猜数游戏 | 当前尝试次数为 0 "); // 设定标题
    int num = 0, input_num = 0, min = 0, max = 0, try_times = 0; // 定义初始变量 , 分别为
    // num : 要猜的数字    input_num : 输入的数字    min ：最小范围    max ：最大范围    try_times : 尝试次数
    std::string title = "猜数游戏 | 当前尝试次数为 ", time = std::to_string(try_times), final_title; // 定义初始字符串 , 分别为
    // title : 标题模板    time : 次数 , 使用 to_string() 转换    final_title : 两者结合，最终出现的标题
    std::cout << "请输入最小值:"; // 要求输入最小值
    std::cin >> min; // 用户输入
    std::cout << "请输入最大值:"; // 要求输入最大值
    std::cin >> max; // 用户输入
    num = random_number(min, max); // 赋值要猜的数字
    auto start = std::chrono::system_clock::now(); // 起始时间
    while(true){ // 循环往复猜数过程
        std::cout << "输入你要猜的数:"; // 要求输入猜的数值
        std::cin >> input_num; // 用户输入
        try_times++; // 尝试次数自增
        time = std::to_string(try_times); // 将尝试次数转换为字符串
        final_title = title + time; // 将标题模板与最终标题结合
        SetTitle(final_title); // 设定标题
        if (input_num == num) break; // 如果二者相等 , 退出循环
        if (input_num < num){ // 提示信息 : 小了 或 大了
            std::cout << "小了!"; // 提示小了
        }else std::cout << "大了！"; // 提示大了
        
    }
    auto end = std::chrono::system_clock::now(); // 结束时间
    std::chrono::duration<double> duration_chrono = end - start; // 经过的时间 , 以 chrono::duration 储存
    int duration = duration_chrono.count(); // 转换为 int 整型
    std::cout << "猜对了！答案就是" << num << "\n"; // 猜中的信息
    std::cout << "您一共用了" << try_times << "次在范围" << min << "-" << max << "中猜中！\n"; // 展示次数
    std::cout << "耗时 : " << duration << "秒\n"; // 展示耗费时间
    system("pause"); // 停止
    system("cls"); // 清屏
    goto loop; // 再来一次
}