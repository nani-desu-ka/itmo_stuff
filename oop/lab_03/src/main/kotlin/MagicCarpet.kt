class MagicCarpet : AirVehicle {
    override val name: String
        get() = "Настенный ковер"
    override val velocity: Float
        get() = 6f

    override fun flight(distance: Float): Float {
        return (distance * 0.3 - velocity).toFloat()
    }
}