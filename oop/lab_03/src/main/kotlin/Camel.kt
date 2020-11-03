class Camel : TerrestrialVehicle {
    override val name: String
        get() = "Ленивый верблюд"
    override val velocity: Float
        get() = 1f
    override val movementTime: Float
        get() = 10f
    override var restAmount: Float = 0f
        get() = field
        set(value) {
            field = value
        }
    override fun rest(): Float {
        return restAmount * 5
    }
}