package bankLogic

import util.*
import java.lang.Exception

interface Bank {
    val NAME: String
    val ADDRESS: String
    val clients: MutableList<Client>
    val transactions: MutableList<Transaction>
    var debitPercent: Float
    val depositPercent: (Float) -> Float
    var creditCommission: Float
    var creditMinimum: Float

    fun withdrawMoneyFrom(id: Int, accountType: AccountType, accountID: Int, amount: Float): Bank {
        if (id >= clients.size) throw IncorrectClientID(id)
        try {
            clients[id].withdraw(amount, accountType, accountID)
        } catch (e: Exception) {
            println(e)
        }
        transactions.add(Transaction(TransactionType.WITHDRAW, amount, id, accountType, accountID))
        return this
    }
    fun depositMoney(id: Int, accountType: AccountType, accountID: Int, amount: Float): Bank {
        if (id >= clients.size) throw IncorrectClientID(id)
        try {
            clients[id].deposit(amount, accountType, accountID)
        } catch (e: Exception) {
            println(e)
        }
        transactions.add(Transaction(TransactionType.DEPOSIT, amount, id, accountType, accountID))
        return this
    }
    fun transferFromTo(fromID: Int, fromAccountType: AccountType, fromAccountID: Int
                       , toID: Int, toAccountType: AccountType, toAccountID: Int
                       , amount: Float): Bank {
        if (fromID >= clients.size) throw IncorrectClientID(fromID)
        if (toID >= clients.size) throw IncorrectClientID(toID)
        withdrawMoneyFrom(fromID, fromAccountType, fromAccountID, amount)
        depositMoney(toID, toAccountType, toAccountID, amount)
        transactions.add(Transaction(TransactionType.TRANSFER, amount
            , fromID, fromAccountType, fromAccountID
            , toID, toAccountType, toAccountID))
        return this
    }
    fun newClient(name: String, surname: String, address: String = "", passportData: String = ""): Bank {
        if (name == "" || surname == "") throw IncorrectClientInfo()
        clients.add(Client(clients.size, name, surname, address, passportData))
        return this
    }
    fun createAccount(id: Int, account: AccountType, firstDeposit: Float, depositTime: Int = 0): Bank {
        if (id >= clients.size) throw IncorrectClientID(id)
        when (account) {
            AccountType.DEBIT, AccountType.CREDIT -> clients[id].createAccount(account, firstDeposit)
            AccountType.DEPOSIT -> {
                clients[id].setDepositTime(clients[id].createAccount(account, firstDeposit), depositTime)
            }
        }
        return this
    }
    fun cancelTransaction(transactionID: Int): Bank {
        if (transactionID >= transactions.size) throw IncorrectTransactionID(transactionID)
        when (transactions[transactionID].transactionType) {
            TransactionType.DEPOSIT -> {
                try {
                    clients[transactions[transactionID].fromID].withdraw(
                        transactions[transactionID].amount,
                        transactions[transactionID].fromAccountType,
                        transactions[transactionID].fromAccountID
                    )
                } catch (e: Exception) {
                    println(e)
                }
            }
            TransactionType.WITHDRAW -> {
                try {
                    clients[transactions[transactionID].fromID].deposit(
                        transactions[transactionID].amount,
                        transactions[transactionID].fromAccountType,
                        transactions[transactionID].fromAccountID
                    )
                } catch (e: Exception) {
                    println(e)
                }
            }
            TransactionType.TRANSFER -> {
                try {
                    clients[transactions[transactionID].fromID].deposit(
                        transactions[transactionID].amount,
                        transactions[transactionID].fromAccountType,
                        transactions[transactionID].fromAccountID
                    )
                    clients[transactions[transactionID].toID].withdraw(
                        transactions[transactionID].amount,
                        transactions[transactionID].toAccountType,
                        transactions[transactionID].toAccountID
                    )
                } catch (e: Exception) {
                    println(e)
                }
            }
        }
        transactions.removeAt(transactionID)
        return this
    }
    fun timeTravel(dayAmount: Int): Bank {
        for (day in 0 until dayAmount) {
            for (client in clients) {
                client.dailyUpdate(debitPercent, creditCommission, creditMinimum, depositPercent)
            }
        }
        return this
    }
    fun setAddress(clientID: Int, newAddress: String): Bank {
        clients[clientID].setAddress(newAddress)
        return this
    }
    fun setPassportData(clientID: Int, newPassportData: String): Bank {
        clients[clientID].setPassportData(newPassportData)
        return this
    }
}