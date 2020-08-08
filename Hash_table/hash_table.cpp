#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <string>

struct TInfo {
    std::string phone;
    std::string name;
};


struct HashItem {
public:
    TInfo info;
public:
    bool empty = true;
public:
    bool visit = false;
public:
    explicit HashItem(TInfo info_i) {
        info = std::move(info_i);
    }
};

class MyHash {
    std::vector<HashItem> hash_table = {};
    TInfo info;
    int size_table;
    int size;
    int step;

public:
    explicit MyHash(int size_t) {
        size_table = size_t;
        info = TInfo();
        size = 0;
        step = 21;
        for (int i = 0; i < size_table; i++) {
            hash_table.emplace_back(HashItem(info));
        }
    }

private:
    int hash_function(std::string s) const{
        int result = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            result += (s[i]) * i;
            result %= size_table;
        }
        return result;
    }

public:
    int add_hash(std::string name_i, std::string phone_i) {
        int adr = -1;
        if (size < size_table) {
            adr = hash_function(phone_i);
            while (!hash_table[adr].empty) {
                adr = (adr + step) / size_table;
            }
            hash_table[adr].empty = false;
            hash_table[adr].visit = true;
            TInfo contact = TInfo();
            contact.phone = std::move(phone_i);
            contact.name = std::move(name_i);
            hash_table[adr].info = contact;
            size += 1;
        }
        return adr;
    }

private:
    void clear_visit() {
        int len = hash_table.size();
        for (int i = 0; i < len; i++) {
            hash_table[i].visit = false;
        }
    }

public:
    int find_hash(const std::string& phone_i) {
        int result = -1;
        bool ok;
        int count = 1;
        clear_visit();
        int i = hash_function(phone_i);
        ok = hash_table[i].info.phone == phone_i;
        while (!ok && !hash_table[i].visit) {
            count += 1;
            hash_table[i].visit = true;
            i = (i + step) / size_table;
            ok = hash_table[i].info.phone == phone_i;
        }
        if (ok) {
            result = i + 1;
        }
        return result;
    }

public:
    bool del_hash(const std::string& phone_i) {
        bool result = false;
        int i = 0;
        if (size != 0) {
            i = hash_function(phone_i);
            if (hash_table[i].info.phone == phone_i) {
                hash_table[i].empty = true;
                hash_table[i].info.name = " ";
                hash_table[i].info.phone = " ";
                result = true;
                size -= 1;
            } else {
                i = find_hash(phone_i);
                if (i == -1) {
                    hash_table[i].empty = true;
                    hash_table[i].info.name = " ";
                    hash_table[i].info.phone = " ";
                    result = true;
                    size -= 1;
                }
            }
        }
        return result;
    }

public:
    void print_hash_table() {
        std::cout << "N\t" << "NAME\t" << "PHONE" << std::endl;
        for (int i = 0; i < size_table; i++) {
            std::cout << i + 1 << "\t" << hash_table[i].info.name << "\t" << hash_table[i].info.phone << std::endl;
        }
    }
};

int main() {
    MyHash my_hash = MyHash(10);
    my_hash.add_hash("Dmitry", "978978345678");
    my_hash.add_hash("Fedor", "3565643534545");
    my_hash.add_hash("Ivan", "6723783456743");
    my_hash.print_hash_table();
    std::cout << "Found index: " << my_hash.find_hash("978978345678") << std::endl;
    std::cout << "Deletion success: " << my_hash.del_hash("3565643534545") << std::endl;
    my_hash.print_hash_table();
}



