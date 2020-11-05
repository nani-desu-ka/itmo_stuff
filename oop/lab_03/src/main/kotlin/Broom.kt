class Broom : AirVehicle {
    override val name: String
        get() = "Швабра"
    override val velocity: Double
        get() = 20.0

    override fun reduceDistance(distance: Double): Double {
        val percentage = kotlin.math.floor(distance / 1000) / 100
        if (percentage >= 1.0) return 0.0
        return distance - (distance * percentage)
    }
}