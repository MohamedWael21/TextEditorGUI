#include "notepad.h"
#include "./ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);


}

Notepad::~Notepad()
{
    delete ui;
}



void Notepad::on_actionNew_triggered()
{
    //delete old filename
    currentFile.clear();
    //make textEditor empty
    ui->textEdit->setText(QString());

}



void Notepad::on_actionOpen_triggered()
{
    // open fileExplorer for user to choose file and get name
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    // file object
    QFile file(fileName);

    // get file name without absolute path
    currentFile = QFileInfo(fileName).fileName();

    // try open file in read mode as text file
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        // show warning for user if can not open file
        QMessageBox::warning(this, "Warning", "Can not open " + currentFile + " " + file.errorString
                             ());
        return;
    }
    // show file name in notepad window
    setWindowTitle(currentFile);

    //make Text stream to read file content in textEdit
    QTextStream textStream(&file);

    // read all text from file in text variable
    QString text = textStream.readAll();

    // put text from file in text editor
    ui->textEdit->setText(text);

    // close file
    file.close();


}


void Notepad::on_actionSave_As_triggered()
{
    // get file name where user want to save file
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");

    // create file object
    QFile file(fileName);

    // try open file in write mode as text
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        // show message if file can not save
        QMessageBox::warning(this, "Warning", "Can not Save " + currentFile + " " + file.errorString() );
        return;
    }
    // update file variable
    currentFile = QFileInfo(fileName).fileName();
    // set window title
    setWindowTitle(currentFile);

    // create text stream
    QTextStream textStream(&file);


    // get all text from text edit
    QString text = ui->textEdit->toPlainText();

    // write all text to file
    textStream << text;

    // close file
    file.close();


}


void Notepad::on_actionExit_triggered()
{
    // close Notepad
    QApplication::quit();
}




void Notepad::on_actionCopy_triggered()
{
    // copy text to clipboard
    ui->textEdit->copy();
}




void Notepad::on_actionPaste_triggered()
{
    // paste text from clipboard
    ui->textEdit->paste();
}


void Notepad::on_actionCut_triggered()
{
    // cut text from text edit
    ui->textEdit->cut();
}



void Notepad::on_actionUndo_triggered()
{
    // undo the previous action
    ui->textEdit->undo();
}




void Notepad::on_actionRedo_triggered()
{
    //redo the previous action
    ui->textEdit->redo();
}



