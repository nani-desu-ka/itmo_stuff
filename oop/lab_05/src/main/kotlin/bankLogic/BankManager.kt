package bankLogic

import util.IncorrectBankID

object BankManager {
    private val _banks: MutableList<Bank> = mutableListOf()
    fun add(newBank: Bank): BankManager {
        _banks.add(newBank)
        return this
    }
    fun findBank(bankID: Int): Bank {
        if (bankID > _banks.size) throw IncorrectBankID(bankID)
        return _banks[bankID]
    }
    fun findBankID(bankReference: Bank): Int {
        return _banks.indexOf(bankReference)
    }
    fun removeBank(bankReference: Bank): BankManager {
        _banks.remove(bankReference)
        return this
    }
    fun timeTravel(dayAmount: Int): BankManager {
        for (bank in _banks) {
            bank.timeTravel(dayAmount)
        }
        return this
    }
    fun showBanksList() {
        for (id in 0 until _banks.size) {
            println("$id: ${_banks[id].NAME} - ${_banks[id].ADDRESS}")
        }
    }
    fun showEverything() {
        for (id in 0 until _banks.size) {
            println("$id: ${_banks[id].NAME} - ${_banks[id].ADDRESS}")
            for (client in _banks[id].clients) {
                println("   ${client.surname} ${client.name}")
                println("       Дебетовый счет:")
                for (accountsNumber in 0 until client.debitAccount.size) {
                    println("           $accountsNumber: ${client.debitAccount[accountsNumber].first}₽")
                }
                println("       Депозит:")
                for (accountsNumber in 0 until client.deposit.size) {
                    println("           $accountsNumber: ${client.deposit[accountsNumber].first}₽")
                }
                println("       Кредитный счет:")
                for (accountsNumber in 0 until client.creditAccount.size) {
                    println("           $accountsNumber: ${client.creditAccount[accountsNumber].first}₽")
                }
            }
        }
    }
}