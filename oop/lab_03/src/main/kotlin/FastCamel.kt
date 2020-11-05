class FastCamel : TerrestrialVehicle {
    override val name: String
        get() = "Верблюд на скоростях"
    override val velocity: Double
        get() = 40.0
    override val movementTime: Double
        get() = 10.0
    override var restAmount: Double = 0.0
        get() = field
        set(value) {
            field = value
        }
    override fun rest(): Double {
        return when (restAmount) {
            0.0 -> 5.0
            1.0 -> 6.5
            else -> 8.0
        }
    }
}