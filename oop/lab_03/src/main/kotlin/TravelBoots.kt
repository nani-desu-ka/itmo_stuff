class TravelBoots : TerrestrialVehicle {
    override val name: String
        get() = "Тревела"
    override val velocity: Double
        get() = 6.0
    override val movementTime: Double
        get() = 60.0
    override var restAmount: Double = 0.0
        get() = field
        set(value) {
            field = value
        }
    override fun rest(): Double {
        return when (restAmount) {
            0.0 -> 10.0
            else -> 5.0
        }
    }
}