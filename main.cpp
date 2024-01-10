#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>

typedef std::set<std::string> Lang;

void printLang(Lang l) {
    for (auto word : l) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

void initLang(Lang &l, bool n) {
    std::string filename;
    short file_num;
    n ? filename = "lang2.txt" : filename = "lang1.txt";
    n ? file_num = 2 : file_num = 1;
    
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cout << "Ошибка открытия файла " << file_num << "." << std::endl;
        return;
    }
    
    std::string buff;
    int i = 0;
    while (std::getline(fin, buff)) {
        i++;
        if (l.size() >= 10000) {
            std::cout << "Превышен размер языка " << file_num << std::endl;
            return;
        }
        if (buff.length() > 100) {
            std::cout << "Длина цепочки не должна превышать 100 (язык " << file_num << ", строка " << i << ")" << std::endl;
            return;
        }
        l.insert(buff);
    }
    
    std::cout << "Язык " << file_num << std::endl;
    printLang(l);
}

Lang concatLangs(Lang l1, Lang l2) {
    Lang l1l2;

    for (auto word1 : l1) {
        for (auto word2 : l2) {
            l1l2.insert(word1 + word2);
        }
    }

    return l1l2;
}

int main() {
    Lang l1, l2;

    initLang(l1, 0);
    std::cout << std::endl;
    
    initLang(l2, 1);
    std::cout << std::endl;
    
    std::cout << "Конкатенированный язык:" << std::endl;
    printLang(concatLangs(l1, l2));
    
    std::cout << std::endl;
    
    return 0;
}
