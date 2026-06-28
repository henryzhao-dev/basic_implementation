//
// Created by Henry    on 2026/6/25.
//

#ifndef CPP_SYSTEM_LAB_MYSDS_H
#define CPP_SYSTEM_LAB_MYSDS_H


class MySDS {
private:
    char* data;
    int length;
    int capacity;

    void resize(int newCapacity);
    int strlen(const char* str);

public:
    MySDS();
    MySDS(const char* str);
    ~MySDS();

    int size();
    const char* c_str();
    void append(const char* str);

};


#endif //CPP_SYSTEM_LAB_MYSDS_H