В домашнем задании необходимо написать код программы, выполняющую определенную задачу в зависимости от варианта
Вариант #9
 
​Необходимо написать программу, реализующую функционал потокового текстового редактора с использованием ООП.
Необходимо реализовать поддержку операций:
cat <filename> - передает следующей операции сначала строки поданные на вход, затем строки из файла filename
echo <some string> - игнорирует строки поданные на вход, передает следующей операции строку <some string>
Выход одной операции подается на вход другой операции, операции разделяются символом '|'.
Если следующей операции нет, то строки выводятся в стандартный вывод (на экран).

Для реализации обработки строк утверждается следующий интерфейс IOperation.
Наследник IOperation обязан реализовать методы:
void ProcessLine(const std::string& str);
void HandleEndOfInput() = 0;
void SetNextOperation(<умный/сырой указатель/ссылка на IOperation>) = 0;

Каждая операция наследуется от интерфейса IOperation.
Программа должна парсить выражение, переданное в аргументах командной строки и строить конвеер из наследников IOperation.
Выражение можно парсить предельно строго ( например, недопускаются лишние пробелы или их отсутствие )
Для упрощения парсера аргументы отдельных операций не допускают пробелы ( echo 1 2 3 недопустим как и cat file name.txt )
Результат вычисления получается вызовом метода HandleEndOfInput у первой операции.
Пример (при вводе в терминале выражение с пробелами нужно обернуть, например, в одинарные кавычки)
./text_processor 'echo 1 | cat file_1.txt | cat file_2.txt'
1
<содержимое file_1.txt>
<содержимое file_2.txt>

Ваш вариант:
Добавьте к существующим операциям head <N> - которая выводит или передает дальше только первые <N> строк
