#ifndef ADDEDITATOMNODE_H
#define ADDEDITATOMNODE_H

#include <QDialog>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

namespace Ui {
class AddEditAtomNode;
}


class AddEditAtomNode : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditAtomNode(QWidget *parent = 0);
    ~AddEditAtomNode();

protected:

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
    void on_AddEditAddressPasteButton_clicked();
    void on_AddEditPrivkeyPasteButton_clicked();
    void on_AddEditTxhashPasteButton_clicked();

signals:

private:
    Ui::AddEditAtomNode *ui;
};

#endif // ADDEDITATOMNODE_H
