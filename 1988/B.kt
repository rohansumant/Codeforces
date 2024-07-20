fun main() {
    val tc = readln().toInt()
    repeat(tc) {
        val n = readln().toInt()
        val s = readln()
        var prev = 1
        var z = 0
        var o = 0
        for (i in 0..<n) {
            if (s[i] == '0' && prev != 0) {
                z++
            } else if (s[i] == '1') {
                o++
            }
            prev = s[i]-'0'
        }
        println("${if (o > z) "Yes" else "No"}")
    }
}