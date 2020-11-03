interface Vehicle {
    val name: String
    val velocity: Float
    val movementType: RaceType
    fun start(distance: Float): Float
}

interface TerrestrialVehicle : Vehicle {
    override val name: String
    override val velocity: Float
    val movementTime: Float
    var restAmount: Float
    override val movementType: RaceType
        get() = RaceType.TERRAIN
    fun rest(): Float
    override fun start(distance: Float): Float {
        var tempDistance = 0f
        var tempTime = 0f
        while (tempDistance < distance) {
            if (tempDistance + movementTime * velocity < distance) {
                tempDistance += velocity * movementTime
                tempTime += movementTime
                rest()
                restAmount += 1
            } else {
                tempTime += (distance - tempDistance) / velocity
                break
            }
        }
        return tempTime
    }
}

interface AirVehicle : Vehicle {
    override val name: String
    override val velocity: Float
    override val movementType: RaceType
        get() = RaceType.AIR
    fun flight(distance: Float): Float
    override fun start(distance: Float): Float {
        return flight(distance)
    }
}