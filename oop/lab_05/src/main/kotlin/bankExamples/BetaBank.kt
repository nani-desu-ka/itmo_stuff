package bankExamples

import bankLogic.Bank
import bankLogic.Client
import bankLogic.Transaction

class BetaBank(
    override val ADDRESS: String
) : Bank {
    override val NAME = "Бетта Банк"
    override val clients: MutableList<Client> = mutableListOf()
    override val transactions: MutableList<Transaction> = mutableListOf()
    override var debitPercent: Float = 0.07f
    override val depositPercent: (Float) -> Float = {
            it: Float -> when (it) {
        in 0f..5000f -> 0.04f
        in 50001f..10000f -> 0.11f
        else -> 0.17f
    }
    }
    override var creditCommission: Float = 300f
    override var creditMinimum: Float = -7000f
}