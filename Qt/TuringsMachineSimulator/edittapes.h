#ifndef EDITTAPES_H
#define EDITTAPES_H

#include <QMainWindow>
#include "tape.h"

namespace Ui {
class EditTapes;
}

class EditTapes : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditTapes(Tape *toEdit, int tapePos, bool tapeEdited, QWidget *parent = 0);
    void loadTape();
    bool isReady();
    bool isEdited();
    void applyEdits();
    ~EditTapes();

private slots:
    void on_plusLeftBt_clicked();
    void on_minusLeftBt_clicked();
    void on_minusRightBt_clicked();
    void on_plusRightBt_clicked();
    void on_blanckSymLEdit_textChanged(const QString &arg1);
    void on_saveBt_clicked();

    void on_restoreBt_clicked();

private:
    void updateTape();
    Ui::EditTapes *ui;
    Tape *tape;
    std::list<QChar> tapeList;
    bool edited = false;
    bool ready = false;
};

#endif // EDITTAPES_H
