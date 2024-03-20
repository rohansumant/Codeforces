fun main() {
  val tc = readln().toInt()
  repeat(tc) {
    val (n,k) = readln().split(' ').map{it.toInt()}
    val ls = readln().split(' ').map{it.toInt()}
    val fh = ls.take(n).groupingBy{it}.eachCount()
    val sh = ls.drop(n).groupingBy{it}.eachCount()

    // println("${fh} ${sh}")

    val afh = mutableListOf<Int>()
    val ash = mutableListOf<Int>()

    var it = fh.iterator()
    while (afh.size < 2*k && it.hasNext()) {
      val (key, value) = it.next()
      if (value == 2) {
        repeat(2) { afh += key }
      }
    }

    it = fh.iterator()
    while (afh.size < 2*k && it.hasNext()) {
      val (key, value) = it.next()
      if (value == 1) {
        afh += key
        ash += key
      }
    }
    require(afh.size == 2*k)

    it = sh.iterator()
    while (it.hasNext() && ash.size < 2*k) {
      val (key, value) = it.next()
      if (value == 2) {
        repeat(2) { ash += key }
      }
    }
    require(ash.size == 2*k)

    afh.forEach {
      print("$it ")
    }
    println()

    ash.forEach {
      print("$it ")
    }
    println()

  }
}

main()
