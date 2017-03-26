#ifndef MASTERNODEMANAGER_H
#define MASTERNODEMANAGER_H

#include "util.h"
#include "amount.h"
#include "sync.h"

#include <QWidget>
#include <QTimer>

namespace Ui {
    class MasternodeManager;

}
class ClientModel;
class WalletModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Masternode Manager page widget */
class MasternodeManager : public QWidget
{
    Q_OBJECT

public:
    explicit MasternodeManager(QWidget *parent = 0);
    ~MasternodeManager();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);


public slots:
    void updateNodeList();
    void updateAtomNode(QString alias, QString addr, QString privkey, QString txHash, QString txIndex, QString status);
    void on_UpdateButton_clicked();

signals:

private:
    QTimer *timer;
    Ui::MasternodeManager *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;
    CCriticalSection cs_atom;

private slots:
    void on_createButton_clicked();
    void on_startButton_clicked();
    void on_startAllButton_clicked();
    void on_tableWidget_2_itemSelectionChanged();
};
#endif // MASTERNODEMANAGER_H
