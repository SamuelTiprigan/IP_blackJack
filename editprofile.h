#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QDialog>
#include <QtCore/QCoreApplication>
#include"stdio.h"
#include"stdlib.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>

#include <fstream>
#include "QMessageBox"


namespace Ui {
class EditProfile;
}

class EditProfile : public QDialog
{
    Q_OBJECT

public:
    explicit EditProfile(QWidget *parent = 0);
    ~EditProfile();

private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_searchEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::EditProfile *ui;

};

#endif // EDITPROFILE_H
