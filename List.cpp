#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>

using namespace std;

class List
{
private:
    string ftitle;       // Tytu³ zadania
    string fnote;        // Notatka
    bool fstatus;        // Status zadania (true - zrobione, false - do zrobienia)
    string fdate;        // Data utworzenia zadania

public:
    List(string title, string note, bool status = false) : ftitle{ title }, fnote{ note }, fstatus{ status }
    {
        time_t now = time(0); // Pobranie aktualnego czasu
        tm current_time;
        localtime_s(&current_time, &now); // Konwersja czasu na lokalny czas
        char formatted_time[20];
        strftime(formatted_time, sizeof(formatted_time), "%d.%m.%Y - %H:%M", &current_time); // Sformatowanie czasu do odpowiedniej postaci
        fdate = formatted_time;  // Przypisanie sformatowanego czasu do fdate
    }

    string getTitle(void) const
    {
        return ftitle;   // Zwraca tytu³ zadania
    }

    string getNote(void) const
    {
        return fnote;   // Zwraca notatkê
    }

    bool getStatus(void) const
    {
        return fstatus;    // Zwraca status zadania
    }

    string getDate(void) const
    {
        return fdate;   // Zwraca datê utworzenia zadania
    }

    void setTitle(string title)
    {
        ftitle = title;    // Ustawia tytu³ zadania
    }

    void setNote(string note)
    {
        fnote = note;    // Ustawia notatkê
    }

    void setStatus(bool status)
    {
        fstatus = status;   // Ustawia status zadania
    }

    string task() const
    {
        string status = (getStatus() ? "Done" : "To Do");  // Ustala status zadania (Done lub To Do)
        return getTitle() + " - " + status;         // Zwraca tytu³ zadania wraz ze statusem
    }
};
