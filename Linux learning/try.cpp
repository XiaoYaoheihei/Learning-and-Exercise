#include <iostream>
#include <cassert>
#include <leveldb/db.h>
#include <string.h>
using namespace std;
using namespace leveldb;

int main()
{
    leveldb::DB *db;
    leveldb::Options options;
    options.create_if_missing = true;
    
    leveldb::Status status = leveldb::DB::Open(options, "/home/xiaoyao/database", &db);
    assert(status.ok());

    std::cout << "Hello, world with leveldb in it!\n";

    //写入数据
    leveldb::Slice key("hello");
    string value("wo zhende fu le");
    status = db->Put(leveldb::WriteOptions(), key, value);
    if (status.ok()) {
        cout << "key: " << key.ToString() << "\n" << "value: " << value << "\n写入成功。" << endl;
    }

    //查找数据
    /*status = db->Get(leveldb::ReadOptions(), key, &value);
    if (status.ok()) {
        cout << "key: " << key.ToString() << " " << "value:" << value << "查找成功。" << endl;
    }*/

    //删除数据
    /*status = db->Delete(leveldb::WriteOptions(), key);
    if (status.ok()) {
        cout << "key: " << key.ToString() << " " << "删除成功。" << endl;
    }*/
    
    //迭代遍历数据库
    leveldb::Iterator* ita = db->NewIterator(leveldb::ReadOptions());
    //返回可迭代数据库的句柄
    ita->SeekToFirst();//定位到第一个对象为止
    int n = 0;
    while (ita->Valid()) {//获取迭代器当前是否正常，比如到了结束为止该函数就会返回false
        leveldb::Slice key = ita->key();// 获取迭代器当前定位对象的键，前提是Valid()返回true
        leveldb::Slice value = ita->value();// 获取迭代器当前定位对象的值，前提是Valid()返回true
        printf("%d: (%s -> %s)\n", ++n, key.ToString().c_str(), value.ToString().c_str());
        ita->Next();      // 定位到下一个对象，等同于stl容器迭代器的++  
    }

    delete ita;
    delete db;

    return 0;
}
/*
#include <cassert>
#include <iostream>
#include "./leveldb/db.h"

int main() {
    leveldb::DB *db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());

    std::cout << "leveldb open success!" << std::endl;

    std::string value;
    std::string key1 = "testkey1";
    leveldb::Status s = db->Get(leveldb::ReadOptions(), key1, &value);
    if (s.IsNotFound()) {
        std::cout << "can not found for key:" << key1 << std::endl;
        db->Put(leveldb::WriteOptions(), key1, "testvalue1");
    }

    s = db->Get(leveldb::ReadOptions(), key1, &value);
    if (s.ok()) {
        std::cout << "found key:" << key1 << ",value:" << value << std::endl;
    }
    s = db->Delete(leveldb::WriteOptions(), key1);
    if (s.ok()) {
        std::cout << "delete key success which key:" << key1 << std::endl;
    }
    s = db->Get(leveldb::ReadOptions(), key1, &value);
    if (s.IsNotFound()) {
        std::cout << "can not found after delete for key:" << key1 << std::endl;
    }

    delete db;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/


