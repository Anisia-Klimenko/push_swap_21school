# push_swap_21school

Сортировка массива с помощью 2 стеков и набора инструкций за минимальное число шагов.

## Инструкции

sa : swap a - меняет местами первые 2 элемента в стеке а (ничего не делает, если в стеке меньше 2 элементов)

sb : swap b - аналогично для стека b

ss : sa и sb одновременно

pa : push a - перекладывает первый элемент в стеке b в стек a (ничего не делает, если b пустой)

pb : push b - аналогично для стека b

ra : rotate a - первый элемент стека a становится последним

rb : rotate b - аналогично для стека b

rr : ra и rb одновременно

rra : reverse rotate a - последний элемент стека a становится первым

rrb : reverse rotate b - аналогично для стека b

rrr : rra и rrb одновременно

## Описание и сборка

```make``` - компиляция библиотеки libft и сборка программы

```make clean``` - удаление объектных файлов

```make fclean``` - удаление всех скомпелированных файлов

```./push_swap 1 5 2 ... 10``` или ```./push_swap "1 5 2 ... 10"``` - запуск программы, аргументы передаются списком, разделенные пробелами

В качестве аргументов можно передать целые различные (не дублирующиеся) числа в диапозоне ```int``` (от -2147483648 до 2147483647). Иначе программа выведет
сообщение об ошибке.
