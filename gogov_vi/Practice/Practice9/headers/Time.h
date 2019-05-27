#ifndef _TIME_H_
#define _TIME_H_
#include <iostream>
#include <fstream>

class time
{
public:
    unsigned hour, min;
    time();
    time(const time&);
    time(unsigned, unsigned);
    ~time();

    time set_hour(unsigned);
    time set_min(unsigned);

    bool operator==(const time&) const;
    bool operator!=(const time&) const;
    bool operator>(const time&) const;
    bool operator>=(const time&) const;
    bool operator<(const time&) const;
    bool operator<=(const time&) const;

    time operator+(const time&);
    time operator-(const time&);
    const time& operator=(const time&);

    friend std::ostream& operator<<(std::ostream&, const time&);
};

class bad_time_hour : std::exception
{
    const std::string what_str = "Некорректный час.";
public:
    const char* what() const;
};

class bad_time_min : std::exception
{
    const std::string what_str = "Некорректные минуты.";
public:
    const char* what() const;
};

class bad_time : std::exception
{
    const std::string what_str = "Время начала больше времени конца.";
public:
    const char* what() const;
};

#endif 