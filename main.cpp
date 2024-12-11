#include <iostream>
#include <limits>
#include "LinkedList.h"          // ������������ ���� ��� ����������������� ������
#include "DoublyLinkedList.h"    // ������������ ���� ��� ���������������� ������
#include "HashSet.h"             // ������������ ���� ��� HashSet
#include "UniqueList.h"          // ������������ ���� ��� UniqueList
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

// ������� ��� �������� ������������ ����� �����
template <typename T>
T getValidatedInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear(); // ����� ��������� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������
            std::cout << "������������ ����. ���������� �����.\n";
        }
        else {
            return value; // ���� ����������, ���������� ��������
        }
    }
}

// ������� ���� � ������� ���� ������
void showMainMenu() {
    cout << "����� ���������� � ��������� ������ � ����������� � ����������������� ��������!\n";
    cout << "�������� �������:\n";
    cout << "1. ������ � ���������������� �������\n";
    cout << "2. ������ � ��������������� �������\n";
    cout << "3. ������ � ����������� ����������� ������������\n";
    cout << "4. ����� ���������� ������� �� �����\n";
    cout << "5. ��������� ���������\n";
    cout << "6. �����\n";
}

// ���� ��� ������ � ���������������� �������
void singleLinkedListMenu() {
    LinkedList<int> list;
    int choice;
    cout << "�� ������� ���������������� ������.\n";
    while (true) {
        cout << "\n�������� ��������:\n";
        cout << "1. �������� ������� � ������\n";
        cout << "2. ������� ������� �� ������\n";
        cout << "3. ��������� ������ �� ���������\n";
        cout << "4. �������� ������\n";
        cout << "5. ��������� � ������� ����\n";

        // ��������� ������������ ����� ������ ������������
        choice = getValidatedInput<int>("��� �����: ");

        switch (choice) {
        case 1: {
            // ���������� ��������
            int value = getValidatedInput<int>("������� �������� ��� ����������: ");
            list.add(value);
            std::cout << "������� " << value << " �������� � ������.\n";
            break;
        }
        case 2: {
            // �������� ��������
            int value = getValidatedInput<int>("������� �������� ��� ��������: ");
            list.remove(value);
            break;
        }
        case 3: {
            // �������� �� ���������
            if (list.containsDuplicates()) {
                std::cout << "������ �������� ���������.\n";
            }
            else {
                std::cout << "���������� � ������ ���.\n";
            }
            break;
        }
        case 4: {
            // ������ ������
            std::cout << "������: ";
            list.print();
            break;
        }
        case 5:
            // ����������� � ������� ����
            return;
        default:
            std::cout << "������������ �����. ���������� �����.\n";
        }
    }
}

// ���� ��� ������ � ��������������� �������
void doublyLinkedListMenu() {
    DoublyLinkedList<int> list;
    int val, choice;
    cout << "�� ������� ��������������� ������.\n";
    while (true) {
        cout << "����:\n";
        cout << "1. �������� �������\n";
        cout << "2. ������� �������\n";
        cout << "3. ������� ������ ��������� ��������\n";
        cout << "4. ������� ������\n";
        cout << "5. �������� ������� ��������\n";
        cout << "6. ��������� � ������� ����\n";
        cout << "�������� �����: ";
        choice = getValidatedInput<int>("��� �����: ");

        switch (choice) {
        case 1:
            cout << "������� ������� ��� ����������: ";
            cin >> val;
            list.addElement(val);
            break;
        case 2:
            cout << "������� ������� ��� ��������: ";
            cin >> val;
            list.removeElement(val);
            break;
        case 3:
            cout << "������� ������� ��� �������� ������� ���������: ";
            cin >> val;
            list.removeFirstOccurrence(val);
            break;
        case 4:
            list.printList();
            break;
        case 5:
            cout << "������� ������� ��� ������ �������: ";
            cin >> val;
            list.printNeighbors(val);
            break;
        case 6:
            return;  // ����������� � ������� ����
        default:
            cout << "�������� �����, ���������� �����." << endl;
        }
    }
}

// ���� ��� ������ � ������������ �����������
void musicCollectionMenu() {
    // �������� ����������� ������������
    HashSet<std::string> music;
    music.Add("Song1");
    music.Add("Song2");
    music.Add("Song3");
    music.Add("Song4");
    music.Add("Song4");

    // ������� ��� ����������� ������������
    std::cout << "��� ����������� ������������: ";
    music.Print();
    std::cout << "\n";

    // ������ ������ ���������
    HashSet<std::string> meloman1;
    meloman1.Add("Song1");
    meloman1.Add("Song3");

    HashSet<std::string> meloman2;
    meloman2.Add("Song1");
    meloman2.Add("Song2");

    HashSet<std::string> meloman3;
    meloman3.Add("Song1");

    // ������� ������ ������ ���������
    std::cout << "������ �������� 1: ";
    meloman1.Print();
    std::cout << "\n";

    std::cout << "������ �������� 2: ";
    meloman2.Print();
    std::cout << "\n";

    std::cout << "������ �������� 3: ";
    meloman3.Print();
    std::cout << "\n";

    // ����� �����, ������� �������� ���� ���������
    HashSet<std::string> commonLikes = meloman1.Intersect(meloman2).Intersect(meloman3);
    std::cout << "����������� ������������, ������� �������� ����: ";
    commonLikes.Print();
    std::cout << "\n";

    // �����, ������� �������� ��������� ���������
    HashSet<std::string> someLikes = meloman1.Union(meloman2).Union(meloman3);
    std::cout << "����������� ������������, ������� �������� ��������� ���������: ";
    someLikes.Print();
    std::cout << "\n";

    // �����, ������� �� �������� ������
    HashSet<std::string> notLiked = music.Except(someLikes);
    std::cout << "����������� ������������, ������� �� �������� ������: ";
    notLiked.Print();
    std::cout << "\n";
}

