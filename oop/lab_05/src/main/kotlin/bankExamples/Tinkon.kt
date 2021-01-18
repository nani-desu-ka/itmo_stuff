package bankExamples

import bankLogic.Bank
import bankLogic.Client
import bankLogic.Transaction

class Tinkon(
    override val ADDRESS: String
) : Bank {
    override val NAME = "Тинькон"
    override val clients: MutableList<Client> = mutableListOf()
    override val transactions: MutableList<Transaction> = mutableListOf()
    override var debitPercent: Float = 0.04f
    override val depositPercent: (Float) -> Float = {
            it: Float -> when (it) {
        in 0f..50000f -> 0.08f
        in 500001f..100000f -> 0.10f
        else -> 0.35f
    }
    }
    override var creditCommission: Float = 500f
    override var creditMinimum: Float = -50000f
}