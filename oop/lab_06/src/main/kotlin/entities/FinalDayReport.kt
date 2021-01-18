package entities

class FinalDayReport {
    val reports: MutableList<Report> = mutableListOf()
    fun add(report: Report) {
        reports.add(report)
    }
}