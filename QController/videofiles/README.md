Videofiles
========

Videofiles помогает использовать Gstreamer в с, с++ коде через классы.
Он работает по модели Родитель-Дети, где создает один родительный объект на конвеер в коде, к родителю подключаются дети выполняющие различные функции независимые друг от друга.
На данный момент Родитель это источник данных, заканчивающийся объектом tee и предоставляющий интерфейс для подключения к этому объекту.
Родитель контролирует событяи на шине, количество кадров в секунду и состояние конвеера
Реализованные на данный момент Дети:
Блок видеозаписи- записывает видео в файл
Блок скриншотов - делает скрин при работающем конвеере
Блок показа - отображает данные на экране

Импорт в текущий проект
------------------------
Импортируется при помощи cmake и строк:
add_subdirectory( ${CMAKE_SOURCE_DIR}/videofiles )
include_directories( ${CMAKE_SOURCE_DIR})
target_link_libraries (${PROJECT_NAME} PRIVATE VideoFiles)

Features
--------

- Позволяет расширять функционал конвеера достаточно просто, без потери модульности
- В дальнейшем буду доработаны до синглтонов и будет использоваться проверка на аппаратные возможности

Пример использования
-------------

VideoApp* mainApp = new VideoApp();
VideoRecord* Recorder = new VideoRecord(mainApp);
VideoSnapshot* VideoSnap = new VideoSnapshot(mainApp);
VideoShow* VideoSink = new VideoShow(mainApp);

Contribute
----------

- Issue Tracker: 192.168.0.12/valeev_bm/videofiles/issues
- Source Code: 192.168.0.12/valeev_bm/videofiles
Support
-------

If you are having issues, please let us know.
We have a mailing list located at: vbm@eleps.ru