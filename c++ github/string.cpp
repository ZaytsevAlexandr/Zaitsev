    #include <iostream>
    #include <cstring>

    using namespace std;

    struct Vector
    {
        char* data;
        int _size; // current size
        int capacity; // maximum number of available elements

        Vector(int start_size = 100){ // Create a vector (construct)
            data = new char[start_size];
            capacity = start_size;
            _size = 0;
            // cout << "New vector has been created!" << '\n'; // test
        }

        void push(char element){ // Add an element to the end
            if (_size == capacity){
                capacity = (capacity ? capacity * 2 : 1); // if (capacity != 0) then? (capacity * 2) else: 1
                char* new_data = new char[capacity];
                for (int i = 0; i < _size; i++)
                    new_data[i] = data[i];
                delete[] data;
                data = new_data;
            }
            data[_size++] = element;
        }

        void throw_vector(){ // Print out an array
            for (int i = 0; i < _size; i++)
                cout << data[i] << ' ';
            cout << '\n';
        }

        char last_word(){
            char LastWord[10];
            int CurrentNumberOfLetters = 0;

            for (int j = _size - 1;;j--){
                int i = 0;
                if (int(data[j]) != 32){
                    CurrentNumberOfLetters++;
                    LastWord[10 - i++] = data[j];
                }
                else break;
            }

            if (CurrentNumberOfLetters != 10){
                for (int i = 0; i < 10; i++){
                    int j = 0;

                    LastWord[j] = LastWord[10 - CurrentNumberOfLetters + j];
                    j++;
                }

                for (int i = CurrentNumberOfLetters; i < 10; i++)
                    LastWord[i] = '\0';
            }

            return *LastWord;
        }

        void task(){
            char words[30][10];
            int CurrentSymbol = 0;

            int NumberOfWords = 0;
            for (int Word = 0; Word < 30; Word++){
                if (data[CurrentSymbol] != 32){
                    for (int Letter = 0;; Letter++){
                        words[Word][Letter] = data[CurrentSymbol];
                        if (int(data[++CurrentSymbol]) == 32)
                            break;
                    }

                    NumberOfWords++;
                }

                else{
                    CurrentSymbol++;
                    continue;
                }
            }
            for (int i = 0; i < NumberOfWords; i++){
                if (strcmp(words[i], last_word())){

                }
            }
        }
    };




    int main(){
        Vector str;

        for (;;){ // enter the string
            char symbol;
            cin >> symbol;
            str.push(symbol);

            if (symbol == '.')
                break;
        }
    }
