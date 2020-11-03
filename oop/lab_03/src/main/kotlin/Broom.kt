class Broom : AirVehicle {
    override val name: String
        get() = "Швабра"
    override val velocity: Float
        get() = 1f

    override fun flight(distance: Float): Float {
        return (distance * 0.2 - velocity * 2).toFloat()
    }
}