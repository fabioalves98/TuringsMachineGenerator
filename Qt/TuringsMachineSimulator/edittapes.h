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
    explicit EditTapes(std::list<QChar> toEdit, QChar bSym, QWidget *parent = 0);
    void loadTape();
    std::list<QChar> getTape();
    QChar getBlanckSym();
    bool isReady();
    bool isEdited();
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
    std::list<QChar> tape;
    QChar blanckSym;
    bool edited = false;
    bool ready = false;
};

#endif // EDITTAPES_H
