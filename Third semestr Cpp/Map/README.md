## map1_anogram.cpp
**Task**
**Вход:** `N` пар слов.
**Выход:** для каждой пары: `YES`, если эта пара-анаграмма, иначе `NO`.

Для каждой пары вызвать функцию, которая возвращает словарь:
ключ-символ, значение-число. Соответственно, число каждого символа.
Если словарь для первого слова == словарю для второго то это анаграмма.

```cpp
    #include <iostream>
    #include <vector>
    #include <string>
    #include <map>

    using namespace std;

    map<char, int> word_dictionary(const string &word){
        map<char, int> dictionary;
        for(const auto &letter : word){
            ++dictionary[letter];
        }
        return dictionary;
    }

    int main(){
        vector <string> answer;
        int N;
        cout << "Enter num of pairs of words:  ";
        cin >> N;

        cout << "Enter your pairs\n";
        string first_word, second_word;
        for(int i = 0; i < N; i++){
            cin >> first_word >> second_word;

            if (word_dictionary(first_word) == word_dictionary(second_word)){
                answer.push_back("YES");
            }
            else{
                answer.push_back("NO");
            }
        }

        for(auto x : answer){
            cout << x << "\n";
        }

        return 0;
    }
```

## map2_buses.cpp
**Task**
Реализуйте систему хранения автобусных маршрутов. Вам нужно
обрабатывать следующие запросы:
* **NEW_BUS** `bus` , `stop_count`,  `stop1 stop2 ...` - добавить маршрут автобуса с названием `bus` и `stop_count` остановками с названиями `stop1,
stop2, ...`
* **BUSES_FOR_STOP** `stop` - вывести названия всех маршрутов автобуса, проходящих через остановку `stop`.
* **STOPS_FOR_BUS** `bus` - вывести названия всех остановок маршрута `bus` со списком автобусов, на которые можно пересесть на каждой из остановок.
* **ALL_BUSES** - вывести список всех маршрутов с остановками.

**Формат ввода**
В первой строке ввода содержится количество запросов `Q`, затем в `Q`
строках следуют описания запросов.
Гарантируется, что все названия маршрутов и остановок состоят лишь
из латинских букв, цифр и знаков подчеркивания.
