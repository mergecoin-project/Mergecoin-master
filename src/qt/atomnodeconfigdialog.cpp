#include "atomnodeconfigdialog.h"
#include "ui_atomnodeconfigdialog.h"

#include <QModelIndex>

AtomNodeConfigDialog::AtomNodeConfigDialog(QWidget *parent, QString nodeAddress, QString privkey) :
    QDialog(parent),
    ui(new Ui::AtomNodeConfigDialog)
{
    ui->setupUi(this);
    QString desc = "rpcallowip=127.0.0.1<br>rpcuser=REPLACEME<br>rpcpassword=REPLACEME<br>server=1<br>listen=1<br>port=REPLACEMEWITHYOURPORT<br>masternode=1<br>masternodeaddr=" + nodeAddress + "<br>masternodeprivkey=" + privkey + "<br>";
    ui->detailText->setHtml(desc);
}

AtomNodeConfigDialog::~AtomNodeConfigDialog()
{
    delete ui;
}
