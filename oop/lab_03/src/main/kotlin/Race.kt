enum class RaceType {
    AIR,
    TERRAIN,
    MIXED,
}


class Race(raceType: RaceType, distance: Float) {
    private var _members: MutableList<Vehicle> = mutableListOf()
    private val _raceType = raceType
    private val _distance = distance
    fun startRace(): Vehicle {
        if (_members.size == 0) throw NoParticipantsFound()
        var minTime = -1f
        lateinit var winner: Vehicle
        for (member in _members) {
            val tempTime = member.start(_distance)
            if (minTime == -1f || tempTime < minTime) {
                minTime = tempTime
                winner = member
            }
        }
        return winner
    }
    fun registerParticipant(participant: Vehicle) {
        if (_raceType != RaceType.MIXED) {
            if (participant.movementType == _raceType) {
                _members.add(participant)
                return
            }
            throw IncorrectRaceType(participant.movementType, _raceType)
        }
        _members.add(participant)
    }
}