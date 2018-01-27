#include "settings.h"
#include "ui_settings.h"

Settings* Settings::instance = 0;

Settings::Settings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

Settings* Settings::getInstance() {
    if (instance == 0) {
        instance = new Settings;
    }
    return instance;
}

int Settings::getDelayTime()
{
    return delayTime;
}

void Settings::setDelayTime(int value)
{
    delayTime = value;
}
