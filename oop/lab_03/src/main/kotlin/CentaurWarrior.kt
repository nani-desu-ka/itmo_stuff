class CentaurWarrunner : TerrestrialVehicle {
    override val name: String
        get() = "Кентавр"
    override val velocity: Double
        get() = 15.0
    override val movementTime: Double
        get() = 8.0
    override var restAmount: Double = 0.0
    override fun rest(): Double {
        return 2.0
    }
}