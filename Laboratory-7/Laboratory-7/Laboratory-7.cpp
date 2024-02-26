#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Client {
    string name;
    string haircutDate;
    Client(string n, string date) : name(n), haircutDate(date) {}
};

bool compareByName(const Client& a, const Client& b) {
    return a.name < b.name;
}

bool compareByHaircutDate(const Client& a, const Client& b) {
    return a.haircutDate < b.haircutDate;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int choice;

    vector<Client> clients;

    while (true)
    {
        cout << "Меню парикмахерской:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Отобразить информацию о клиентах\n";
        cout << "3. Обновить информацию о стрижке\n";
        cout << "4. Показать статистику по филиалам\n";
        cout << "5. Сортировать клиентов\n";
        cout << "6. Выход\n";

        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, date;
            cout << "Введите имя клиента: ";
            cin >> name;
            cout << "Введите дату стрижки (в формате дд.мм.гггг): ";
            cin >> date;
            clients.push_back(Client(name, date));
            break;
        }
        case 2:
        {
            cout << "Информация о клиентах:\n";
            for (const auto& client : clients) {
                cout << "Имя: " << client.name << ", Дата стрижки: " << client.haircutDate << "\n";
            }
            break;
        }
        case 3:
            // Обновить информацию о стрижке
            break;
        case 4:
            // Показать статистику по филиалам
            break;
        case 5:
        {
            int sortChoice;
            cout << "1. Сортировать по имени\n";
            cout << "2. Сортировать по дате стрижки\n";
            cout << "Выберите параметр сортировки: ";
            cin >> sortChoice;

            switch (sortChoice) {
            case 1:
                sort(clients.begin(), clients.end(), compareByName);
                cout << "Клиенты отсортированы по имени.\n";
                break;
            case 2:
                sort(clients.begin(), clients.end(), compareByHaircutDate);
                cout << "Клиенты отсортированы по дате стрижки.\n";
                break;
            default:
                cout << "Некорректный выбор. Возврат в главное меню.\n";
                break;
            }
            break;
        }
        case 6:
            cout << "Программа завершена.\n";
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }

        cout << "\n";
    }
}
