class Mortar : AirVehicle {
    override val name: String
        get() = "Ведро дырявое"
    override val velocity: Float
        get() = 3f

    override fun flight(distance: Float): Float {
        return (distance * 0.3 - velocity * 0.3).toFloat()
    }
}