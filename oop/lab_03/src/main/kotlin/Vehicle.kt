interface Vehicle {
    val name: String
    val velocity: Double
    val movementType: RaceType
    fun start(distance: Double): Double
}

interface TerrestrialVehicle : Vehicle {
    override val name: String
    override val velocity: Double
    val movementTime: Double
    var restAmount: Double
    override val movementType: RaceType
        get() = RaceType.TERRAIN
    fun rest(): Double
    override fun start(distance: Double): Double {
        var tempDistance = 0.0
        var tempTime = 0.0
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
    override val velocity: Double
    override val movementType: RaceType
        get() = RaceType.AIR
    fun reduceDistance(distance: Double): Double
    override fun start(distance: Double): Double {
        return reduceDistance(distance) / velocity
    }
}