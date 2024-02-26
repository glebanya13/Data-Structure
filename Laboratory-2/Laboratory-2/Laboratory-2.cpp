#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int choice;

    while (true)
    {
        cout << "Меню парикмахерской:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Отобразить информацию о клиентах\n";
        cout << "3. Обновить информацию о стрижке\n";
        cout << "4. Показать статистику по филиалам\n";
        cout << "5. Выход\n";

        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Добавить клиента
            break;
        case 2:
            // Отобразить информацию о клиентах
            break;
        case 3:
            // Обновить информацию о стрижке
            break;
        case 4:
            // Показать статистику по филиалам
            break;
        case 5:
            cout << "Программа завершена.\n";
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }

        cout << "\n";
    }
}
