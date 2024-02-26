#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Client {
    string lastName;
};

vector<Client> clients;

void addClient() {
    Client client;
    cout << "Введите фамилию клиента: ";
    cin >> client.lastName;
    clients.push_back(client);
    cout << "Клиент добавлен.\n";
}

void displayClients() {
    cout << "Информация о клиентах:\n";
    for (const auto& client : clients) {
        cout << "Фамилия: " << client.lastName << "\n";
        cout << "-----------------------\n";
    }
}

void searchClientsByLastName() {
    string searchLastName;
    cout << "Введите фамилию для поиска: ";
    cin >> searchLastName;

    cout << "Результаты поиска:\n";
    for (const auto& client : clients) {
        if (client.lastName.find(searchLastName) != string::npos) {
            cout << "Фамилия: " << client.lastName << "\n";
            cout << "-----------------------\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice;

    while (true) {
        cout << "Меню парикмахерской:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Отобразить информацию о клиентах\n";
        cout << "3. Поиск клиентов по фамилии\n";
        cout << "4. Обновить информацию о стрижке\n";
        cout << "5. Показать статистику по филиалам\n";
        cout << "6. Выход\n";

        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addClient();
            break;
        case 2:
            displayClients();
            break;
        case 3:
            searchClientsByLastName();
            break;
        case 4:
            // Обновить информацию о стрижке
            break;
        case 5:
            // Показать статистику по филиалам
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
