# 3DViewer v2.0 (Linux, Mac)

Разработана программа для визуализации каркасной модели в трехмерном пространстве.

- Программа разработана на языке C++. 
- Код программы находится в папке src.
- При написании кода придерживался Google Style.
- Сборка программы настроена с помощью Makefile со стандартным набором целей для GNU-программ: all, install, uninstall, clean, dvi, tests.
- Программа разработана в соответствии с принципами объектно-ориентированного программирования.
- Обеспечено полное покрытие unit-тестами модулей, связанных с загрузкой моделей и аффинными преобразованиями.
- В один момент времени только одна модель на экране.
- Программа предоставляет следующие возможности:
    - Загружать каркасную модель из файла формата obj (поддержка только списка вершин и поверхностей).
    - Перемещать модель на заданное расстояние относительно осей X, Y, Z.
    - Поворачивать модель на заданный угол относительно своих осей X, Y, Z.
    - Масштабировать модель на заданное значение.
- В программе реализован графический пользовательский интерфейс, на базе GUI-библиотеки Qt.
- Графический пользовательский интерфейс содержит:
    - Кнопку для выбора файла с моделью и поле для вывода его названия.
    - Зону визуализации каркасной модели.
    - Кнопку/кнопки и поля ввода для перемещения модели. 
    - Кнопку/кнопки и поля ввода для поворота модели. 
    - Кнопку/кнопки и поля ввода для масштабирования модели.  
    - Информацию о загруженной модели - название файла, кол-во вершин и ребер.
- Программа корректно обрабатывает и позволяет пользователю просматривать модели с деталями до 100, 1000, 10 000, 100 000, 1 000 000 вершин без зависания.
- Программа реализована с использованием паттерна MVC, Facade, Strategy, Singleton.
- Программа позволяет настраивать тип проекции (параллельная и центральная).
- Программа позволяет настраивать тип (сплошная, пунктирная), цвет и толщину ребер, способ отображения (отсутствует, круг, квадрат), цвет и размер вершин.
- Программа позволяет выбирать цвет фона.
- Настройки сохраняются между перезапусками программы.
- Программа позволяет сохранять полученные ("отрендеренные") изображения в файл в форматах bmp и jpeg.
