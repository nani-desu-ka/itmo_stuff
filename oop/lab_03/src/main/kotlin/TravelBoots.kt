class TravelBoots : TerrestrialVehicle {
    override val name: String
        get() = "Тревела"
    override val velocity: Float
        get() = 100f
    override val movementTime: Float
        get() = 1f
    override var restAmount: Float = 0f
        get() = field
        set(value) {
            field = value
        }
    override fun rest(): Float {
        return restAmount
    }
}