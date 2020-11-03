class FastCamel : TerrestrialVehicle {
    override val name: String
        get() = "Верблюд на скоростях"
    override val velocity: Float
        get() = 5.5f
    override val movementTime: Float
        get() = 7f
    override var restAmount: Float = 0f
        get() = field
        set(value) {
            field = value
        }
    override fun rest(): Float {
        return restAmount * 6
    }
}