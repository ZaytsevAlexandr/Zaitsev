// Дана строка, содержащая от 1 до 30 слов, в каждом из которых от 1 до 10 латинских букв и/или цифр;
// между соседними словами - не менее одного пробела, за последним словом - точка.
// Напечатать все слова, отличные от последнего слова, предварительно преобразовав
// каждое по правилу: оставить в слове только первое вхождение каждой буквы.


    #include <iostream>
    #include <cstring>

    using namespace std;

    string string_push(){
        cout << "You must use only uppercase and lowercase Latin letters and numbers, and you must put the dot in the end of your string!" << endl;
        string start_str;
        while (true) {
            getline(cin, start_str);
            bool valid = true;
            for (char c : start_str) {
                if (!isalnum(c) && c != ' ' && c != '.') {
                    valid = false;
                    break;
                }
            }
            if (valid && start_str.back() == '.') {
                break;
            } else {
                cout << "Please, try again" << endl;
            }
        }
        return start_str;
    }

    void string_split(string str){
        string words[30];
        int index_LastWord = 0;

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~Разделение слов~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

        char* char_str = new char[str.length() + 1];
        strcpy(char_str, str.c_str());

        char* pch = strtok (char_str, " ."); // во втором параметре указаны разделители (пробел, точка)
        for (int i = 0; pch != nullptr; i++){
            words[i] = pch; // сохраняем слово
            index_LastWord = i;

            pch = strtok (nullptr, " .");
        }

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

        delete [] char_str;

        for (int i = 0; i < index_LastWord; i++){ // перебор слов
            if (words[i] == words[index_LastWord]){ // проверка на совпадение со последним словом
                continue;
            }

            string new_word = ""; // новое слово
            bool already_used_small[26] = {false}; // массив для отслеживания уже использованных маленьких букв

            for (int j = 0; j < words[i].length(); j++){ // перебор букв в слове
                if (!already_used_small[tolower(words[i][j]) - 'a']) { // проверка на первое вхождение буквы,
                    new_word += words[i][j]; // добавляем символ в новое слово
                    already_used_small[tolower(words[i][j]) - 'a'] = true; // отмечаем использование буквы
                }
            }
            cout << new_word << endl;
        }
    }

    int main(){
        string my_string;
        my_string = string_push();

        cout << "Your string isn't split:" << endl;
        cout << my_string << endl;

        cout << "Your split string is written below:" << endl;
        string_split(my_string);
    }
