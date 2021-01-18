package bankLogic

import util.*

class Transaction(val transactionType: TransactionType, val amount: Float
                  , val fromID: Int, val fromAccountType: AccountType, val fromAccountID: Int
                  , val toID: Int = 0, val toAccountType: AccountType = AccountType.DEPOSIT, val toAccountID: Int = 0)