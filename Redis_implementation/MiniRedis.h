//
// Created by Henry    on 2026/6/15.
//

#ifndef CPP_SYSTEM_LAB_MINIREDIS_H
#define CPP_SYSTEM_LAB_MINIREDIS_H

#include <deque>
#include <string>
#include <unordered_map>
#include <deque>



enum RedisType {
    STRING,
    LIST,
    HASH
};

struct RedisObject {
    RedisType type;

    std::string stringValue;
    std::deque<std::string> listValue;
    std::unordered_map<std::string, std::string> hashValue;
};

class MiniRedis {
private:
    std::unordered_map<std::string, RedisObject> db;

public:
    void set(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    std::string type(const std::string& key);
    bool exists(const std::string& key);

    void lpush(const std::string& key, const std::string& value);
    void rpush(const std::string& key, const std::string& value);
    std::string lpop(const std::string& key);
    std::string rpop(const std::string& key);

    void hset(const std::string& key, const std::string& field, const std::string& value);
    std::string hget(const std::string& key, const std::string& field);
};


#endif //CPP_SYSTEM_LAB_MINIREDIS_H