#ifndef ATOMNODECONFIGDIALOG_H
#define ATOMNODECONFIGDIALOG_H

#include <QDialog>

namespace Ui {
    class AtomNodeConfigDialog;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog showing transaction details. */
class AtomNodeConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AtomNodeConfigDialog(QWidget *parent = 0, QString nodeAddress = "123.456.789.123:15200", QString privkey="MASTERNODEPRIVKEY");
    ~AtomNodeConfigDialog();

private:
    Ui::AtomNodeConfigDialog *ui;
};

#endif // ATOMNODECONFIGDIALOG_H
