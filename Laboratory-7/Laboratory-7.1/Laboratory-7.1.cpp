#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Client {
    string name;
    int haircutInfo;  // Пусть haircutInfo будет полем для сортировки
};

void displayClients(const vector<Client>& clients) {
    cout << "Информация о клиентах:\n";
    for (const auto& client : clients) {
        cout << "Имя: " << client.name << "\tСтрижка: " << client.haircutInfo << "\n";
    }
}

void selectionSort(vector<Client>& clients) {
    int n = clients.size(); // Получаем количество элементов в векторе
    for (int i = 0; i < n - 1; ++i) { // Внешний цикл: проходим по всем элементам, кроме последнего
        int minIndex = i; // Предполагаем, что текущий элемент является минимальным
        for (int j = i + 1; j < n; ++j) { // Внутренний цикл: ищем минимальный элемент среди оставшихся
            if (clients[j].haircutInfo < clients[minIndex].haircutInfo) {
                minIndex = j; // Если находим элемент меньший текущего минимального, обновляем minIndex
            }
        }
        // Обмен элементов: после внутреннего цикла меняем текущий элемент с найденным минимальным
        swap(clients[i], clients[minIndex]);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice;

    vector<Client> clients;

    while (true) {
        cout << "Меню парикмахерской:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Отобразить информацию о клиентах\n";
        cout << "3. Обновить информацию о стрижке\n";
        cout << "4. Показать статистику по филиалам\n";
        cout << "5. Сортировать клиентов по стрижке (по возрастанию)\n";
        cout << "6. Выход\n";

        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            Client newClient;
            cout << "Введите имя клиента: ";
            cin >> newClient.name;
            cout << "Введите информацию о стрижке: ";
            cin >> newClient.haircutInfo;
            clients.push_back(newClient);
        }
        break;
        case 2:
            displayClients(clients);
            break;
        case 3:
            // Обновить информацию о стрижке
            break;
        case 4:
            // Показать статистику по филиалам
            break;
        case 5:
            selectionSort(clients);
            cout << "Клиенты отсортированы по информации о стрижке (по возрастанию).\n";
            break;
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
