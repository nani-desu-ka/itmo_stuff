package util

class UnableToWithdraw : Exception("Withdraw ERROR")
class IncorrectClientInfo : Exception("Name and surname are required")
class IncorrectAccountID(id: Int) : Exception("$id: account does not exist")
class IncorrectBankID(id: Int) : Exception("$id: bank does not exist")
class IncorrectClientID(id: Int) : Exception("$id: client does not exist")
class IncorrectTransactionID(id: Int) : Exception("$id: transaction does not exist")