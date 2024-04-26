#include "atm.h"
#include "ui_atm.h"

ATM::ATM(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ATM)
{
    ui->setupUi(this);
    b=BankAccount(1287187, 75, 18292372, "Shweta Agarwal");
    ui->balanceBox->setValue(b.get_balance());
    connect(ui->withdrawButton, &QPushButton::clicked, this, &ATM::clickWithdraw);

    connect(ui->depositButton, &QPushButton::clicked, this, &ATM::clickDeposit);
}

ATM::~ATM()
{
    delete ui;
}
void ATM::clickWithdraw()
{
    int amount = ui->transactionBox->value();
    b.withdraw(amount);
    ui->balanceBox->setValue(b.get_balance());
}

void ATM::clickDeposit()
{
    int amount = ui->transactionBox->value();
    b.deposit(amount);
    ui->balanceBox->setValue(b.get_balance());
}
