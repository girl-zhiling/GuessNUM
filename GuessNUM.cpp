#include "ZhilingPack.h" // ������ https://raw.githubusercontent.com/girl-zhiling/ZhilingPack/main/ZhilingPack.h ��ȡ

int main(){
loop:srand_set(); // �趨�������
    SetConsoleTitleA("������Ϸ | ��ǰ���Դ���Ϊ 0 "); // �趨����
    int num = 0, input_num = 0, min = 0, max = 0, try_times = 0; // �����ʼ���� , �ֱ�Ϊ
    // num : Ҫ�µ�����    input_num : ���������    min ����С��Χ    max �����Χ    try_times : ���Դ���
    std::string title = "������Ϸ | ��ǰ���Դ���Ϊ ", time = std::to_string(try_times), final_title; // �����ʼ�ַ��� , �ֱ�Ϊ
    // title : ����ģ��    time : ���� , ʹ�� to_string() ת��    final_title : ���߽�ϣ����ճ��ֵı���
    std::cout << "��������Сֵ:"; // Ҫ��������Сֵ
    std::cin >> min; // �û�����
    std::cout << "���������ֵ:"; // Ҫ���������ֵ
    std::cin >> max; // �û�����
    num = random_number(min, max); // ��ֵҪ�µ�����
    auto start = std::chrono::system_clock::now(); // ��ʼʱ��
    while(true){ // ѭ��������������
        std::cout << "������Ҫ�µ���:"; // Ҫ������µ���ֵ
        std::cin >> input_num; // �û�����
        try_times++; // ���Դ�������
        time = std::to_string(try_times); // �����Դ���ת��Ϊ�ַ���
        final_title = title + time; // ������ģ�������ձ�����
        SetTitle(final_title); // �趨����
        if (input_num == num) break; // ���������� , �˳�ѭ��
        if (input_num < num){ // ��ʾ��Ϣ : С�� �� ����
            std::cout << "С��!"; // ��ʾС��
        }else std::cout << "���ˣ�"; // ��ʾ����
        
    }
    auto end = std::chrono::system_clock::now(); // ����ʱ��
    std::chrono::duration<double> duration_chrono = end - start; // ������ʱ�� , �� chrono::duration ����
    int duration = duration_chrono.count(); // ת��Ϊ int ����
    std::cout << "�¶��ˣ��𰸾���" << num << "\n"; // ���е���Ϣ
    std::cout << "��һ������" << try_times << "���ڷ�Χ" << min << "-" << max << "�в��У�\n"; // չʾ����
    std::cout << "��ʱ : " << duration << "��\n"; // չʾ�ķ�ʱ��
    system("pause"); // ֹͣ
    system("cls"); // ����
    goto loop; // ����һ��
}