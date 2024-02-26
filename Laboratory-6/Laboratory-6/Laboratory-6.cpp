#include <iostream>
#include <cstring>

using namespace std;

const int MAX_CLIENTS = 100;

struct Client {
    string name;
    string haircutInfo;
};

void addClient(Client clients[], int& numClients) {
    if (numClients < MAX_CLIENTS) {
        cout << "Введите имя клиента: ";
        cin >> clients[numClients].name;
        cout << "Введите информацию о стрижке: ";
        cin >> clients[numClients].haircutInfo;
        numClients++;
        cout << "Клиент добавлен успешно.\n";
    }
    else {
        cout << "Достигнуто максимальное количество клиентов.\n";
    }
}

void displayClients(const Client clients[], int numClients) {
    if (numClients > 0) {
        cout << "Информация о клиентах:\n";
        for (int i = 0; i < numClients; i++) {
            cout << "Имя: " << clients[i].name << ", Стрижка: " << clients[i].haircutInfo << "\n";
        }
    }
    else {
        cout << "Нет зарегистрированных клиентов.\n";
    }
}

void updateHaircutInfo(Client clients[], int numClients) {
    if (numClients > 0) {
        cout << "Введите имя клиента для обновления информации о стрижке: ";
        string clientName;
        cin >> clientName;

        bool found = false;
        for (int i = 0; i < numClients; i++) {
            if (clients[i].name == clientName) {
                cout << "Введите новую информацию о стрижке: ";
                cin >> clients[i].haircutInfo;
                found = true;
                cout << "Информация обновлена успешно.\n";
                break;
            }
        }

        if (!found) {
            cout << "Клиент с именем " << clientName << " не найден.\n";
        }
    }
    else {
        cout << "Нет зарегистрированных клиентов.\n";
    }
}

void removeClient(Client clients[], int& numClients, const string& clientName) {
    if (numClients > 0) {
        for (int i = 0; i < numClients; i++) {
            if (clients[i].name == clientName) {
                clients[i] = clients[numClients - 1];
                numClients--;
                cout << "Клиент " << clientName << " удален успешно.\n";
                return;
            }
        }
        cout << "Клиент с именем " << clientName << " не найден.\n";
    }
    else {
        cout << "Нет зарегистрированных клиентов.\n";
    }
}

void removeAllClients(int& numClients) {
    if (numClients > 0) {
        numClients = 0;
        cout << "Все клиенты удалены успешно.\n";
    }
    else {
        cout << "Нет зарегистрированных клиентов.\n";
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice;
    int numClients = 0;
    Client clients[MAX_CLIENTS];

    while (true) {
        cout << "Меню парикмахерской:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Отобразить информацию о клиентах\n";
        cout << "3. Обновить информацию о стрижке\n";
        cout << "4. Показать статистику по филиалам\n";
        cout << "5. Удалить клиента\n";
        cout << "6. Удалить всех клиентов\n";
        cout << "7. Выход\n";

        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addClient(clients, numClients);
            break;
        case 2:
            displayClients(clients, numClients);
            break;
        case 3:
            updateHaircutInfo(clients, numClients);
            break;
        case 4:
            cout << "Функция в разработке.\n";
            break;
        case 5: {
            string clientName;
            cout << "Введите имя клиента для удаления: ";
            cin >> clientName;
            removeClient(clients, numClients, clientName);
            break;
        }
        case 6:
            removeAllClients(numClients);
            break;
        case 7:
            cout << "Программа завершена.\n";
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }

        cout << "\n";
    }
}
