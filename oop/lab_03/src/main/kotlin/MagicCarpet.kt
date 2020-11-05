class MagicCarpet : AirVehicle {
    override val name: String
        get() = "Настенный ковер"
    override val velocity: Double
        get() = 10.0

    override fun reduceDistance(distance: Double): Double {
        return when {
            distance < 1000 -> distance
            distance < 5000 -> distance - distance * 0.03
            distance < 10000 -> distance - distance * 0.1
            else -> distance - distance * 0.05
        }
    }
}