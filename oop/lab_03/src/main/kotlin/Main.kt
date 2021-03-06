fun main() {
    try {
        val RaceManager = RaceEngine()
        RaceManager.createRace(RaceType.MIXED, 1000.0)
        RaceManager.registerParticipant(MagicCarpet())
        RaceManager.registerParticipant(TravelBoots())
        RaceManager.registerParticipant(CentaurWarrunner())
        RaceManager.registerParticipant(FastCamel())
        RaceManager.registerParticipant(Broom())
        println(RaceManager.startRace().name)
        RaceManager.createRace(RaceType.TERRAIN, 100.0)
//        RaceManager.tempRace = 4
        RaceManager.tempRace = 1
//        RaceManager.registerParticipant(MagicCarpet())
        RaceManager.registerParticipant(CentaurWarrunner())
        println(RaceManager.startRace().name)
    } catch (e: Exception) {
        println(e)
    }
}