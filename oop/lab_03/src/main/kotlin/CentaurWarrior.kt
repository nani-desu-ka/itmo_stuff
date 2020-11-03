class CentaurWarrunner : TerrestrialVehicle {
    override val name: String
        get() = "Кентавр"
    override val velocity: Float
        get() = 20f
    override val movementTime: Float
        get() = 5f
    override var restAmount: Float = 0f
    override fun rest(): Float {
        return restAmount * 2
    }
}