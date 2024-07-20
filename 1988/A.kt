fun main() {
    val tc = readln().toInt()
    repeat(tc) {
        val (n, k) = readln().split(" ").map {it.toInt()}
        println((n-1+k-2)/(k-1))
    }
}