// ������� ��� �������������� ����� � �������
void PrintVowelsAsCharacters(const UniqueList<wchar_t>& vowels_list) {
    // ���������� ����� Print ��� ������ ���������
    vowels_list.Print();
}

// ������� ��� ��������� ������
void ProcessText(const wstring& text) {
    UniqueList<wchar_t> unique_vowels_list;
    UniqueList<wchar_t> repeated_vowels_list;
    wstring vowels = L"�Ũ����������������";

    map<wchar_t, int> vowels_count;

    // ������� ���������� ������ �������
    for (wchar_t c : text) {
        if (vowels.find(c) != wstring::npos) {
            vowels_count[c]++;
        }
    }

    // ������������� ������� � ���������� � ������������� ������
    for (const auto& pair : vowels_count) {
        if (pair.second == 1) {
            unique_vowels_list.Add(pair.first);
        }
        else if (pair.second > 1) {
            repeated_vowels_list.Add(pair.first);
        }
    }

    // ����� �����������
    wcout.imbue(locale("Russian"));

    wcout << L"���������� �����: " << text << endl;

    wcout << L"���������� ������� � ���������� �����: ";
    PrintVowelsAsCharacters(unique_vowels_list);

    wcout << L"������������� ������� � ���������� �����: ";
    PrintVowelsAsCharacters(repeated_vowels_list);
}
std::wstring stringToWString(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}
// ������� �������
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
    Olimpiad<string, pair<int, int>> participants;  // ����: ������� + ��� (string), ��������: ���� (�����, �����)
    string lastName, firstName;
    int grade, points;
    string fullName;
    ifstream inputFile("olymp.txt");

    while (true) {
        // ������� ����
        showMainMenu();
        mainChoice = getValidatedInput<int>("��� �����: ");

        switch (mainChoice) {
        case 1:
            singleLinkedListMenu();  // ���� ����������������� ������
            break;
        case 2:
            doublyLinkedListMenu();  // ���� ���������������� ������
            break;
        case 3:
            musicCollectionMenu();  // ���� ������ � ������������ ��������������
            break;
        case 4:
            file.imbue(locale(locale(), new codecvt_utf8<wchar_t>()));

            if (!file) {
                wcerr << L"������ �������� �����!" << endl;
                return 1;
            }

            // ������ ����������� �����

            while (getline(file, line)) {
                text += line + L" ";
            }
            file.close();

            // ��������� ������
            ProcessText(text);
            std::cout << "\n";
            setlocale(LC_ALL, "Russian");
            break;
        case 5: 
            cout << "���������� ���������: \n";
            
            
            

            
            if (!inputFile.is_open()) {
                cerr << "�� ������� ������� ���� olymp.txt" << endl;
                return 1;
            }

           
            // ��������� ����������
            
            setlocale(LC_ALL, "ru_RU.UTF-8");
            wcout.imbue(locale("ru_RU.UTF-8"));
            // ��������� ���������� ���������� �� �����
            inputFile >> N;

            // ������� ������ Olimpiad ��� �������� ����������
            

            // ������ ������ ���������� �� �����
            for (int i = 0; i < N; ++i) {
                
                inputFile >> lastName >> firstName >> grade >> points;
                fullName = lastName + " " + firstName;
                participants.addElement(fullName, { grade, points });
            }

            inputFile.close();  // ��������� ����

            cout << "������ ����������:" << endl;
            for (const auto& participant : participants.getAllElements()) {
                cout << participant.first << " �����: " << participant.second.first
                    << ", �����: " << participant.second.second << endl;
            }
            // ������ ������������ �����
            for (const auto& participant : participants.getAllElements()) {
                maxPoints = max(maxPoints, participant.second.second);
            }

            // ������ �����������
            for (const auto& participant : participants.getAllElements()) {
                if (participant.second.second > 200 && participant.second.second == maxPoints) {
                    winners.push_back(participant.first);
                }
            }

            // ������� ��� �����������
            if (winners.empty()) {
                // ���� ��� �����������
                cout << 0 << endl;
            }
            else if (winners.size() <= N * 0.2) {
                // ���� ����������� �� ������ 20%
                cout << winners.size() << endl;
            }
            else {
                // ���� ��������� �� ������
                for (const auto& participant : participants.getAllElements()) {
                    if (participant.second.second < maxPoints) {
                        secondMaxPoints = max(secondMaxPoints, participant.second.second);
                    }
                }

                // ��� ��������� � ������� ������������� �������
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
            cout << "���������� ���������. �� ��������!\n";
            return 0;  // ����� �� ���������
        default:
            cout << "������������ �����. ���������� �����.\n";
        }
    }

    return 0;
}




















































