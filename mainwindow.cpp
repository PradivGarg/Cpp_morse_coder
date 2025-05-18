#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui -> setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

QString MainWindow::textToMorse(const QString &text){
    const QMap<char, QString> morseCodeMap ={
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."},
        {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
        {'8', "---.."}, {'9', "----."},
        {' ', "/"} // Space as a separator
    };

    QString morseCode;
    for (const QChar &ch : text.toUpper()){
        if (morseCodeMap.contains(ch.toLatin1())){
            morseCode += morseCodeMap[ch.toLatin1()] + " ";
        }
        else{
            morseCode += "? ";
        }
    }

    return morseCode.trimmed();
}

void MainWindow::on_convertButton_clicked(){
    QString inputText = ui -> inputLineEdit -> text();
    QString morseCode = textToMorse(inputText);
    ui -> outputTextEdit -> setPlainText(morseCode);
}
