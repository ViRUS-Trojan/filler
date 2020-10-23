# filler
Филлер-это проект школы 21. Целью данного проекта является создание бота для игры-головоломки map-filler.

Алгоритм.

На каждом ходу игры бот должен разместить фигуру, которая будет предоставлена виртуальной машиной.

Чтобы определить место, где должен быть помещен кусок, мой бот создает тепловую карту.

Это карта, где каждая из свободных ячеек на карте представлена числом. Это число-расстояние между текущей ячейкой и ближайшей вражеской ячейкой.

Расстояние рассчитывается с помощью Манхэттенского расстояния:

Например, координаты текущей ячейки — A (i, j). Координаты вражеской ячейки — B (x, y).

Формула так проста:

расстояние = |i - x| + |j - y|

После расчета тепловой карты бот пытается поместить фигуру на каждую позицию карты. Но правила игры имеют одно ограничение — фигура должна перекрывать одну из ранее размещенных ячеек.

Для возможных мест, куда нужно положить фигуру, будет рассчитан балл — сумма чисел на каждой позиции.

Место с наименьшим счетом будет использоваться для размещения фигуры.

Поэтому созданный бот использует следующую стратегию — поставить фигуру как можно ближе к противнику. Потому что его цель-окружить врага, чтобы остановить его.