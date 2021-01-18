package bankExamples

import bankLogic.Bank
import bankLogic.Client
import bankLogic.Transaction

class Sber(
    override val ADDRESS: String
) : Bank {
    override val NAME = "Сберпанк"
    override val clients: MutableList<Client> = mutableListOf()
    override val transactions: MutableList<Transaction> = mutableListOf()
    override var debitPercent: Float = 0.01f
    override val depositPercent: (Float) -> Float = {
            it: Float -> when (it) {
            in 0f..1000f -> 0.05f
            in 10001f..10000f -> 0.10f
            else -> 0.30f
        }
    }
    override var creditCommission: Float = 1000f
    override var creditMinimum: Float = -10000f
}