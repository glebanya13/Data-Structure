#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Client {
    string name;
    string haircutInfo;
};

// Функции для работы с данными
void readFromFile(vector<Client>& clients, const string& filename);
void writeToFile(const vector<Client>& clients, const string& filename);
void displayClients(const vector<Client>& clients);
void addClient(vector<Client>& clients);

int main() {
    setlocale(LC_ALL, "rus");
    int choice;

    vector<Client> clients;

    // Цикл меню
    while (true) {
        cout << "Меню парикмахерской:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Отобразить информацию о клиентах\n";
        cout << "3. Обновить информацию о стрижке\n";
        cout << "4. Показать статистику по филиалам\n";
        cout << "5. Выход\n";

        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addClient(clients);
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
            writeToFile(clients, "clients.txt");
            cout << "Программа завершена.\n";
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }

        cout << "\n";
    }
}

void readFromFile(vector<Client>& clients, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка при открытии файла: " << filename << endl;
        return;
    }

    clients.clear(); // Очистить существующие данные

    while (file >> ws && !file.eof()) {
        Client client;
        getline(file, client.name);
        getline(file, client.haircutInfo);
        clients.push_back(client);
    }

    file.close();
}

void writeToFile(const vector<Client>& clients, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка при открытии файла для записи: " << filename << endl;
        return;
    }

    for (const auto& client : clients) {
        file << client.name << '\n';
        file << client.haircutInfo << '\n';
    }

    file.close();
}

void displayClients(const vector<Client>& clients) {
    cout << "Информация о клиентах:\n";
    for (const auto& client : clients) {
        cout << "Имя: " << client.name << "\nСтрижка: " << client.haircutInfo << "\n\n";
    }
}

void addClient(vector<Client>& clients) {
    Client newClient;
    cout << "Введите имя клиента: ";
    cin.ignore(); // Игнорировать любые символы новой строки в буфере
    getline(cin, newClient.name);

    cout << "Введите информацию о стрижке: ";
    getline(cin, newClient.haircutInfo);

    clients.push_back(newClient);
}
