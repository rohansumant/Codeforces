fun main() {
    val tc = readln().toInt()
    repeat (tc) {
        val n = readln().toLong()
        val ls = mutableListOf<Long>(n)
        n.toString(2).reversed().forEachIndexed {
            i, e ->
            if (e == '1') {
                val x = n xor (1L shl i)
                if (x > 0L) ls += x
            }
        }
        println("${ls.size}")
        println(ls.reversed().joinToString(" "))
    }
}