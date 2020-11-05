class Camel : TerrestrialVehicle {
    override val name: String
        get() = "Ленивый верблюд"
    override val velocity: Double
        get() = 10.0
    override val movementTime: Double
        get() = 30.0
    override var restAmount: Double = 0.0
        get() = field
        set(value) {
            field = value
        }
    override fun rest(): Double {
        return if (restAmount == 0.0) 5.0
        else 8.0
    }
}