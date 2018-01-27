#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>

namespace Ui {
class Settings;
}

class Settings : public QMainWindow
{
    Q_OBJECT

public:
    static Settings* getInstance();
    int getDelayTime();
    void setDelayTime(int value);

private:
    static Settings* instance;
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    Ui::Settings *ui;

    int delayTime = 200;
};

#endif // SETTINGS_H
