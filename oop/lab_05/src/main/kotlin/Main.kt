import bankExamples.*
import bankLogic.BankManager
import util.AccountType

fun main() {
    BankManager.add(Sber("Уличная улица, д.1")).add(Sber("Домашняя улица, д.1"))
        .add(Tinkon("Гостевая улица, д.1"))
    BankManager.findBank(1)
        .newClient("Биба", "Боба", "Ъ проспект, д.1/2", "123413465")
        .createAccount(0, AccountType.DEBIT, 1000f)
        .createAccount(0, AccountType.DEPOSIT, 1005f, 40)
        .createAccount(0, AccountType.CREDIT, 1000f)
        .withdrawMoneyFrom(0, AccountType.DEPOSIT, 0, 1004f)
    BankManager.showEverything()
    println()
    BankManager.timeTravel(60).showEverything()
    println()
    BankManager.findBank(1).withdrawMoneyFrom(0, AccountType.CREDIT, 0, 1004f)
        .withdrawMoneyFrom(0, AccountType.DEPOSIT, 0, 1004f)
    BankManager.findBank(1).newClient("Боба", "Биба", "Ь проспект, д.2/1")
    BankManager.findBank(1).createAccount(1, AccountType.DEBIT, 500f)
    BankManager.showEverything()
    BankManager.findBank(1).transferFromTo(1, AccountType.DEBIT, 0, 0, AccountType.DEPOSIT, 0, 480f)
    println()
    BankManager.showEverything()
    BankManager.findBank(1).setPassportData(1, "12346597")
        .transferFromTo(1, AccountType.DEBIT, 0, 0, AccountType.DEPOSIT, 0, 480f)
    println()
    BankManager.showEverything()
}