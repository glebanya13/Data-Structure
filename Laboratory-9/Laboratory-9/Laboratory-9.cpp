#include <iostream>
#include <vector>
#include <algorithm> // Для бинарного поиска
#include <locale>

using namespace std;

struct Client {
    string firstName;
    string lastName;
    Client(string first, string last) : firstName(first), lastName(last) {}
};

// Функция для интерпретирующего поиска по фамилии
int interpretativeSearch(const vector<Client>& clients, const string& lastName) {
    for (int i = 0; i < clients.size(); ++i) {
        if (clients[i].lastName == lastName) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<Client>& clients, const string& lastName) {
    int left = 0; // устанавливается в начало вектора (0).
    int right = clients.size() - 1; // устанавливается в конец вектора (размер вектора минус 1).

    while (left <= right) {
        int mid = left + (right - left) / 2; // индекс среднего элемента

        if (clients[mid].lastName == lastName) {
            return mid;
        }

        if (clients[mid].lastName < lastName) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice;

    vector<Client> clients = {
        {"Gleb", "Shar"},
        {"Glab", "Sher"},
        {"Glib", "Shyr"},
    };

    while (true) {
        cout << "Меню парикмахерской:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Отобразить информацию о клиентах\n";
        cout << "3. Обновить информацию о стрижке\n";
        cout << "4. Показать статистику по филиалам\n";
		cout << "5. Поиск клиента\n";
        cout << "6. Выход\n";

        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
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
        case 5: {
            string searchLastName;
            cout << "Введите фамилию для поиска: ";
            cin >> searchLastName;

            int interpretativeIndex = interpretativeSearch(clients, searchLastName);
            int binaryIndex = binarySearch(clients, searchLastName);

            if (interpretativeIndex != -1) {
                cout << "Интерпретирующий поиск: Клиент найден на позиции " << interpretativeIndex + 1 << ".\n";
            }
            else {
                cout << "Интерпретирующий поиск: Клиент не найден.\n";
            }

            if (binaryIndex != -1) {
                cout << "Бинарный поиск: Клиент найден на позиции " << binaryIndex + 1 << ".\n";
            }
            else {
                cout << "Бинарный поиск: Клиент не найден.\n";
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
