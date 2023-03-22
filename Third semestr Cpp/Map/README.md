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

**Формат вывода**
Для каждого запроса, кроме `NEW_BUS`, выведите соответствующий ответ на него:

* На запрос `BUSES_FOR_STOP` `stop` выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке, в котором они создавались командами `NEW_BUS`. Если остановка `stop` не существует, выведите `No stop`.

* На запрос `STOPS_FOR_BUS` `bus` выведите описания остановок маршрута `bus` в отдельных строках в том порядке, в котором они были заданы в соответствующей команде `NEW_BUS`. Описание каждой остановки `stop` должно иметь вид `Stop stop: bus1 bus2 ...`, где `bus1 bus2 ...` - список автобусов, проезжающих через остановку `stop`, в порядке, в котором они создавались командами `NEW_BUS`, за исключением исходного маршрута `bus`. 
Если через остановку `stop` не проезжает ни один автобус, кроме `bus`, вместо списка автобусов для нее выведите no `interchange`. Если маршрут `bus` не существует, выведите `No bus`.  

* На запрос `ALL_BUSES` выведите описания всех автобусов в алфавитном порядке. Описание каждого маршрута `bus` должно иметь вид `Bus bus: stop1 stop2 ...`, где `stop1 stop2 ...` - список остановок автобуса `bus` в порядке, в котором они были заданы в соответствующей команде `NEW_BUS`. Если автобусы отсутствуют, выведите `No buses`.

**Ввод**
```cpp
    10
    ALL_BUSES
    BUSES_FOR_STOP Marushkino
    STOPS_FOR_BUS 32K
    NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
    NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo 
    2
    BUSES_FOR_STOP Vnukovo
    NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
    NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
    STOPS_FOR_BUS 272
    ALL_BUSES
```

**Вывод**
```cpp
    No buses
    No stop
    No bus
    32 32K
    Stop Vnukovo: 32 32K 950
    Stop Moskovsky: no interchange
    Stop Rumyantsevo: no interchange
    Stop Troparyovo: 950
    Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
    Bus 32: Tolstopaltsevo Marushkino Vnukovo
    Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
    Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
```

```cpp


```