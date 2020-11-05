class RaceEngine {
    private var _races: MutableList<Race> = mutableListOf()
    var tempRace: Int = -1
        set(raceNumber) {
            if (raceNumber > _races.size) {
                throw NoRacesFound()
            }
            field = raceNumber
        }

    fun createRace(raceType: RaceType, distance: Double) {
        _races.add(Race(raceType, distance))
        if (tempRace == -1) {
            tempRace = 0
        }
    }
    fun registerParticipant(participant: Vehicle) {
        _races[tempRace].registerParticipant(participant)
    }
    fun startRace(): Vehicle {
        if (tempRace == -1) {
            throw NoRacesFound()
        }
        return _races[tempRace].startRace()
    }
}