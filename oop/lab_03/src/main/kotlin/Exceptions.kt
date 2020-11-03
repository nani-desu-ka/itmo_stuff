class IncorrectRaceType(vehicleType: RaceType, raceType: RaceType) : Exception("$vehicleType does not match $raceType")
class NoRacesFound : Exception("Wrong race selected")
class NoParticipantsFound : Exception("Race without participants")