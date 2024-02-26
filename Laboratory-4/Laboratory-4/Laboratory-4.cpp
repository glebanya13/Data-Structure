#include <iostream>
#include <vector>
#include <windows.h>
#include <map>

using namespace std;

struct Client {
    int id;
    string name;
    string haircut;
    int age;
    string branch;
    Client(int _id, string _name, int _age, string _haircut, string _branch) : id(_id), name(_name), age(_age), haircut(_haircut), branch(_branch) {}
};


vector<Client> clients;

Client findClientById(int id) {
    for (const Client& client : clients) {
        if (client.id == id) {
            return client;
        }
    }
    return Client(-1, "", -1, "", "");
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    int choice;

    while (true) {
        cout << "Меню парикмахерской:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Отобразить информацию о клиентах\n";
        cout << "3. Обновить информацию о стрижке\n";
        cout << "4. Показать статистику по филиалам\n";
        cout << "5. Поиск клиента по ID\n";
        cout << "6. Выход\n";

        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            int newId;
            string newName;
            int newAge;
            string newBranch;
            cout << "Введите ID нового клиента: ";
            cin >> newId;
            cout << "Введите имя нового клиента: ";
            cin >> newName;
            cout << "Введите возраст нового клиента: ";
            cin >> newAge;
            cout << "Введите филиал нового клиента: ";
            cin >> newBranch;
            clients.push_back(Client(newId, newName, newAge, "", newBranch));
            cout << "Клиент успешно добавлен.\n";
            break;
        }
        case 2:
        {
            cout << "Информация о клиентах:\n";
            for (const Client& client : clients) {
                cout << "ID: " << client.id << ", Имя: " << client.name << ", Возраст: " << client.age << endl;
            }
            break;
        }
        case 3:
        {
            int clientId;
            cout << "Введите ID клиента для обновления информации о стрижке: ";
            cin >> clientId;

            auto it = find_if(clients.begin(), clients.end(), [clientId](const Client& client) {
                return client.id == clientId;
                });

            if (it != clients.end()) {
                cout << "Введите новую информацию о стрижке для клиента " << it->name << ":\n";
                string newHaircut;
                cout << "Введите вид стрижки: ";
                cin >> newHaircut;
                it->haircut = newHaircut;
                cout << "Информация о стрижке успешно обновлена.\n";
            }
            else {
                cout << "Клиент с указанным ID не найден.\n";
            }

            break;
        }
        case 4:
        {
            map<string, int> branchStats;

            for (const Client& client : clients) {
                branchStats[client.branch]++;
            }

            cout << "Статистика по филиалам:\n";
            for (const auto& pair : branchStats) {
                cout << "Филиал: " << pair.first << ", Количество клиентов: " << pair.second << endl;
            }

            break;
        }
        case 5:
        {
            int searchId;
            cout << "Введите ID клиента для поиска: ";
            cin >> searchId;
            Client foundClient = findClientById(searchId);
            if (foundClient.id != -1) {
                cout << "Найден клиент: ID=" << foundClient.id << ", Имя=" << foundClient.name << ", Возраст=" << foundClient.age << endl;
            }
            else {
                cout << "Клиент не найден.\n";
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

    return 0;
}
