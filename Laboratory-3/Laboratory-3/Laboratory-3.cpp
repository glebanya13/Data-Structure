#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void createAndWriteToFile() {
    string fileName;
    cout << "Введите название файла: ";
    cin >> fileName;
    cin.ignore(); // Добавляем эту строку, чтобы очистить буфер ввода после считывания имени файла

    ofstream file(fileName);
    if (file.is_open()) {
        string data;
        cout << "Введите данные для записи в файл (для окончания ввода введите 'end'): ";
        while (true) {
            getline(cin, data);
            if (data == "end") {
                break;
            }
            file << data << endl;
        }
        cout << "Данные успешно записаны в файл." << endl;
    }
    else {
        cout << "Не удалось открыть файл." << endl;
    }
    file.close();
}

void readFile() {
    ifstream file("example.txt");
    if (file.is_open()) {
        string line;
        cout << "Содержимое файла:" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "Не удалось открыть файл." << endl;
    }
    file.close();
}

void clearFile() {
    ofstream file("example.txt", ios::out | ios::trunc);
    if (file.is_open()) {
        cout << "Содержимое файла успешно удалено." << endl;
    }
    else {
        cout << "Не удалось открыть файл." << endl;
    }
    file.close();
}

void deleteFile() {
    if (remove("example.txt") == 0) {
        cout << "Файл успешно удален." << endl;
    }
    else {
        cout << "Не удалось удалить файл." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    createAndWriteToFile();
    readFile();
    clearFile();
    deleteFile();

    return 0;
}
