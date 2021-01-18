package bankLogic

import util.*
class Client(val ID: Int,
             var name: String, var surname: String,
             var address: String,var passportData: String) {
    var debitAccount: MutableList<Pair<Float, Status>> = mutableListOf()
    var deposit: MutableList<Triple<Float, Status, Int>> = mutableListOf()
    var creditAccount: MutableList<Pair<Float, Status>> = mutableListOf()
    var creditInfo: Float = 0f
    private var debitVault: MutableList<Pair<Float, Int>> = mutableListOf()
    private var depositVault: MutableList<Triple<Float, Float, Int>> = mutableListOf()

    private var _accountStatus: Status = Status.INACTIVE

    fun dailyUpdate(debitPercent: Float, creditCommission: Float, creditMin: Float, depositPercent: (Float) -> Float) {
        for (id in 0 until deposit.size) {
            if (deposit[id].second == Status.ACTIVE) {
                depositVault[id] = Triple(depositVault[id].first,
                    depositVault[id].second + depositPercent(depositVault[id].first),
                    depositVault[id].third + 1)
                if (depositVault[id].third == 30) {
                    deposit[id] = Triple(deposit[id].first + depositVault[id].first, deposit[id].second, deposit[id].third)
                    depositVault[id] = Triple(depositVault[id].first,0f, 0)
                }
                if (deposit[id].third == 0) continue
                deposit[id] = Triple(deposit[id].first, deposit[id].second, deposit[id].third - 1)
            }
        }
        for (id in 0 until debitAccount.size) {
            if (debitAccount[id].second == Status.ACTIVE) {
                debitVault[id] = Pair(debitVault[id].first + debitAccount[id].first * debitPercent,
                    debitVault[id].second + 1)
                if (debitVault[id].second == 30) {
                    debitAccount[id] = Pair(debitAccount[id].first + debitVault[id].first, debitAccount[id].second)
                    debitVault[id] = Pair(0f, 0)
                }
            }
        }
        creditInfo = creditMin
        for (id in 0 until creditAccount.size) {
            if (creditAccount[id].second == Status.ACTIVE) {
                if (creditAccount[id].first < 0) {
                    creditAccount[id] = Pair(creditAccount[id].first - creditCommission, creditAccount[id].second)
                }
                if (creditAccount[id].first < creditMin) {
                    creditAccount[id] = Pair(creditAccount[id].first, Status.INACTIVE)
                }
            }
        }
    }
    fun createAccount(account: AccountType, firstDeposit: Float): Int {
        statusUpdate()
        return when (account) {
            AccountType.DEBIT -> {
                debitAccount.add(Pair(firstDeposit, _accountStatus))
                debitVault.add(Pair(0f, 0))
                debitAccount.size - 1
            }
            AccountType.CREDIT -> {
                creditAccount.add(Pair(firstDeposit, _accountStatus))
                creditAccount.size - 1
            }
            AccountType.DEPOSIT -> {
                deposit.add(Triple(firstDeposit, Status.INACTIVE, 0))
                depositVault.add(Triple(firstDeposit, 0.0f, 0))
                deposit.size - 1
            }
        }
    }
    fun setDepositTime(accountID: Int, time: Int): Client {
        if (accountID >= deposit.size) throw IncorrectAccountID(accountID)
        deposit[accountID] = Triple(deposit[accountID].first, _accountStatus, time)
        return this
    }
    fun setAddress(newAddress: String): Client {
        address = newAddress
        statusUpdate()
        return this
    }
    fun setPassportData(newPassportData: String): Client {
        passportData = newPassportData
        statusUpdate()
        return this
    }
    fun withdraw(amount: Float, account: AccountType, accountID: Int): Client {
        when (account) {
            AccountType.DEBIT -> withdrawFromDebit(amount, accountID)
            AccountType.CREDIT -> withdrawFromCredit(amount, accountID)
            AccountType.DEPOSIT -> withdrawFromDeposit(amount, accountID)
        }
        return this
    }
    fun deposit(amount: Float, account: AccountType, accountID: Int): Client {
        when (account) {
            AccountType.DEBIT -> depositToDebit(amount, accountID)
            AccountType.CREDIT -> depositToCredit(amount, accountID)
            AccountType.DEPOSIT -> depositToDeposit(amount, accountID)
        }
        return this
    }

    private fun withdrawFromDebit(amount: Float, accountID: Int) {
        if (accountID >= debitAccount.size) throw IncorrectAccountID(accountID)
        if (debitAccount[accountID].first - amount >= 0 && debitAccount[accountID].second == Status.ACTIVE) {
            debitAccount[accountID] = Pair(debitAccount[accountID].first - amount, debitAccount[accountID].second)
        } else {
            throw UnableToWithdraw()
        }
    }
    private fun withdrawFromDeposit(amount: Float, accountID: Int) {
        if (accountID >= deposit.size) throw IncorrectAccountID(accountID)
        if (deposit[accountID].third == 0 && deposit[accountID].first - amount >= 0
            && deposit[accountID].second == Status.ACTIVE) {
            deposit[accountID] = Triple(deposit[accountID].first - amount, deposit[accountID].second,
                deposit[accountID].third)
        } else {
            throw UnableToWithdraw()
        }
    }
    private fun withdrawFromCredit(amount: Float, accountID: Int) {
        if (accountID >= creditAccount.size) throw IncorrectAccountID(accountID)
        if (creditAccount[accountID].first - amount >= creditInfo && creditAccount[accountID].second == Status.ACTIVE) {
            creditAccount[accountID] = Pair(creditAccount[accountID].first - amount, creditAccount[accountID].second)
        } else {
            throw UnableToWithdraw()
        }
    }

    private fun depositToDebit(amount: Float, accountID: Int) {
        if (accountID >= debitAccount.size) throw IncorrectAccountID(accountID)
        debitAccount[accountID] = Pair(debitAccount[accountID].first + amount, debitAccount[accountID].second)
    }
    private fun depositToDeposit(amount: Float, accountID: Int) {
        if (accountID >= deposit.size) throw IncorrectAccountID(accountID)
        deposit[accountID] = Triple(deposit[accountID].first + amount, deposit[accountID].second,
            deposit[accountID].third)
    }
    private fun depositToCredit(amount: Float, accountID: Int) {
        if (accountID >= creditAccount.size) throw IncorrectAccountID(accountID)
        creditAccount[accountID] = Pair(creditAccount[accountID].first + amount, creditAccount[accountID].second)
    }

    private fun statusUpdate() {
        _accountStatus = if (address != "" && passportData != "") Status.ACTIVE
        else Status.INACTIVE
        if (_accountStatus == Status.ACTIVE) {
            for (id in 0 until debitAccount.size) debitAccount[id] = Pair(debitAccount[id].first, _accountStatus)
            for (id in 0 until deposit.size) {
                deposit[id] = Triple(deposit[id].first, _accountStatus, deposit[id].third)
            }
            for (id in 0 until creditAccount.size) {
                if (creditAccount[id].first >= 0) {
                    creditAccount[id] = Pair(creditAccount[id].first, _accountStatus)
                }
            }
        }
    }

}