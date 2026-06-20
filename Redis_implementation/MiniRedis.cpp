//
// Created by Henry    on 2026/6/15.
//

#include "MiniRedis.h"
#include <stdexcept>

void MiniRedis::set(const std::string& key, const std::string& value) {
    RedisObject obj;
    obj.type = STRING;
    obj.stringValue = value;

    db[key] = obj;
}

std::string MiniRedis::get(const std::string& key) {
    auto it = db.find(key);

    if (it == db.end()) {
        throw std::out_of_range("key not found");
    }

    const RedisObject& obj = it->second;

    if (obj.type != STRING) {
        throw std::runtime_error("wrong type");
    }

    return obj.stringValue;
}

bool MiniRedis::exists(const std::string &key) {
    return db.find(key) != db.end();
}

std::string MiniRedis::type(const std::string &key) {
    auto it = db.find(key);

    if (it == db.end()) {
        return "none";
    }

    const RedisObject& obj = it->second;

    if (obj.type == STRING) {
        return "string";
    }

    if (obj.type == LIST) {
        return "list";
    }

    if (obj.type == HASH) {
        return "hash";
    }

    return "unknown";
}

void MiniRedis::lpush(const std::string &key, const std::string &value) {
    auto it = db.find(key);

    if (it == db.end()) {
        RedisObject obj;
        obj.type = LIST;
        obj.listValue.push_front(value);
        db[key] = obj;
        return;
    }

    RedisObject& obj = it->second;

    if (obj.type != LIST) {
        throw std::runtime_error("wrong type");
    }

    obj.listValue.push_front(value);
}

void MiniRedis::rpush(const std::string &key, const std::string &value) {
    auto it = db.find(key);

    if (it == db.end()) {
        RedisObject obj;
        obj.type = LIST;
        obj.listValue.push_back(value);
        db[key] = obj;
        return;
    }

    RedisObject& obj = it->second;

    if (obj.type != LIST) {
        throw std::runtime_error("wrong type");
    }

    obj.listValue.push_back(value);
}

std::string MiniRedis::lpop(const std::string &key) {
    auto it = db.find(key);

    if (it == db.end()) {
        throw std::out_of_range("key not found");
    }

    RedisObject& obj = it->second;

    if (obj.type != LIST) {
        throw std::runtime_error("wrong type");
    }

    if (obj.listValue.empty()) {
        throw std::out_of_range("list is empty");
    }

    std::string value = obj.listValue.front();
    obj.listValue.pop_front();

    return value;
}

std::string MiniRedis::rpop(const std::string &key) {
    auto it = db.find(key);

    if (it == db.end()) {
        throw std::out_of_range("key not found");
    }

    RedisObject& obj = it->second;

    if (obj.type != LIST) {
        throw std::runtime_error("wrong type");
    }

    if (obj.listValue.empty()) {
        throw std::out_of_range("list is empty");
    }

    std::string value = obj.listValue.back();
    obj.listValue.pop_back();

    return value;
}

void MiniRedis::hset(const std::string &key, const std::string &field, const std::string &value) {
    auto it = db.find(key);

    if (it == db.end()) {
        RedisObject obj;
        obj.type = HASH;
        obj.hashValue[field] = value;
        db[key] = obj;
        return;
    }

    RedisObject& obj = it->second;

    if (obj.type != HASH) {
        throw std::runtime_error("wrong type");
    }

    obj.hashValue[field] = value;
}

std::string MiniRedis::hget(const std::string &key, const std::string &field) {
    auto it = db.find(key);

    if (it == db.end()) {
        throw std::out_of_range("key not found");
    }

    RedisObject& obj = it->second;

    if (obj.type != HASH) {
        throw std::runtime_error("wrong type");
    }

    auto fieldIt = obj.hashValue.find(field);

    if (fieldIt == obj.hashValue.end()) {
        throw std::out_of_range("field not found");
    }

    return fieldIt->second;
}

void MiniRedis::sadd(const std::string &key, const std::string &value) {
    auto it = db.find(key);

    if (it == db.end()) {
        RedisObject obj;
        obj.type = SET;
        obj.setValue.insert(value);
        db[key] = obj;
        return;
    }

    RedisObject& obj = it->second;

    if (obj.type != SET) {
        throw std::runtime_error("wrong type");
    }

    obj.setValue.insert(value);
}

bool MiniRedis::sismember(const std::string &key, const std::string &value) {
    auto it = db.find(key);

    if (it == db.end()) {
        return false;
    }

    RedisObject& obj = it->second;

    if (obj.type != SET) {
        throw std::runtime_error("wrong type");
    }

    return obj.setValue.find(value) != obj.setValue.end();
}











