#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <ctime>
#include "List.cpp"
using namespace std;

void resetMapIds(map<int, List>& m)
{
    int id = 1;
    map<int, List> tempMap;
    for (auto& element : m)
    {
        tempMap.insert(make_pair(id, element.second));  // Tworzy nową mapę z poprawnymi identyfikatorami
        id++;
    }
    m = tempMap;   // Zastępuje oryginalną mapę poprawioną mapą
}

int main()
{
    map<int, List> map;   // Mapa przechowująca zadania, gdzie kluczem jest identyfikator

    char x = 'a';
    int id = 0;
    auto it = map.find(id);  // Iterator do mapy

    while (x != 'x')
    {
        // MENU
        system("cls");
        cout << "---ToDo List---\n" << endl;

        //wyswietlenie listy
        for (const auto& element : map)
        {
            int key = element.first;
            List value = element.second;
            cout << key << ". " << value.task() << endl;
        }

        //wyświetlenie odpowiedniego menu
        if (map.empty())
        {
            cout << "\nMozliwe akcje:\n\n1 - Dodaj pozycje\nx - Wyjscie z programu\n" << "\nAkcja: ";
        }
        else
        {
            cout << "\nMozliwe akcje:\n\n1 - Dodaj pozycje\n2 - Zmien status\n3 - Edytuj pozycje\n4 - Usun pozycje\n5 - Pokaz szczegoly\nx - Wyjscie z programu\n" << "\nAkcja: ";
        }

        x = getchar(); //popranie akcji od użytkownika

        //odpowiednie procedury dla podanej akcji
        switch (x)
        {
            //nowy element
        case '1':
        {
            cout << "\nNowy element listy:\n";
            string title;
            cin.ignore();
            getline(cin, title);
            map.insert(make_pair(map.size() + 1, List(title, "-")));
            break;
        }
        case '2':
        {
            //zmiana statusu
            cout << "\nPodaj id elementu:\n";
            cin >> id;
            it = map.find(id);

            if (it != map.end())
            {
                it->second.setStatus(!it->second.getStatus());
            }
            else
            {
                cout << "Nie ma elementu o podanym id.\n";
                system("pause");
            }
            break;
        }case '3':
        {
            //edycja elementu
            cout << "\nPodaj id elementu do edycji:\n";
            cin >> id;
            it = map.find(id);
            if (it != map.end())
            {
                string title;
                cout << "Podaj nowy tytul:\n";
                cin.ignore();
                getline(cin, title);
                it->second.setTitle(title);
            }
            else
            {
                cout << "Nie ma elementu o podanym id.\n";
                system("pause");
            }
            break;
        }
        case '4':
        {
            //usuniecie pozycji
            cout << "\nPodaj id elementu do usuniecia:\n";
            cin >> id;
            it = map.find(id);
            if (it != map.end())
            {
                map.erase(it);
                resetMapIds(map);
            }
            else
            {
                cout << "Nie ma elementu o podanym id.\n";
                system("pause");
            }
            break;
        }
        case '5':
        {
            //pokazanie szczegolow
            cout << "\nPodaj id elementu:\n";
            cin >> id;
            it = map.find(id);
            char a = 'a';

            while (a != 'x')
            {
                if (it != map.end())
                {
                    system("cls");
                    cout << "---ToDo List---\n" << endl;
                    cout << "Tytul zadania: " << it->second.getTitle() << endl;
                    cout << "Status: " << (it->second.getStatus() ? "Done" : "To Do") << endl;
                    cout << "Notatka: " << it->second.getNote() << endl;
                    cout << "Data: " << it->second.getDate() << endl;
                }
                else
                {
                    cout << "Nie ma elementu o podanym id.\n";
                }
                cout << "\nMozliwe akcje:\n\n";
                if (it->second.getNote() == "-")
                    cout << "1 - Dodaj notatke";
                else
                    cout << "1 - Edytuj notatke";

                cout << "\n2 - Wroc do menu\nx - Wyjscie z programu\n\nAkcja: ";
                a = getchar();
                if (a == '1')
                {
                    if (it->second.getNote() == "-")
                        cout << "\nDodaj notatke:\n";
                    else
                        cout << "\nEdytuj notatke:\n";
                    string note;
                    cin.ignore();
                    getline(cin, note);
                    it->second.setNote(note);
                }
                else if (a == '2')
                {
                    break;
                }
                else if (a == 'x')
                {
                    x = 'x';
                }
                else
                {
                    cout << "\n\nAkcja nie istnieje";
                }
            }
            break;
        }
        }
    }
}