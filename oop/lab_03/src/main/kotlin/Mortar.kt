class Mortar : AirVehicle {
    override val name: String
        get() = "Ведро дырявое"
    override val velocity: Double
        get() = 8.0

    override fun reduceDistance(distance: Double): Double {
        return distance - distance * 0.06
    }
}