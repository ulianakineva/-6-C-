#include <iostream>
#include <limits>
#include "LinkedList.h"          // Заголовочный файл для однонаправленного списка
#include "DoublyLinkedList.h"    // Заголовочный файл для двунаправленного списка
#include "HashSet.h"             // Заголовочный файл для HashSet
#include "UniqueList.h"          // Заголовочный файл для UniqueList
#include <fstream>
#include <string>
#include "UniqueList.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <map>
#include "Olympiad.h"
using namespace std;

// Функция для проверки корректности ввода числа
template <typename T>
T getValidatedInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear(); // Сброс состояния ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
        }
        else {
            return value; // Ввод корректный, возвращаем значение
        }
    }
}

// Главное меню с выбором типа списка
void showMainMenu() {
    cout << "Добро пожаловать в программу работы с двусвязными и однонаправленными списками!\n";
    cout << "Выберите задание:\n";
    cout << "1. Работа с однонаправленным списком\n";
    cout << "2. Работа с двунаправленным списком\n";
    cout << "3. Работа с коллекциями музыкальных произведений\n";
    cout << "4. Вывод уникальный гласных из файла\n";
    cout << "5. Участники олимпиады\n";
    cout << "6. Выход\n";
}

// Меню для работы с однонаправленным списком
void singleLinkedListMenu() {
    LinkedList<int> list;
    int choice;
    cout << "Вы выбрали однонаправленный список.\n";
    while (true) {
        cout << "\nВыберите действие:\n";
        cout << "1. Добавить элемент в список\n";
        cout << "2. Удалить элемент из списка\n";
        cout << "3. Проверить список на дубликаты\n";
        cout << "4. Показать список\n";
        cout << "5. Вернуться в главное меню\n";

        // Проверяем корректность ввода выбора пользователя
        choice = getValidatedInput<int>("Ваш выбор: ");

        switch (choice) {
        case 1: {
            // Добавление элемента
            int value = getValidatedInput<int>("Введите значение для добавления: ");
            list.add(value);
            std::cout << "Элемент " << value << " добавлен в список.\n";
            break;
        }
        case 2: {
            // Удаление элемента
            int value = getValidatedInput<int>("Введите значение для удаления: ");
            list.remove(value);
            break;
        }
        case 3: {
            // Проверка на дубликаты
            if (list.containsDuplicates()) {
                std::cout << "Список содержит дубликаты.\n";
            }
            else {
                std::cout << "Дубликатов в списке нет.\n";
            }
            break;
        }
        case 4: {
            // Печать списка
            std::cout << "Список: ";
            list.print();
            break;
        }
        case 5:
            // Возвращение в главное меню
            return;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }
}

// Меню для работы с двунаправленным списком
void doublyLinkedListMenu() {
    DoublyLinkedList<int> list;
    int val, choice;
    cout << "Вы выбрали двунаправленный список.\n";
    while (true) {
        cout << "Меню:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Удалить элемент\n";
        cout << "3. Удалить первое вхождение элемента\n";
        cout << "4. Вывести список\n";
        cout << "5. Показать соседей элемента\n";
        cout << "6. Вернуться в главное меню\n";
        cout << "Выберите опцию: ";
        choice = getValidatedInput<int>("Ваш выбор: ");

        switch (choice) {
        case 1:
            cout << "Введите элемент для добавления: ";
            cin >> val;
            list.addElement(val);
            break;
        case 2:
            cout << "Введите элемент для удаления: ";
            cin >> val;
            list.removeElement(val);
            break;
        case 3:
            cout << "Введите элемент для удаления первого вхождения: ";
            cin >> val;
            list.removeFirstOccurrence(val);
            break;
        case 4:
            list.printList();
            break;
        case 5:
            cout << "Введите элемент для поиска соседей: ";
            cin >> val;
            list.printNeighbors(val);
            break;
        case 6:
            return;  // Возвращение в главное меню
        default:
            cout << "Неверный выбор, попробуйте снова." << endl;
        }
    }
}

// Меню для работы с музыкальными коллекциями
void musicCollectionMenu() {
    // Перечень музыкальных произведений
    HashSet<std::string> music;
    music.Add("Song1");
    music.Add("Song2");
    music.Add("Song3");
    music.Add("Song4");
    music.Add("Song4");

    // Выводим все музыкальные произведения
    std::cout << "Все музыкальные произведения: ";
    music.Print();
    std::cout << "\n";

    // Личные списки меломанов
    HashSet<std::string> meloman1;
    meloman1.Add("Song1");
    meloman1.Add("Song3");

    HashSet<std::string> meloman2;
    meloman2.Add("Song1");
    meloman2.Add("Song2");

    HashSet<std::string> meloman3;
    meloman3.Add("Song1");

    // Выводим личные списки меломанов
    std::cout << "Список меломана 1: ";
    meloman1.Print();
    std::cout << "\n";

    std::cout << "Список меломана 2: ";
    meloman2.Print();
    std::cout << "\n";

    std::cout << "Список меломана 3: ";
    meloman3.Print();
    std::cout << "\n";

    // Общие песни, которые нравятся всем меломанам
    HashSet<std::string> commonLikes = meloman1.Intersect(meloman2).Intersect(meloman3);
    std::cout << "Музыкальные произведения, которые нравятся всем: ";
    commonLikes.Print();
    std::cout << "\n";

    // Песни, которые нравятся некоторым меломанам
    HashSet<std::string> someLikes = meloman1.Union(meloman2).Union(meloman3);
    std::cout << "Музыкальные произведения, которые нравятся некоторым меломанам: ";
    someLikes.Print();
    std::cout << "\n";

    // Песни, которые не нравятся никому
    HashSet<std::string> notLiked = music.Except(someLikes);
    std::cout << "Музыкальные произведения, которые не нравятся никому: ";
    notLiked.Print();
    std::cout << "\n";
}

// Функция для преобразования чисел в символы
void PrintVowelsAsCharacters(const UniqueList<wchar_t>& vowels_list) {
    // Используем метод Print для вывода элементов
    vowels_list.Print();
}

// Функция для обработки текста
void ProcessText(const wstring& text) {
    UniqueList<wchar_t> unique_vowels_list;
    UniqueList<wchar_t> repeated_vowels_list;
    wstring vowels = L"АЕЁИОУЫЭЮЯаеёиоуыэюя";

    map<wchar_t, int> vowels_count;

    // Подсчет количества каждой гласной
    for (wchar_t c : text) {
        if (vowels.find(c) != wstring::npos) {
            vowels_count[c]++;
        }
    }

    // Распределение гласных в уникальные и повторяющиеся списки
    for (const auto& pair : vowels_count) {
        if (pair.second == 1) {
            unique_vowels_list.Add(pair.first);
        }
        else if (pair.second > 1) {
            repeated_vowels_list.Add(pair.first);
        }
    }

    // Вывод результатов
    wcout.imbue(locale("Russian"));

    wcout << L"Содержимое файла: " << text << endl;

    wcout << L"Уникальные гласные в содержимом файла: ";
    PrintVowelsAsCharacters(unique_vowels_list);

    wcout << L"Повторяющиеся гласные в содержимом файла: ";
    PrintVowelsAsCharacters(repeated_vowels_list);
}
std::wstring stringToWString(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}
// Главная функция
int main() {
    setlocale(LC_ALL, "Russian");
    int mainChoice;
    wifstream file("input.txt");
    wstring text;
    wstring line;


    int N;
    vector<string> winners;
    vector<string> secondPlace;
    int maxPoints = -1;
    int secondMaxPoints = -1;
    Olimpiad<string, pair<int, int>> participants;  // Ключ: Фамилия + Имя (string), значение: пара (класс, баллы)
    string lastName, firstName;
    int grade, points;
    string fullName;
    ifstream inputFile("olymp.txt");

    while (true) {
        // Главное меню
        showMainMenu();
        mainChoice = getValidatedInput<int>("Ваш выбор: ");

        switch (mainChoice) {
        case 1:
            singleLinkedListMenu();  // Меню однонаправленного списка
            break;
        case 2:
            doublyLinkedListMenu();  // Меню двунаправленного списка
            break;
        case 3:
            musicCollectionMenu();  // Меню работы с музыкальными произведениями
            break;
        case 4:
            file.imbue(locale(locale(), new codecvt_utf8<wchar_t>()));

            if (!file) {
                wcerr << L"Ошибка открытия файла!" << endl;
                return 1;
            }

            // Чтение содержимого файла

            while (getline(file, line)) {
                text += line + L" ";
            }
            file.close();

            // Обработка текста
            ProcessText(text);
            std::cout << "\n";
            setlocale(LC_ALL, "Russian");
            break;
        case 5: 
            cout << "Победители олимпиады: \n";
            
            
            

            
            if (!inputFile.is_open()) {
                cerr << "Не удалось открыть файл olymp.txt" << endl;
                return 1;
            }

           
            // Объявляем переменные
            
            setlocale(LC_ALL, "ru_RU.UTF-8");
            wcout.imbue(locale("ru_RU.UTF-8"));
            // Считываем количество участников из файла
            inputFile >> N;

            // Создаем объект Olimpiad для хранения участников
            

            // Чтение данных участников из файла
            for (int i = 0; i < N; ++i) {
                
                inputFile >> lastName >> firstName >> grade >> points;
                fullName = lastName + " " + firstName;
                participants.addElement(fullName, { grade, points });
            }

            inputFile.close();  // Закрываем файл

            cout << "Список участников:" << endl;
            for (const auto& participant : participants.getAllElements()) {
                cout << participant.first << " класс: " << participant.second.first
                    << ", баллы: " << participant.second.second << endl;
            }
            // Найдем максимальные баллы
            for (const auto& participant : participants.getAllElements()) {
                maxPoints = max(maxPoints, participant.second.second);
            }

            // Список победителей
            for (const auto& participant : participants.getAllElements()) {
                if (participant.second.second > 200 && participant.second.second == maxPoints) {
                    winners.push_back(participant.first);
                }
            }

            // Условия для победителей
            if (winners.empty()) {
                // Если нет победителей
                cout << 0 << endl;
            }
            else if (winners.size() <= N * 0.2) {
                // Если победителей не больше 20%
                cout << winners.size() << endl;
            }
            else {
                // Ищем следующих по баллам
                for (const auto& participant : participants.getAllElements()) {
                    if (participant.second.second < maxPoints) {
                        secondMaxPoints = max(secondMaxPoints, participant.second.second);
                    }
                }

                // Все участники с вторыми максимальными баллами
                for (const auto& participant : participants.getAllElements()) {
                    if (participant.second.second == secondMaxPoints) {
                        secondPlace.push_back(participant.first);
                    }
                }

                if (secondPlace.size() == 1) {
                    cout << secondPlace[0] << endl;
                }
                else {
                    cout << secondPlace.size() << endl;
                }
            }
            setlocale(LC_ALL, "Russian");
            cout << "\n";
            break;
        case 6: 
            cout << "Завершение программы. До свидания!\n";
            return 0;  // Выход из программы
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}




















































